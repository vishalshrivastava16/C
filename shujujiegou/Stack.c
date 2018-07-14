#include <stdio.h>
#include "Stack.h"

/* 栈的数组实现 */

int main()
{
    Stack s = CreateStack();
    printf("IsEmpty :%d\n",IsEmpty(s));
    Push(&s,10);
    Push(&s,9);
    printf("top:%d\n",s.top);
    printf("Pop:%d\n",Pop(&s));
    printf("Pop:%d\n",Pop(&s));    
    printf("IsEmpty :%d\n",IsEmpty(s));

    getchar();
    return 0;
}

Stack CreateStack()
{
    Stack stack;
    stack.top = -1;
    return stack;
}

int IsEmpty(Stack s)
{
    return s.top == -1;
}

void Push(Stack *s, int value)
{
    if(IsFull(*s))
        printf("Stack full\n");
    else
        s->array[++(s->top)] = value;
}

int Pop(Stack *s)
{
    if(IsEmpty(*s))
        return ERROR;
    else
        return s->array[s->top--];
}

int IsFull(Stack s)
{
    if(s.top==MAXSIZE)
        return 1;
    else
        return 0;
}







