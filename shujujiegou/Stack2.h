#ifndef STACK2_H
#define STACK2_H

/* 栈的链表实现 */
typedef struct Node{
    int Data;
    struct Node *Next;
} LinkStack;

LinkStack *CreateStack();
int IsEmpty(LinkStack *S);
void Push(int x, LinkStack *S);
int Pop(LinkStack *S);




#endif