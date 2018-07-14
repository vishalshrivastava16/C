#include <stdio.h>

int MSSS1(int a[], int n);  //三重循环
int MSSS2(int a[], int n);  //二重循环
int MSSS3(int a[], int Left, int Right);    //递归
int MSSS4(int a[], int n);  //在线算法(Online algorithm)
int Max3(int a, int b, int c);


int main()
{
    int a[]={4,-3,5,-2,-1,2,6,-2};
    int n=8;
    int sum=0;
    sum=MSSS1(a,n);
    printf("算法1：%d\n",sum);
    sum=MSSS2(a,n);
    printf("算法2：%d\n",sum);
    sum=MSSS3(a,0,7);
    printf("算法3：%d\n",sum);
    sum=MSSS4(a,n);
    printf("算法4：%d\n",sum);
    return 0;
}

int MSSS1(int a[], int n){
    int ThisSum,MaxSum,i,j,k;
    MaxSum = 0;
    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++){
            ThisSum=0;
            for(k=i;k<=j;k++){
                ThisSum+=a[k];
                if (ThisSum>MaxSum){
                    MaxSum=ThisSum;
                }
            }
        }
    }
    return MaxSum;
}

int MSSS2(int a[], int n)
{
    int ThisSum,MaxSum,i,j;
    MaxSum = 0;
    for(i=0;i<n;i++)
    {
        ThisSum=0;
        for(j=i;j<n;j++)
        {
            ThisSum+=a[j];
            if (ThisSum>MaxSum)
                MaxSum = ThisSum;
        }
    }
    return MaxSum;
}

int MSSS3(int a[], int Left, int Right)
{
    int MaxLeftSum, MaxRightSum;
    int MaxLeftBorderSum, MaxRightBorderSum;
    int LeftBorderSum, RightBorderSum;
    int Center, i;

    if(Left==Right)
    {
        if(a[Left]>0)
            return a[Left];
        else
            return 0;
    }

    Center = (Right+Left)/2;
    MaxLeftSum = MSSS3(a, Left, Center);
    MaxRightSum = MSSS3(a,Center+1, Right);

    MaxLeftBorderSum = 0;
    LeftBorderSum = 0;
    for(i=Center;i>=Left;i--)
    {
        LeftBorderSum += a[i];
        if (LeftBorderSum > MaxLeftBorderSum)
            MaxLeftBorderSum = LeftBorderSum;
    }

    MaxRightBorderSum = 0;
    RightBorderSum = 0;
    for(i=Center+1; i<=Right; i++)
    {
        RightBorderSum += a[i];
        if (RightBorderSum>MaxRightBorderSum)
            MaxRightBorderSum = RightBorderSum;
    }

    return Max3(MaxLeftBorderSum + MaxRightBorderSum, MaxLeftBorderSum, MaxRightBorderSum );
}

int Max3(int a, int b, int c)
{
    if (a>b && a>c)
        return a;
    else if (b>a && b>c)
        return b;
    else
        return c;
}

int MSSS4(int a[], int n)
{
    int ThisSum, MaxSum, i;
    ThisSum = MaxSum = 0;
    for(i=0;i<n;i++)
    {
        ThisSum += a[i];

        if (ThisSum>MaxSum)
            MaxSum = ThisSum;
        else if(ThisSum<0)
            ThisSum=0;
    }
    return MaxSum;
}
