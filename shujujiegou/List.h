#ifndef _LIST_H
#define _LIST_H

typedef struct list{
    int Data;
    struct list *Next;
} List;

int Length(List *PtrL);
List *FindKth(int K, List *PtrL);
List *Find(int X, List *PtrL);
List *Insert(int X, int i, List *PtrL);
List *Delete(int i, List *PtrL);
void Print(List *PtrL);







#endif
