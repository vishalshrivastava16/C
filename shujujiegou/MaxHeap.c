#include <stdio.h>
#include <stdlib.h>
#define MaxData 1000
#define ElementType int
typedef struct HNode{
    ElementType *Elements;/* 数组 */
    int Size;
    int Capacity;
}   *MaxHeap;

typedef enum{false, true} Boolean;
MaxHeap Create(int MaxSize);
Boolean IsFull(MaxHeap H);
void Insert(MaxHeap H, ElementType item);
Boolean IsEmpty(MaxHeap H);
ElementType DeleteMax(MaxHeap H);//返回H中最大元素
void PercDown( MaxHeap H, int p );//下滤；
MaxHeap BuildHeap( MaxHeap H );
int main()
{

    return 0;
}

MaxHeap Create(int MaxSize)
{
    MaxHeap H = (MaxHeap)malloc(sizeof(struct HNode));
    H->Elements = (ElementType)malloc(sizeof(int)*(MaxSize+1));//从下标1开始存储元素
    H->Size = 0;
    H->Capacity = MaxSize;
    H->Elements[0] = MaxData;//哨兵
    return H;
}
Boolean IsFull(MaxHeap H)
{
    return H->Size==H->Capacity;
}
Boolean IsEmpty(MaxHeap H)
{
    return H->Size == 0;
}
void Insert(MaxHeap H, ElementType item)
{
    int i;
    if(IsFull(H)){
        printf("Heap Full\n");
        return;
    }
    i = ++H->Size;
    for(;H->Elements[i/2]<item; i/=2)
        H->Elements[i] = H->Elements[i/2];
    H->Elements[i] = item;
}
ElementType DeleteMax(MaxHeap H)
{
    int Parent, Child;
    ElementType MaxItem, temp;
    if(IsEmpty(H)){
        printf("Heap Empty\n");
        return NULL;
    }
    MaxItem = H->Elements[1];
    temp = H->Elements[H->Size--];
    for(Parent = 1; Parent*2<=H->Size; Parent=Child)
    {
        Child = Parent*2;
        if((Child != H->Size)&&(H->Elements[Child] < H->Elements[Child+1]))
            Child++;
        if(temp > H->Elements[Child])
            break;
        else
            H->Elements[Parent] = H->Elements[Child];
    }
    H->Elements[Parent] = temp;
    return MaxItem;
}

void PercDown( MaxHeap H, int p )
{ /* 下滤：将H中以H->Data[p]为根的子堆调整为最大堆 */
    int Parent, Child;
    ElementType X;
    X = H->Elements[p];

    for(Parent = p; Parent*2 <= H->Size; Parent = Child){
        Child = Parent*2;
        if((Child!=H->Size)&&(H->Elements[Child]<H->Elements[Child+1]))
            Child ++;
        if(X >= H->Elements[Child])
            break;
        else
            H->Elements[Parent] = H->Elements[Child];
    }
    H->Elements[Parent] = X;
}
MaxHeap BuildHeap( MaxHeap H )
{
    int size, i;
    ElementType t;
    scanf("%d",&size);
    for(i=0;i<size;i++){
        scanf("%d",&t);
        H->Elements[i] = t;
    }
    for(i = H->Size/2; i>0; i--)
        PercDown(H, i);
    return H;
}