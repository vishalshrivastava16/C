#ifndef STACK_H
#define STACK_H

#define MAXSIZE 100
#define ERROR -1

typedef struct _stack{
    int array[MAXSIZE];
    int top;
} Stack;

Stack CreateStack();
int IsEmpty(Stack s);
void Push(Stack *s, int value);
int Pop(Stack *s);
int IsFull(Stack s);


#endif