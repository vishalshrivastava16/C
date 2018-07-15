#ifndef QUEUE_H
#define QUEUE_H

#define MaxSize 20

typedef struct{
    int Data[MaxSize];
    int rear;//尾
    int front;//头
} Queue;

Queue *CreateQ();
void AddQ(Queue *Q, int X);
int DeleteQ(Queue *Q);
int IsFull( Queue *Q );
int IsEmpty(Queue *Q);


#endif