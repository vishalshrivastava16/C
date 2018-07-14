#include <stdio.h>
#include <stdlib.h>
#include "Stack2.h"
/* 栈的链表实现
typedef struct Node{
    int Data;
    struct Node *Next;
} LinkStack; */

int main()
{
    LinkStack *stack = CreateStack();
    printf("Is empty:%d\n",IsEmpty(stack));
    Push(2,stack);
    Push(3,stack);
    printf("Pop : %d\n",Pop(stack));
    printf("Pop : %d\n",Pop(stack));
    


    getchar();
    return 0;
}

LinkStack *CreateStack()
{
    LinkStack *S;
    S = (LinkStack*)malloc(sizeof(LinkStack));
    S->Next = NULL;
    return S;
}
int IsEmpty(LinkStack *S)
{
    return S->Next == NULL;
}

void Push(int x, LinkStack *S)
{
    LinkStack *p;
    p = (LinkStack*)malloc(sizeof(LinkStack));
    p->Data = x;
    p->Next = S->Next;
    S->Next = p;
}

int Pop(LinkStack *S)
{
    LinkStack *FirstCell;
    int number;
    if(IsEmpty(S)){
        printf("Empty Stack\n");
        return NULL;
    }else{
        FirstCell = S->Next;
        number = FirstCell->Data;
        S->Next = FirstCell->Next;
        free(FirstCell);
        return number;
    }
}

