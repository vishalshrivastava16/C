#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MaxVertexNum 10
typedef struct GNode{
    int Nv;
    int Ne;
    int G[MaxVertexNum][MaxVertexNum];
} *MGraph;

typedef struct ENode{
    int V1;
    int V2;
}   *Edge;

bool Visited[MaxVertexNum];

/* 初始化 */
MGraph CreateGraph( int Vertex)
{
    int i, j;
    MGraph Graph = (MGraph)malloc(sizeof(struct GNode));
    Graph->Nv = Vertex;
    Graph->Ne = 0;
    for(i=0;i<Vertex;i++)
        for(j=0;j<Vertex;j++)
            Graph->G[i][j] = 0;
    return Graph;
}

/* 插入 */
void InsertEdge( MGraph Graph, Edge E)
{
    Graph->Ne++;
    Graph->G[E->V1][E->V2] = 1;
    Graph->G[E->V2][E->V1] = 1;
}

void InitVisited(MGraph Graph)
{
    int i;
    for(i=0;i<Graph->Nv;i++)
        Visited[i] = false;
}
 
 bool IsEdge(MGraph Graph, int V, int W)
 {
     if(Graph->G[V][W])
        return true;
    else
        return false;
 }

/* 深度优先搜索 */
void DFS(MGraph Graph, int StartVertex)
{
    Visited[StartVertex] = true;
    printf("%d ",StartVertex);
    int i;
    /* V的每个邻接点i */
    for(i=0;i<Graph->Nv;i++){
        if(IsEdge(Graph, StartVertex, i)&&(Visited[i]==false))
            DFS(Graph, i);
    }
}

/* 队列 */
typedef struct QNode{
    int Data[MaxVertexNum];
    int front,rear;
}*Queue;

Queue CreateQ()
{
    Queue Q = (Queue)malloc(sizeof(struct QNode));
    Q->front = -1;
    Q->rear = -1;
    return Q;
}



void AddQ(Queue Q, int V)
{
    Q->Data[++Q->rear] = V;
}

int DeleteQ(Queue Q)
{
    return Q->Data[++Q->front];
}
bool IsEmpty(Queue Q)
{
    return Q->rear==Q->front;
}
/* 广度优先搜索 */
void BFS(MGraph Graph, int StartVertex)
{
    /* 使用队列，将结点入队出队，将相连点入队 */
    printf("%d ",StartVertex);
    Visited[StartVertex] = true;
    int V,W;
    Queue Q = CreateQ();
    AddQ(Q, StartVertex);

    
    while(!IsEmpty(Q)){
        V = DeleteQ(Q);
        for(W=0;W<Graph->Nv;W++)
        {
            if(!Visited[W]&&IsEdge(Graph,V,W)){
                printf("%d ",W);
                Visited[W] = true;
                AddQ(Q, W);
            }
        }
    }
}



int main()
{
    int NV, NE;
    int i;
    Edge E = (Edge)malloc(sizeof(struct ENode));
    scanf("%d %d",&NV, &NE);
    MGraph Graph = CreateGraph(NV);
    for(i=0;i<NE;i++){
        scanf("%d %d",&E->V1,&E->V2);
        InsertEdge(Graph, E);
    }
    InitVisited(Graph);
    for(i=0;i<NV;i++){
        if(Visited[i]==false){
            printf("{ ");
            DFS(Graph, i);
            printf("}");
            printf("\n");
        }
    }
    InitVisited(Graph);
    for(i=0;i<NV;i++){
        if(Visited[i]==false){
            printf("{ ");
            BFS(Graph, i);
            printf("}\n");
        }
    }
    system("pause");
    return 0;
}
