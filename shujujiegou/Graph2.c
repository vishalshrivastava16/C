/* 图的链表表示法 */
#include <stdio.h>
#include <stdlib.h>

#define MaxVertexNum 100    /* 最大顶点数100 */
typedef int Vertex; /* 顶点下标 */
typedef int WeightType; /* 变的权值 */
typedef char DataType;  /* 顶点的数据 */

/* 边的定义 */
typedef struct ENode{
    Vertex V1, V2;
    WeightType Weight;
} *Edge;

/* 邻接点的定义 */
typedef struct AdjVNode{
    Vertex Adjv;    /* 邻接点下标 */
    WeightType Weight;  /* 边权重 */
    struct AdjVNode *Next;   /* 下一个邻接点 */
}*PtrToAdjVNode;

/* 顶点表头节点的定义 */
typedef struct VNode{
    PtrToAdjVNode FirstEdge;    /* 边表头指针 */
    DataType Data;
}AdjList[MaxVertexNum];

/* 图结点的定义 */
typedef struct GNode{
    int Nv; /* 顶点数 */
    int Ne; /* 边数 */
    AdjList G;  /* 邻接表 */
}   *LGraph;

LGraph CreateGraph(int VertexNum)
{
    /* 初始化一个有VertexNum个顶点但没有边的图 */
    Vertex V;
    LGraph Graph = (LGraph)malloc(sizeof(struct GNode));
    Graph->Nv = VertexNum;
    Graph->Ne = 0;

    /* 初始化邻接表头指针 */
    for(V = 0; V<Graph->Nv; V++)
        Graph->G[V].FirstEdge = NULL;

    return Graph;
}

void InsertEdge( LGraph Graph, Edge E)
{
    PtrToAdjVNode NewNode;

    /* 插入边<V1,V2> */
    /* 为V2建立新的邻接点 */
    NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
    NewNode->Adjv = E->V2;
    NewNode->Weight = E->Weight;
    /* 将V2插入V1的表头 */
    NewNode->Next = Graph->G[E->V1].FirstEdge;
    Graph->G[E->V2].FirstEdge = NewNode;

    /* 若是无向图，插入边<V2,V1> */
    /* 为V1建立新的邻接点 */
    NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
    NewNode->Adjv = E->V1;
    NewNode->Weight = E->Weight;
    /* 将V1插入V2的表头 */
    NewNode->Next = Graph->G[E->V2].FirstEdge;
    Graph->G[E->V2].FirstEdge = NewNode;
}

LGraph BuildGraph()
{
    LGraph Graph;
    Edge E;
    Vertex V;
    int Nv, i;

    scanf("%d", &Nv);   /* 读入顶点个数 */
    Graph = CreateGraph(Nv);

    scanf("%d", &(Graph->Ne));   /* 读入边的个数 */
    if( Graph->Ne){/* 如果有边 */
        E = (Edge)malloc(sizeof(struct ENode));
        /* 读入 起点 终点 权重 插入邻接矩阵 */
        for(i=0; i<Graph->Ne; i++){
            scanf("%d %d %d", &E->V1, &E->V2, E->Weight);
            InsertEdge(Graph, E);
        }
    }

    /* 如果顶点有数据，读入数据 */
    for(V=0; V<Graph->Nv; V++)
        scanf(" %c", &(Graph->G[V].Data));
    
    return Graph;
}

/* DFS */
void Visit( Vertex V )
{
    printf("正在访问顶点%d\n", V);
}

int Visited[];
/* Visited[]为全局变量，已初始化为false */
void DFS( LGraph Graph, Vertex V, void(*Visit)(Vertex))
{   /* 以V点出发对邻接表存储的图进行DFS搜索 */
    PtrToAdjVNode W;
    Visit(V);
    Visited[V] = 1;

    for(W=Graph->G[V].FirstEdge; W; W = W->Next)/* 对V的每个邻接点W->AdjV */
        if(!Visited[W->Adjv])/* 若W->AdjV未被访问 */
            DFS(Graph, W->Adjv, Visit);
}