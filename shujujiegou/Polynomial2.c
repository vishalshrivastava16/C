/* 链表实现多项式 */
#include <stdio.h>
#include <stdlib.h>

/* 多项式由次数由低到高 */
typedef struct Node{
    int Coeff;  //系数
    int Exp;    //次数
    struct Node *Next;
} Polynomial;

Polynomial *ZeroPolynomial( Polynomial *Poly);
void PrintPolynomial( Polynomial *Poly);
Polynomial *InsertPolynomial(Polynomial *Poly, int coeff, int Exp);
Polynomial *AddPolynomial( Polynomial *Poly1, Polynomial *Poly2, Polynomial *SumPoly);


int main()
{
    Polynomial *poly1 = NULL;
    poly1 = ZeroPolynomial(poly1);

    PrintPolynomial(poly1);

    poly1 = InsertPolynomial(poly1, 3, 5);
    Polynomial *poly2 = NULL;
    poly2 = ZeroPolynomial(poly2);
    poly2 = InsertPolynomial(poly2, 2, 6);
    Polynomial *SumPoly;
    PrintPolynomial(poly1);
    PrintPolynomial(poly2);
    SumPoly = AddPolynomial(poly1,poly2, SumPoly);
    PrintPolynomial(SumPoly);


    getchar();
    return 0;
}

/* 多项式初始化 */
Polynomial *ZeroPolynomial( Polynomial *Poly)
{
    Polynomial *p = (Polynomial*)malloc(sizeof(Polynomial));
    
    p->Next = NULL;
    p->Coeff = 0;
    p->Exp = 0;
    return p;
}

/* 打印多项式 */
void PrintPolynomial( Polynomial *Poly)
{
    Polynomial *p = Poly;
    printf("Polynomial = ");
    while(p){
        printf("%d*X^%d + ",p->Coeff,p->Exp);
        p=p->Next;
    }
    printf("\n");
}

/* 插入项数 */
Polynomial *InsertPolynomial(Polynomial *Poly, int coeff, int Exp)
{
    Polynomial *p = (Polynomial*)malloc(sizeof(Polynomial)), *s;
    /* 在末尾插入 */
    s = Poly;
    while(s->Next)
        s = s->Next;
    s->Next = p;
    p->Coeff = coeff;
    p->Exp = Exp;
    p->Next = NULL;
    return Poly;
}
/* 多项式相加 */
Polynomial *AddPolynomial( Polynomial *Poly1, Polynomial *Poly2, Polynomial *SumPoly)
{
    Polynomial *s, *p, *z;
    s=Poly1;
    p=Poly2;
    SumPoly = NULL;
    z=SumPoly;
    while(s->Next){
        z = (Polynomial*)malloc(sizeof(Polynomial));        
        if(s->Exp == p->Exp){
            z->Exp = s->Exp;
            z->Coeff = ( s->Coeff + p->Coeff);
            s = s->Next;
            p = p->Next;
        }else if(s->Exp>p->Exp){
            z->Exp = p->Exp;
            z->Coeff = p->Coeff;
            p = p->Next;
        }else {
            z->Exp = s->Exp;
            z->Coeff = s->Coeff;
            s = s->Next;
        }
        z = z->Next;
    }

    z= p;

    return SumPoly;
}