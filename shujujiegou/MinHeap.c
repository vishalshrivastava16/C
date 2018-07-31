#include <stdio.h>
#include <stdlib.h>
#define MinData -10001
#define ElementType int

typedef struct HNode{
    ElementType *Data;
    int Size;
    int Capacity;
}   *MinHeap;

void PerDown(MinHeap H, int p)
{
    //在H中以p为根调整为最小堆
    int Parent, Child;
    ElementType X;
    X = H->Data[p];

    for(Parent = p; Parent*2<=H->Size; Parent = Child)
    {
        Child = Parent*2;
        if((Child!=H->Size)&&(H->Data[Child]>H->Data[Child+1]))
            Child++;
        if(X<=H->Data[Child])
            break;
        else
            H->Data[Parent] = H->Data[Child];
    }
    H->Data[Parent] = X;
}

MinHeap CreateHeap(int MaxSize)
{
    MinHeap H = (MinHeap)malloc(sizeof(struct HNode));
    H->Capacity = MaxSize;
    H->Size = 0;
    H->Data = (int*)malloc(sizeof(int)*(MaxSize+1));
    H->Data[0] = MinData;
    return H;
}

MinHeap BuildHeap(MinHeap H)
{
    ElementType n;
    int Parent, Child;
    int i;
    while(H->Size<H->Capacity)
    {
        scanf("%d",&n);
        H->Data[++H->Size] = n;
    }
    // 排序
    for(i=H->Size/2;i>0;i--)
        PerDown(H,i);
    return H;
}

void PrintHeap(MinHeap H, int path)
{
    int flag, data, i;
    for(i=0;i<path;i++)
    {
        flag = 0;
        scanf("%d",&data);
        while(data){
            if(flag){
                printf(" ");
                flag = 0;
            }
            else{
                flag = 1;
                printf("%d",H->Data[data]);
                data/=2;
            }
        }
        printf("\n");
    }
}

int main()
{
    int MaxSize, path;
    scanf("%d %d",&MaxSize,&path);
    MinHeap H = CreateHeap(MaxSize);
    H = BuildHeap(H);
    PrintHeap(H, 3);

    system("pause");
    return 0;
}