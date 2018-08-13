#include <stdio.h>
#include <stdlib.h>
#define MaxVertexMum 100    /* 最大顶点数100 */
#define INFINITY 65535  /* 双字节无符号整数最大值65535 */
typedef int Vertex; /* 顶点 */
typedef int WeightType;  /* 权 */
typedef char DataType;   /* 顶点存储的数据类型 */

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

int main()
{


    return 0;
}