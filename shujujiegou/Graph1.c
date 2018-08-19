#include <stdio.h>
#include <stdlib.h>
#define MaxVertexMum 100    /* 最大顶点数100 */
#define INFINITY 65535  /* 双字节无符号整数最大值 */
typedef int Vertex; /* 顶点 */
typedef int WeightType;  /* 权 */
typedef char DataType;   /* 顶点存储的数据类型 */
typedef enum {false, true}bool;

/* 图的数组表示法 */

/* 边的定义 */
typedef struct ENode{
    Vertex V1, V2;
    WeightType Weight;
}* Edge;

/* 图的定义 */
typedef struct GNode{
    int Nv; /* 顶点数 */
    int Ne; /* 边数 */
    WeightType G[MaxVertexMum][MaxVertexMum];   /* 权重邻接矩阵 */
    DataType Data[MaxVertexMum];    /* 存在顶点的数据（非必需） */
}   *MGraph;

/* 创建图 */
MGraph CreateGraph( int VertexNum )
{
    /* 初始化一个有VertexNum个顶点，但没有边的图 */
    Vertex V, W;
    MGraph Graph;
    Graph = (MGraph)malloc(sizeof(struct GNode));
    Graph->Nv = VertexNum;
    Graph->Ne = 0;

    /* 初始化邻接矩阵为无穷大（不相连），从0 - VertexNum-1 */
    for(V=0; V<Graph->Nv; V++)
        for(W=0; W<Graph->Nv; W++)
            Graph->G[V][W] = INFINITY;

    return Graph;
}

void InsertEdge( MGraph Graph, Edge E)
{
    /* 无向图 */
    Graph->G[E->V1][E->V2] = E->Weight;
    Graph->G[E->V2][E->V1] = E->Weight;
}

MGraph BuildGraph()
{
    MGraph Graph;
    Edge E;
    Vertex V;
    int Nv, i;

    scanf("%d",&Nv);    /* 读入顶点个数 */
    Graph = CreateGraph( Nv );  /* 初始化 */
    scanf("%d",&(Graph->Ne));   /* 读入边的个数 */
    if(Graph->Ne){/* 如果有边 */
        E = (Edge)malloc(sizeof(struct ENode));
        /* 读入 起点 终点 权重 */
        for(i=0; i<Graph->Ne; i++){
            scanf("%d %d %d", &E->V1, &E->V2, &E->Weight);
            InsertEdge( Graph, E);
        }
    }
    /* 如果顶点有数据，读入数据 */
    for(i=0; i<Graph->Ne; i++)
        scanf("%c",&(Graph->Data[V]));

    return Graph;
}

/* BFS */
bool IsEdge(MGraph Graph, Vertex V, Vertex W)
{
    /* 检查<V,W>是否为一条边，即W是否为V的邻接点 */
    return Graph->G[V][W]<INFINITY ? true : false;
}


/* Visited[]为全局变量，已经初始化为false */
bool Visited[];

typedef struct{
    int Data[MaxVertexMum];
    int rear;//尾
    int front;//头
} Queue;

Queue *CreateQ()
{
    Queue *Q;
    Q->rear = -1;
    Q->front = -1;
    return Q;
}

int IsFull( Queue *Q )
{
    if((Q->rear+1)%MaxVertexMum == Q->front)
        return 1;
    else
        return 0;
}

int IsEmpty(Queue *Q)
{
    if(Q->rear == Q->front)
        return 1;
    else
        return 0;
}

void AddQ(Queue *Q, int X)
{
    if(IsFull(Q)){
        printf("队列已满，插入错误\n");
        return;
    }
    Q->rear = (Q->rear+1)%MaxVertexMum;
    Q->Data[Q->rear] = X;
}int DeleteQ(Queue *Q)
{
    if( IsEmpty(Q)){
        printf("队列空\n");
        return NULL;
    }else{
        Q->front = (Q->front+1)%MaxVertexMum;
        return Q->Data[Q->front];
    }
}
void BFS(MGraph Graph, Vertex S, void(*Visit)(Vertex))
{
    /* 以S为出发点对邻接矩阵存储的图进行BFS搜索 */
    Queue *Q;
    Vertex V, W;

    Q = CreateQ();

    Visit( S );
    Visited[S] = true;
    AddQ(Q, S);

    while(!IsEmpty(Q)){
        V = DeleteQ(Q);  /* 弹出V */
        for( W=0; W<Graph->Nv; W++ ) /* 对图中的每个顶点W */
            /* 若W是V的邻接点并且未访问过 */
            if ( !Visited[W] && IsEdge(Graph, V, W) ) {
                /* 访问顶点W */
                Visit( W );
                Visited[W] = true; /* 标记W已访问 */
                AddQ(Q, W); /* W入队列 */
            }
    }

}