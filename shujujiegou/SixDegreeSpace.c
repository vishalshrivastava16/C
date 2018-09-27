#include <stdio.h>
#include <stdlib.h>

/* 六度空间 */

#define MaxN 10001
#define MaxM 33*10001

typedef  struct AdjVNode{
    int AdjV;/* 邻接点下标 */
    struct AdjVNode *Next;
}*PtrToAdjVNode;

typedef struct VNode{
    PtrToAdjVNode FirstEdge;
} AdjList[MaxN];

typedef struct GNode{
    int Nv;/* 顶点数 */
    int Ne;/* 边数 */
    AdjList G;/* 邻接表 */
}*LGraph;

typedef struct QNode{
    int Data[MaxN];
    int front,rear;
}*Queue;

LGraph CreateGraph( int VertexNum )
{
    int V;
    LGraph Graph = (LGraph)malloc(sizeof(struct GNode));
    Graph->Nv = VertexNum;
    Graph->Ne = 0;

    for(V=0;V<Graph->Nv;V++)
        Graph->G[V].FirstEdge = NULL;

    return Graph;
}

void InsertEdge(LGraph Graph, int V1, int V2)
{
    V1--;V2--;/* 编号0 ~ N-1 */
    Graph->Ne++;
    PtrToAdjVNode NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
    /*  V1->V2*/
    NewNode->AdjV = V2;
    NewNode->Next = Graph->G[V1].FirstEdge;
    Graph->G[V1].FirstEdge = NewNode;

    /* V2->V1 */
    NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
    NewNode->AdjV = V1;
    NewNode->Next = Graph->G[V2].FirstEdge;
    Graph->G[V2].FirstEdge = NewNode;   
}

void AddQ(Queue Q, int V)
{
    Q->Data[++Q->rear] = V;
}

int DeleteQ(Queue Q)
{
    return Q->Data[++Q->front];
}

int IsEmpty(Queue Q)
{
    return !(Q->front<Q->rear);
}

void BFS(LGraph Graph, int StartVertex)
{
    double Per=1.0;
    int i, cnt=0;
    int last = StartVertex;
    /* 广度优先搜索 */
    int Visited[MaxN];
    for(i=0;i<Graph->Nv;i++)
        Visited[i]=0;/* 未访问过 */
    Queue Q = (Queue)malloc(sizeof(struct QNode));
    Q->front = Q->rear = -1;

    Visited[StartVertex] = 1;
    Q->Data[++Q->rear] = StartVertex;

    int V, tail;
    PtrToAdjVNode Node;
    while(!IsEmpty(Q)){
        V = DeleteQ(Q);
        Node = Graph->G[V].FirstEdge;
        for(Node = Graph->G[V].FirstEdge; Node!=NULL; Node = Node->Next)
        {
            if(!Visited[Node->AdjV]){
                Visited[Node->AdjV] = 1;
                AddQ(Q, Node->AdjV);
                Per++;
                tail = Node->AdjV;
            }
        }
        if(V == last){
            cnt++;
            last = tail;
        }

        if(cnt == 6)
            break;
    }
    Per = Per*100/Graph->Nv;
    printf("%d: %.2lf%%\n",StartVertex+1,Per);
}

int main()
{
    int N, M;
    scanf("%d %d",&N,&M);
    LGraph Graph = CreateGraph(N);
    int V1,V2,i;
    for(i=0;i<M;i++){
        scanf("%d %d",&V1,&V2);
        InsertEdge(Graph, V1, V2);
    }

    for(i=0;i<N;i++)
        BFS(Graph, i);

    return 0;
}