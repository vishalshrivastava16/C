#include <stdio.h>

int Gcd(int M, int N);//欧几里得算法，求最大公约数
int main()
{
    printf("%d",Gcd(1989,1590));
    getchar();
    return 0;
}

int Gcd(int M, int N)
{
    int Rem;
    while (N>0)
    {
        Rem = M % N;
        M = N;
        N = Rem;
    }
    return M;
}
