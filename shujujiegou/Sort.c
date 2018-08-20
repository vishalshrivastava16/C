#include <stdio.h>
#include <stdlib.h>

/* 默认从小到大排序 */
#define ElementType int

void Swap(ElementType *A, ElementType *B)
{
    ElementType t;
    t = *A;
    *A = *B;
    *B = t;
}

/* 冒泡排序(简单排序) */
/* 最好情况 T = O(N) */
/* 最坏情况 T = O(N^2) */
void Bubble_Sort( ElementType A[], int N )
{
    int P, i, flag;
    for(P=N; P>=0; P--){
        flag = 0;
        for(i=0; i<P; i++){
            if( A[i] > A[i+1] ){
                Swap(A[i], A[i+1]);
                flag = 1;/* 标识发生了交换 */
            }
        }
        if(flag==0) break;  /* 全程无交换则已经排好序 */
    }
}

/* 插入排序 */
/* 最好情况 T = O(N) */
/* 最坏情况 T = O(N^2) */
void Insertion_Sort( ElementType A[], int N)
{
    int P, Tmp, i;
    for(P=1; P<N; P++){/* 默认第一个数已经排序 */
        Tmp = A[P];
        for(i=P; i>0 && A[i-1]>Tmp; i--)
            A[i] = A[i-1];
        A[i] = Tmp;
    }
}

/* 希尔排序 */
void Shell_Sort( ElementType A[], int N )
{
    /* 使用Sedgewick增量序列 */
    int Si, D, P, i;
    ElementType Tmp;
    /* 增量 */
    int Sedgewick[] = {929, 505, 209, 109, 41, 19, 5, 1, 0};

    for(Si=0; Sedgewick[Si]>=N; Si++)
        ;   /* 初始增量小于待排序列长度 */
    
    for( D=Sedgewick[Si]; D>0; D = Sedgewick[++Si]){
        /* 插入排序 */
        for( P=D; P<N; P++){
            Tmp = A[P];
            for( i=P; i>D && A[i-D]>Tmp; i-=D)
                A[i] = A[i-D];
            A[i] = Tmp;
        }
    }

}

/* 堆排序:向下过滤 */
void PercDown( ElementType A[], int p, int N )
{ /* 改编代码4.24的PercDown( MaxHeap H, int p )    */
  /* 将N个元素的数组中以A[p]为根的子堆调整为最大堆 */
    int Parent, Child;
    ElementType X;
 
    X = A[p]; /* 取出根结点存放的值 */
    for( Parent=p; (Parent*2+1)<N; Parent=Child ) {
        Child = Parent * 2 + 1;
        if( (Child!=N-1) && (A[Child]<A[Child+1]) )
            Child++;  /* Child指向左右子结点的较大者 */
        if( X >= A[Child] ) break; /* 找到了合适位置 */
        else  /* 下滤X */
            A[Parent] = A[Child];
    }
    A[Parent] = X;
}
 
void HeapSort( ElementType A[], int N ) 
{ /* 堆排序 */
     int i;
       
     for ( i=N/2-1; i>=0; i-- )/* 建立最大堆 */
         PercDown( A, i, N );
      
     for ( i=N-1; i>0; i-- ) {
         /* 删除最大堆顶 */
         Swap( &A[0], &A[i] ); /* 见代码7.1 */
         PercDown( A, 0, i );
     }
}


/* 归并排序 */
void Merge( ElementType A[], ElementType TmpA[], int L, int R, int RightEnd)
{
    /* L左起始位置， R右起始位置， RightEnd右边终点位置 */
    int LeftEnd = R - 1; 
    int Tmp = L;/* 存放结果的数组的初始位置 */
    int NumElements = RightEnd-L+1;
    int i;
    while( L <= LeftEnd && R<=RightEnd ){
        if(A[L]<=A[R])
            TmpA[Tmp++] = A[L++];
        else
            TmpA[Tmp++] = A[R++];
    }
    while( L<=LeftEnd )
        TmpA[Tmp++] = A[L++];
    while( R<= RightEnd )
        TmpA[Tmp++] = A[R++];
    for( i = 0; i < NumElements; i++, RightEnd -- )
        A[RightEnd] = TmpA[RightEnd]; 
}





