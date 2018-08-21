#include <stdio.h>
#include <stdlib.h>
#define MinTableSize 10
#define ElementType int
/* 删除标记 */
#define Empty 0 /* 空 */
#define Legitimate 1   /* 有数据 */
typedef int Posion;

/* 开放地址法 */
typedef struct{
    ElementType Element;
    int Info;/* Info为1表示有元素，为0表示元素被删除 */
}Cell;

typedef struct HashTbl{
    int TableSize;
    Cell *TheCells;
}*HashTable;

int NextPrie(int TableSize)
{

}

HashTable Initialize( int TableSize)
{
    HashTable H;
    int i;
    if(TableSize < MinTableSize){
        printf("散列表太小\n");
        return NULL;
    }

    /* 分配散列表 */
    H = (HashTable)malloc(sizeof(struct HashTbl));
    if( H == NULL){
        printf("空间溢出\n");
        return NULL;
    }
    H->TableSize = NextPrie(TableSize);

    /* 分配散列表Cells */
    H->TheCells = (Cell*)malloc(sizeof(Cell)*H->TableSize);
    if(H->TheCells==NULL){
        printf("空间溢出!\n");
        return NULL;
    }
    for(i=0; i<H->TableSize; i++)
        H->TheCells[i].Info = Empty;

    return H;
}

Posion Hash( Posion Key, int TableSize )
{
    /* 模运算 */
    return Key % TableSize;
}

Posion Find( ElementType Key, HashTable H )/* 平方探测 */
{
    Posion CurrentPos, NewPos;
    int CNum=0;/* 记录冲突次数 */
    NewPos = CurrentPos = Hash(Key, H->TableSize);
    while(H->TheCells[NewPos].Info != Empty && H->TheCells[NewPos].Element != Key)
    {
        if(++CNum % 2){/* 判断冲突的奇偶次数 */
            NewPos = CurrentPos + (CNum+1)/2*(CNum+1)/2;
            while(NewPos >= H->TableSize)
                NewPos -= H->TableSize;
        }else{
            NewPos = CurrentPos - CNum/2 * CNum/2;
            while(NewPos < 0)
                NewPos += H->TableSize;
        }
    }

    return NewPos;
}

void Insert(ElementType Key, HashTable H)
{
    Posion Pos;
    Pos = Find( Key, H );
    if(H->TheCells[Pos].Info != Legitimate){
        H->TheCells[Pos].Info = Legitimate;
        H->TheCells[Pos].Element = Key;
    }
}
