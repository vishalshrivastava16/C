#include <stdlib.h>
#include <stdio.h>
#include "Polynomial3.h"
/* typedef struct Node{
    int coef;
    int exp;
    struct Node *next;
}   *Polynomial; */

int main(int argc, char const *argv[])
{
    /* code */
    Polynomial p1, p2, sp;
    p1 = ReadPoly();
    printf("p1:");
    PrintPoly(p1); 

    p2 = ReadPoly();
    printf("p2:");
    PrintPoly(p2);

    sp = Add(p1, p2);
    printf("p1 + p2:");
    PrintPoly(sp);

    printf("p1 * p2:");
    sp = Mult(p1, p2);
    PrintPoly(sp);

    system("pause");
    return 0;
}


Polynomial ReadPoly()
{
    Polynomial front, rear, t;
    front = (Polynomial)malloc(sizeof(struct Node));
    front->next = NULL;
    rear = front;
    int N, c, e;
    printf("poly length: ");
    scanf("%d",&N);
    printf("\n");
    while(N--)
    {
        printf("...");
        scanf("%d %d",&c, &e);
        Attach(c,e,&rear);
    }
    printf("\n");
    t = front;
    front = front->next;
    free(t);
    return front;
}

void Attach(int c, int e, Polynomial *rear)
{
    
    Polynomial P;
    P = (Polynomial)malloc(sizeof(struct Node));
    P->coef = c;
    P->exp = e;
    P->next = NULL;
    (*rear)->next = P;
    *rear = (*rear)->next; 
}

Polynomial Add(Polynomial p1, Polynomial p2)
{
    Polynomial t1, t2, head, rear;
    t1 = p1;
    t2 = p2;
    rear = (Polynomial)malloc(sizeof(struct Node));
    rear->next = NULL;
    head = rear;
    while(t1&&t2)
    {
        if(t1->exp == t2->exp){
            Attach(t1->coef+t2->coef, t1->exp, &rear);
            t1 = t1->next;
            t2 = t2->next;
        }else if(t1->exp > t2->exp){
            Attach(t1->coef, t1->exp, &rear);
            t1 = t1->next;
        }else{
            Attach(t2->coef, t2->exp, &rear);
            t2 = t2->next;
        }
    }
    while(t1)
    {
        Attach(t1->coef, t1->exp, &rear);
        t1 = t1->next;
    }
    while(t2)
    {
        Attach(t2->coef, t2->exp, &rear);
        t2 = t2->next;
    }
    t1 = head;
    head = head->next;
    free(t1);
    return head;
}

Polynomial Mult(Polynomial P1, Polynomial P2)
{
    if(!P1 || !P2)  /* P1,P2中有一项为0 */
        return NULL;
    Polynomial head, rear, t1, t2, t;
    t1 = P1; t2 = P2;
    rear = (Polynomial)malloc(sizeof(struct Node));
    rear->next = NULL;
    head = rear;
    int c, e;
    while(t2){  //将p1第一项分别乘p2
        Attach(t1->coef*t2->coef, t1->exp+t2->exp, &rear);
        t2 = t2->next;
    }
    t1 = t1->next;
    while(t1)
    {
        t2 = P2; 
        rear = head;
        while(t2){
            e = t1->exp + t2->exp;
            c = t1->coef * t2->coef;
            while(rear->next && rear->next->exp > e)
                rear = rear->next;
            if(rear->next && rear->next->exp == e){ //结果系数相等
                if(rear->next->coef + c)
                    rear->next->coef += c;
                else{
                    t = rear->next;
                    rear->next = t->next;
                    free(t);
                }
            }else{
                t = (Polynomial)malloc(sizeof(struct Node));
                t->coef = c;
                t->exp = e;
                t->next = rear->next;
                rear->next = t;
            }
            t2 = t2->next;
        }
        t1 = t1->next;
    }
    t2 = head;
    head = head->next;
    free(t2);
    return head;
}

void PrintPoly(Polynomial p)
{   
    while(p){
        printf("%d %d\t",p->coef, p->exp);
        p = p->next;
    }
    printf("\n");
}