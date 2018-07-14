#include <stdio.h>
#include <stdlib.h>
#include "Polynomial.h"


int main(int argc, char const *argv[])
{
    Polynomial p1 = {
        {0,1,2,3},
        3
    };
    Polynomial p2 ={
        {0,1,2,3},
        3
    };
    Polynomial pp;
    ZeroPolynomial(&pp);
    AddPolynomial(&p1,&p2,&pp);
    printf("%d\n",pp.CoeffArray[pp.HighPower]);
    ZeroPolynomial(&pp);
    MultPolynomial(&p1,&p2,&pp);
    int i;
    printf("pp = ");
    for(i=0; i<=pp.HighPower; i++)
        printf("%d*x^%d+",pp.CoeffArray[i],i);

    getchar();
    return 0;
}



/* 初始化 */
void ZeroPolynomial(Polynomial *Poly)
{
    int i ;
    for(i=0; i<=MaxDegree; i++)
        Poly->CoeffArray[i] = 0;
    Poly->HighPower = 0;
}

/* 两个多项式相加 */
void AddPolynomial(const Polynomial *Poly1, const Polynomial *Poly2, Polynomial *PolySum)
{
    int i;
    ZeroPolynomial(PolySum);
    PolySum->HighPower = Max(Poly1->HighPower, Poly2->HighPower);
    for(i=PolySum->HighPower; i>=0; i--)
        PolySum->CoeffArray[i] = Poly1->CoeffArray[i] + Poly2->CoeffArray[i];
    
}
int Max(int a, int b)
{
    return a>b?a:b;
}

/* 两个多项式相乘 */
void MultPolynomial(const Polynomial *Poly1, const Polynomial *Poly2, Polynomial *PolyProd )
{
    int i, j;
    ZeroPolynomial(PolyProd);
    PolyProd->HighPower = Poly1->HighPower + Poly2->HighPower;
    if(PolyProd->HighPower > MaxDegree)
        printf("超出最大维数限制");
    else
    {
        for(i=0; i<=Poly1->HighPower; i++)
            for(j=0; j<=Poly2->HighPower; j++)
                PolyProd->CoeffArray[i+j] += Poly1->CoeffArray[i] * Poly2->CoeffArray[j];
    }
}