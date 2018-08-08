#include <stdio.h>
#define ElementType int
#define NotFound -1

int BinarySearch(ElementType A[], ElementType X, int N);//二分查找 数组A已降序排序

int main()
{
    int a[]={9,8,7,6,5,4,3,2,1};
    int X =5;
    int N = 9;
    printf("%d",BinarySearch(a,X,N));

    return 0;
}

int BinarySearch(ElementType A[], ElementType X, int N)
{
    int Low, Mid, High;
    Low = 0;
    High = N-1;

    while(Low<High)
    {
        Mid = (Low + High)/2;
        if(A[Mid]>X)
            High = Mid -1;
        else if (A[Mid]<X)
            Low = High + 1;
        else
            return Mid;//找到
    }

    return NotFound;//未找到
}
