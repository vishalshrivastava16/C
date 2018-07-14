#include <stdio.h>
#include <stdlib.h>
#include "List.h"


int main()
{
    List *PtrL = NULL;  //头指针
    printf("%d\n",Length(PtrL));

    PtrL = Insert(1,1,PtrL);
    PtrL = Insert(2,2,PtrL);
    PtrL = Insert(10,3,PtrL);
    Print(PtrL);
    PtrL = Delete(1,PtrL);
    Print(PtrL);

    List *p;
    p = FindKth(2,PtrL);
    printf("the second number is %d\n",p->Data);

    p = Find(10,PtrL);
    printf("10 is the %dth number\n",Length(PtrL)-Length(p)+1);

    getchar();
    return 0;
}

void Print(List *PtrL){
    List *p;
    p = PtrL;
    while(p){
        printf("%d\t",p->Data);
        p = p->Next;
    }
    printf("\n");
}

int Length(List *PtrL)
{
    List *p=PtrL;   //指向表头
    int i=0;
    while(p){
        p=p->Next;
        i++;
    }
    return i;
}

List *FindKth(int K, List *PtrL)
{
    List *p = PtrL;
    int i=1;
    while(p != NULL && i<K){
        p = p->Next;
        i++;
    }
    if(i==K)    //找到第K个
        return p;
    else        //没找到
        return NULL;
}

List *Find(int X, List *PtrL)
{
    List *p = PtrL;
    while(p != NULL && p->Data != X)
        p = p->Next;
    return p;
}


//将X插入到PTRL的第i-1个位置之后
List *Insert(int X, int i, List *PtrL)
{
    List *p, *s;
    if(i==1){
        s = (List*)malloc(sizeof(List));
        s->Data = X;
        s->Next = PtrL;
        return s;
    }
    p = FindKth(i-1, PtrL);
    if(p==NULL){
        printf("第i-1个节点不存在");
        return NULL;
    }else{
        s = (List*)malloc(sizeof(List));
        s->Data = X;
        s->Next = p->Next;
        p->Next = s;
        return PtrL;
    }
}

List *Delete(int i, List *PtrL)
{
    List *p, *s;
    if(i==1){   //删除第一个结点
        s = PtrL;
        if(PtrL != NULL )
            PtrL = PtrL->Next;
        else
            return NULL;
        free(s);
        return PtrL;
    }
    p = FindKth(i-1, PtrL);
    if(p==NULL){
        printf("第%d个结点不存在\n",i-1);
        return NULL;
    }else if(p->Next == NULL){
        printf("第%d个结点不存在\n",i);
        return NULL;
    }else{
        s = p->Next;
        p->Next = s->Next;
        free(s);
        return PtrL;
    }
}
