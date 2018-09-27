#include <stdio.h>
#include <stdlib.h>
#define ElementType int
#define MaxSize 10

typedef struct{
    ElementType Data;
    int Parent;
} SetType;

int Find(SetType S[], ElementType X)
{
    /* 在数组S中查找值为X的元素所属的集合, 并返回根的下标 */
    int i;
    for(i=0; i<MaxSize && S[i].Data != X; i++) ;
    if(i >= MaxSize)
        return -1;   //未找到
    for( ; S[i].Parent >= 0; i = S[i].Parent) ;
    return i;
}

void Union(SetType S[], ElementType X1, ElementType X2)
{
    int Root1, Root2;
    Root1 = Find(S, X1);
    Root2 = Find(S, X2);
    if(Root1 <= Root2)
        S[Root2].Parent = Root1;
    else
        S[Root1].Parent = Root2;
}

void UMatch(SetType S[], int X1, int X2)
{
    if(Find(S,X1)==Find(S,X2))
        printf("match!\n");
    else
        printf("no match!\n");
}
int main()
{
    /* Data表示数值，Parent为正表示父节点下标，为负表示集合元素的个数 */
    int number, i, t;
    scanf("%d",&number);
    SetType S[number];
    for(i=0; i<number; i++){
        scanf("%d", &t);
        S[i].Data = t;
        S[i].Parent = -1;
    }

    Union(S,1,2);
    Union(S,1,4);
    Union(S,1,7);
    Union(S,6,9);
    Union(S,6,10);
    Union(S,3,5);
    Union(S,3,8);
    
    UMatch(S, 6, 10);
    UMatch(S, 8, 3);
    UMatch(S, 4, 5);
    system("pause");

    return 0;
}