#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#define MaxDegree 1000

typedef struct{
    int CoeffArray[MaxDegree + 1];
    int HighPower;
} Polynomial;

void ZeroPolynomial(Polynomial *Poly);
void AddPolynomial(const Polynomial *Poly1, const Polynomial *Poly2, Polynomial *PolySum);
int Max(int a, int b);
void MultPolynomial(const Polynomial *Poly1, const Polynomial *Poly2, Polynomial *PolyProd );




#endif