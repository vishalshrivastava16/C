#ifndef POLYNOMIAL2_H
#define POLYNOMIAL2_H

<<<<<<< HEAD
=======
/* 指数递降*/
>>>>>>> 923acce7af655d035c6128325b80fe0abe398b07
typedef struct Node{
    int Coeff;  //系数
    int Exp;    //指数
    struct Node *Next;
} Polynomial;

<<<<<<< HEAD
=======
/* 实现多项式相加 */
>>>>>>> 923acce7af655d035c6128325b80fe0abe398b07
Polynomial *AddPoly(Polynomial *p1, Polynomial *p2);
void Attach(int coeff, int exp, Polynomial **rear );
void PrintPoly(Polynomial *Poly);
void InsertPoly(int coeff, int exp, Polynomial *Poly);
Polynomial *CreatPoly();

<<<<<<< HEAD
#endif
=======

#endif
>>>>>>> 923acce7af655d035c6128325b80fe0abe398b07
