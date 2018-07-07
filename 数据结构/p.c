#include <stdio.h>
#include <time.h>
#include <math.h>

clock_t start,stop;
double duration;
#define MAXN 100
#define MAXK 1e6 //被测函数最大调用次数
double f1(int n, double a[], double x);
double f2(int n, double a[], double x);

int main(){
    int i;
    double a[MAXN];
    for (i=0;i<MAXN;i++) a[i]=(double)i;

    start = clock();
    for(i=0;i<MAXK;i++)
        f1(MAXN-1,a,1.1);
    stop = clock();
    duration = ((double)(stop-start))/CLK_TCK;
    printf("循环实现：%lf\n",duration);

    start = clock();
    for(i=0;i<MAXK;i++)
        f2(MAXN-1,a,1.1);
    stop = clock();
    duration = ((double)(stop-start))/CLK_TCK;
    printf("递归实现：%lf\n",duration);
    return 0;
}

double f1(int n, double a[], double x){
    //循环实现
    int i;
    double p = a[0];
    for(i=0;i<=n;i++){
        p+=(a[i] * pow(x,i));
    }
    return p;
}

double f2(int n, double a[], double x){
    //递归实现
    int i;
    double p=a[n];
    for (i=n;i>0;i--){
        p=a[i-1] + x*p;
    }
    return p;
}
