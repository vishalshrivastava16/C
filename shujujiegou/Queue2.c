#include <stdio.h>
#include <stdlib.h>
#include "Queue2.h"

/* typedef struct Node{
    int Data;
    struct Node *Next;
}QNode;

typedef struct{
    QNode *rear;
    QNode *front;
}LinkQueue; */

int main()
{
    LinkQueue *Q = CreateQ();

    AddQ(Q, 3);
    AddQ(Q, 6);
    AddQ(Q, 9);

    while(!IsEmpty(Q))
        printf("%d\n",DeleteQ(Q));

    printf("%d\n",DeleteQ(Q));
    
    return 0;
}

LinkQueue *CreateQ()
{
    LinkQueue *Q;
    Q->front= NULL;
    Q->rear= NULL;
    return Q;
}

void AddQ(LinkQueue *Q, int X)
{
    QNode *TailCell = (QNode*)malloc(sizeof(QNode));
    TailCell->Data = X;
    TailCell->Next = NULL;    
    if(IsEmpty(Q)){//队列空 头尾同时指向
        Q->front = TailCell;
        Q->rear = TailCell;
    }else if(Q->rear == Q->front ){//只有一个元素时，头指向尾，尾指向T
        Q->rear = TailCell;
        Q->front->Next=Q->rear;
    }else{//尾后移
        Q->rear->Next = TailCell;
        Q->rear = Q->rear->Next;
    }
}

int IsEmpty(LinkQueue *Q)
{
    return Q->front == NULL;
}

int DeleteQ(LinkQueue *Q)
{
    QNode *FrontCell;
    int data;
    if(IsEmpty(Q)){
        printf("Empty delete error! ");
        return NULL;
    }
    FrontCell = Q->front;
    data = FrontCell->Data;
    if(Q->front == Q->rear)//只有一个元素
        Q->front = Q->rear = NULL;
    else
        Q->front = Q->front->Next;
    free(FrontCell);
    return data;
}