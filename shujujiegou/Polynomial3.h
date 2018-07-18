#ifndef POLYNOMIAL3_H
#define POLYNOMIAL3_H

typedef struct Node{
    int coef;
    int exp;
    struct Node *next;
}   *Polynomial;

Polynomial ReadPoly();
void Attach(int c, int e, Polynomial *rear);
Polynomial Add(Polynomial p1, Polynomial p2);
Polynomial Mult(Polynomial P1, Polynomial P2);
void PrintPoly(Polynomial p);


#endif