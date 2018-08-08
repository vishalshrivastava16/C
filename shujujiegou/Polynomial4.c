#include <stdio.h>
#include <stdlib.h>

typedef struct PNode
{
    int Coef;
    int Exp;
    struct PNode *Next;
}   *Poly;

Poly Attach(Poly p, int coef, int exp)
{
    Poly t = (Poly)malloc(sizeof(struct PNode));
    t->Exp = exp;
    t->Coef = coef;
    t->Next = NULL;
    p->Next = t;
    p = p->Next;
    return p;
}
Poly ReadPoly()
{
    //带头节点,指数递降的多项式
    Poly head = (Poly)malloc(sizeof(struct PNode));
    head->Next = NULL;
    Poly t = head;
    int num, cnt, coef, exp;
    scanf("%d",&num);
    //printf("num = %\n",num);
    for(cnt=0;cnt<num;cnt++)
    {
        scanf("%d %d",&coef,&exp);
        t = Attach(t,coef,exp);
    }
    getchar();
    return head;
}

void PrintPoly(Poly p)
{
    p = p->Next;
    if(!p)
        printf("0 0");
    else{
        while(p)
        {
            printf("%d %d",p->Coef,p->Exp);
            p = p->Next;
            if(p)
                printf(" ");
        }
    }
    printf("\n");
}

Poly AddPoly(Poly P1, Poly P2)
{
    Poly p1 = P1->Next, p2 = P2->Next;
    Poly head = (Poly)malloc(sizeof(struct PNode));
    head->Next = NULL;
    Poly p= head;
    while(p1&&p2){
        if(p1->Exp == p2->Exp){
            if(p1->Coef+p2->Coef){
                p = Attach(p,p1->Coef+p2->Coef,p1->Exp);
            }
            p1 = p1->Next;
            p2 = p2->Next;
        }else if(p1->Exp>p2->Exp){
            p = Attach(p,p1->Coef,p1->Exp);
            p1 = p1->Next;   
        }else{
            p = Attach(p,p2->Coef,p2->Exp);
            p2 = p2->Next; 
        }
    }
    for(;p1;p1=p1->Next) 
        p = Attach(p,p1->Coef,p1->Exp);
    for(;p2;p2=p2->Next)
        p = Attach(p,p2->Coef,p2->Exp);
    return head;
}

Poly Mult(Poly P1, Poly P2)
{
    int e,c;
    Poly temp, t, p1 = P1->Next, p2 = P2->Next;
    Poly head = (Poly)malloc(sizeof(struct PNode));
    head->Next = NULL;
    Poly p = head;
    if(!p1 || !p2)  return head;
    while(p2)
    {
        //初始多项式
        p = Attach(p,p1->Coef*p2->Coef,p1->Exp+p2->Exp);
        p2 = p2->Next;
    }
    p1 = p1->Next;
    while(p1){
        p2 = P2->Next;
        t = head;
        while(p2){
            e = p1->Exp + p2->Exp;
            c = p1->Coef * p2->Coef;
            while(t->Next && t->Next->Exp > e)
                t = t->Next; 
            if(t->Next && t->Next->Exp == e){
                //合并
                if(t->Next->Coef + c)
                    t->Next->Coef += c;
                else{
                    temp = t->Next;
                    t->Next = temp->Next;
                    free(temp);     
                }
            }else{
                temp = (Poly)malloc(sizeof(struct PNode));
                temp->Coef = c;
                temp->Exp = e;
                temp->Next = t->Next;
                t->Next = temp;
                t = t->Next;
            }
            p2 = p2->Next;
        } 
        p1 = p1->Next;
    }
    return head;
}
int main()
{
    Poly p1 = ReadPoly();  
    Poly p2 = ReadPoly();
    //PrintPoly(p1); 
    //PrintPoly(p2);

    Poly mult = Mult(p1,p2);
    PrintPoly(mult);

    Poly sum = AddPoly(p1,p2);
    PrintPoly(sum);
    
    getchar();
    
    return 0;
}

