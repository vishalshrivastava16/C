#include <stdio.h>
#include "queue.h"

/* typedef struct{
    int Data[MaxSize];
    int rear;//尾
    int front;//头
} Queue; */

int main()
{
    Queue *Q = CreateQ();
    AddQ(Q , 5);
    AddQ(Q, 3);
    AddQ(Q, 7);
    while(!IsEmpty(Q))
        printf("%d\n",DeleteQ(Q));

    return 0;
}

Queue *CreateQ()
{
    Queue *Q;
    Q->rear = -1;
    Q->front = -1;
    return Q;
    
}

void AddQ(Queue *Q, int X)
{
    if(IsFull(Q)){
        printf("队列已满，插入错误\n");
        return;
    }
    Q->rear = (Q->rear+1)%MaxSize;
    Q->Data[Q->rear] = X;
}

int DeleteQ(Queue *Q)
{
    if( IsEmpty(Q)){
        printf("队列空\n");
        return NULL;
    }else{
        Q->front = (Q->front+1)%MaxSize;
        return Q->Data[Q->front];
    }
}

int IsFull( Queue *Q )
{
    if((Q->rear+1)%MaxSize == Q->front)
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