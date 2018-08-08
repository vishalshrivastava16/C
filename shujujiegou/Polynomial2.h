#ifndef POLYNOMIAL2_H
#define POLYNOMIAL2_H

typedef struct Node{
    int Coeff;  //系数
    int Exp;    //指数
    struct Node *Next;
} Polynomial;

Polynomial *AddPoly(Polynomial *p1, Polynomial *p2);
void Attach(int coeff, int exp, Polynomial **rear );
void PrintPoly(Polynomial *Poly);
void InsertPoly(int coeff, int exp, Polynomial *Poly);
Polynomial *CreatPoly();

#endif
