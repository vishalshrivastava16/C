#include <stdio.h>

int IsEven(long int x);
long int PowN(long int x, int n);

int main()
{
    printf("%d\n",PowN(2,10));

    return 0;
}

long int PowN(long int x, int n)
{
    if(n==0)
        return 1;
    if(n==1)
        return x;
    if(IsEven(n))
        return PowN(x*x,n/2);
    else
        return PowN(x*x,n/2)*x;
}

int IsEven(long int n)
{
    if((n-2*(n/2))==1)
        return 0;
    else
        return 1;
}
