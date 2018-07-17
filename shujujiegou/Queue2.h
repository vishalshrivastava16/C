#ifndef QUEUE2_H
#define QUEUE2_H

typedef struct Node{
    int Data;
    struct Node *Next;
}QNode;

typedef struct{
    QNode *rear;
    QNode *front;
}LinkQueue;

LinkQueue *CreateQ();
void AddQ(LinkQueue *Q, int X);
int IsEmpty(LinkQueue *Q);
int DeleteQ(LinkQueue *Q);

#endif
