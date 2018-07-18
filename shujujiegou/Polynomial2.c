/* 链表实现多项式 */
#include <stdio.h>
#include <stdlib.h>
#include "Polynomial2.h"
/* 指数递降*/
/* typedef struct Node{
    int Coeff;  //系数
    int Exp;    //指数
    struct Node *Next;
} Polynomial; */


int main(int argc, char const *argv[])
{
    /* code */
    Polynomial *Poly1, *Poly2;
    Poly1 = CreatPoly();
    Poly2 = CreatPoly();

    InsertPoly(2, 4, Poly1);
    InsertPoly(3,5,Poly2);
    InsertPoly(4,3,Poly2);
    
    PrintPoly(Poly1);
    PrintPoly(Poly2);
     
    Polynomial *SumPoly;
    SumPoly = AddPoly(Poly1, Poly2);
    PrintPoly(SumPoly);
    

    getchar();
    return 0;
}

Polynomial *CreatPoly()
{
    Polynomial *p = (Polynomial*)malloc(sizeof(Polynomial));
    p->Next =NULL;
    p->Coeff = 0;
    p->Exp = 0;
    return p;
}

void InsertPoly(int coeff, int exp, Polynomial *Poly)
{
    if(Poly->Exp == 0){    //空多项式
        Poly->Coeff = coeff;
        Poly->Exp = exp;
        return;
    }
    Polynomial *p = (Polynomial*)malloc(sizeof(Polynomial));
    Polynomial *t = Poly;
    p->Coeff = coeff;
    p->Exp = exp;
    p->Next = NULL;
    while(t->Next)
        t = t->Next;
    t->Next = p;

}

Polynomial *AddPoly(Polynomial *p1, Polynomial *p2)
{
    Polynomial *front, *rear, *temp;//头节点、尾节点
    rear = (Polynomial*)malloc(sizeof(Polynomial));
    front = rear;
    while(p1&&p2)//p1 p2都不为空
    {
        if(p1->Exp > p2->Exp){
            Attach(p1->Coeff, p1->Exp, &rear);
            p1 = p1->Next;
        }else if(p1->Exp < p2->Exp){
            Attach(p2->Coeff, p2->Exp, &rear);
            p2 = p2->Next;
        }else{
            if(p1->Coeff + p2->Coeff == 0){
                p1 = p1->Next;
                p2 = p2->Next;
                continue;
            }
            Attach(p1->Coeff + p2->Coeff, p1->Exp, &rear);
            p1 = p1->Next;
            p2 = p2->Next;            
        }
    }
    for(;p1; p1 = p1->Next) Attach(p1->Coeff, p1->Exp, &rear);
    for(;p2;p2 = p2->Next)  Attach(p2->Coeff, p2->Exp, &rear);
    rear->Next = NULL;
    temp = front;
    front = front->Next;//不包含头节点的链表
    free(temp);
    return front;
}

void Attach(int coeff, int exp, Polynomial **rear )
{
    Polynomial *temp = (Polynomial*)malloc(sizeof(Polynomial));
    temp->Exp = exp;
    temp->Coeff = coeff;
    temp->Next = NULL;
    (*rear)->Next = temp;
    *rear = temp;
}

void PrintPoly(Polynomial *Poly)
{
    Polynomial *p = Poly;
    while(p){
        printf("%dX^%d + ", p->Coeff, p->Exp);
        p = p->Next;
    }
    printf("\n");
}