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


/* 归并 */
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

/* 递归归并 */
/* T(N) = T(N/2) + T(N/2) + O(N) = O(N*logN) */
void MSort( ElementType A[], ElementType TmpA[], int L, int RightEnd)
{
    int Center;
    if( L < RightEnd ){
        Center = (L + RightEnd)/2;
        MSort(A, TmpA, L, Center);
        MSort(A, TmpA, Center+1, RightEnd);
        Merge(A, TmpA, L, Center+1, RightEnd);
    }
}
/* 统一接口 */
void Merge_Sort(ElementType A[], int N)
{
    ElementType *TmpA;
    TmpA = malloc(N*sizeof(ElementType));
    if(TmpA != NULL){
        MSort(A, TmpA, 0, N-1);
        free(TmpA);
    }else{
        printf("空间不足\n");
    }
}

/* 非递归归并 */
void Merge_pass(ElementType A[], ElementType TmpA[], int N, int length)/* length:当前有序子列的长度 */
{
    int i, j;
    for(i=0; i<= N-2*length; i+= 2*length){
        Merge(A, TmpA, i, i+length, i+2*length-1); 
    if(i+length < N)/* 最后剩两个子列 */
        Merge(A, TmpA, i, i+length, N-1);
    else/* 最后只剩一个子列 */
        for(j = i; j<N; j++)
            TmpA[j] = A[j];
    }
}

void Merge_sort(ElementType A[], int N)
{
    ElementType *TmpA;
    int length = 1;
    TmpA = malloc(N*sizeof(ElementType));
    if(TmpA!=NULL){
        while(length < N){
            Merge_pass(A, TmpA, N, length);
            length *= 2;
            Merge_pass(TmpA, A, N, length);
            length *= 2;
        }
        free( TmpA );
    }else{
        printf("空间不足\n");
    }
}

/* 快速排序 */
/* 产生随机数 */
ElementType Media3(ElementType A[], int Left, int Right)
{

    int Center = (Left + Right) / 2;
    if(A[Left] > A[Center])
        Swap(&A[Left], &A[Center]);
    if(A[Left] > A[Right])
        Swap(&A[Left], &A[Right]);
    if(A[Center] > A[Right])
        Swap(&A[Center], &A[Right]);

    Swap(&A[Center], &A[Right-1]);
    return A[Right] - 1;
}
/* 核心函数 */
void Quicksort(ElementType A[], int Left, int Right)
{
    int Cutoff = 200;/* 阈值，超过阈值使用插入排序 */
    if(Cutoff <= Right-Left){
        ElementType Pivot = Media3(A, Left, Right);
        int i = Left, j = Right - 1;
        for( ; ; ){
            while( A[++i] < Pivot)  ;
            while( A[--j] > Pivot)  ;
            if( i < j)
                Swap( &A[i], &A[j]);
            else
                break;
        }
        Swap( &A[i], &A[Right-1]);
        Quicksort(A, Left, i-1);
        Quicksort(A, i+1, Right);
    }
    else
        Insertion_Sort(A+Left, Right-Left+1);
}
/* 接口 */
void Quick_Sort(ElementType A[], int N)
{
    Quicksort(A, 0, N-1);   
}

/* 表排序 */
/* 最好情况：初始即有序 */
/* 最坏情况：有N/2个环，每个环包含2个元素 */
/* T(N) = O(m*N) m为复制时间 */



/* 桶排序 */
/* 基数排序:桶排序改进版(当待排个数远大于可能值个数时)) */
/* 次位优先LSD、主位优先MSD，多关键字排序 */

/* 基数排序 - 次位优先 */
 
/* 假设元素最多有MaxDigit个关键字，基数全是同样的Radix */
#define MaxDigit 4
#define Radix 10
 
/* 桶元素结点 */
typedef struct Node *PtrToNode;
struct Node {
    int key;
    PtrToNode next;
};
 
/* 桶头结点 */
struct HeadNode {
    PtrToNode head, tail;
};
typedef struct HeadNode Bucket[Radix];
  
int GetDigit ( int X, int D )
{ /* 默认次位D=1, 主位D<=MaxDigit */
    int d, i;
     
    for (i=1; i<=D; i++) {
        d = X % Radix;
        X /= Radix;
    }
    return d;
}
 
void LSDRadixSort( ElementType A[], int N )
{ /* 基数排序 - 次位优先 */
     int D, Di, i;
     Bucket B;
     PtrToNode tmp, p, List = NULL; 
      
     for (i=0; i<Radix; i++) /* 初始化每个桶为空链表 */
         B[i].head = B[i].tail = NULL;
     for (i=0; i<N; i++) { /* 将原始序列逆序存入初始链表List */
         tmp = (PtrToNode)malloc(sizeof(struct Node));
         tmp->key = A[i];
         tmp->next = List;
         List = tmp;
     }
     /* 下面开始排序 */ 
     for (D=1; D<=MaxDigit; D++) { /* 对数据的每一位循环处理 */
         /* 下面是分配的过程 */
         p = List;
         while (p) {
             Di = GetDigit(p->key, D); /* 获得当前元素的当前位数字 */
             /* 从List中摘除 */
             tmp = p; p = p->next;
             /* 插入B[Di]号桶尾 */
             tmp->next = NULL;
             if (B[Di].head == NULL)
                 B[Di].head = B[Di].tail = tmp;
             else {
                 B[Di].tail->next = tmp;
                 B[Di].tail = tmp;
             }
         }
         /* 下面是收集的过程 */
         List = NULL; 
         for (Di=Radix-1; Di>=0; Di--) { /* 将每个桶的元素顺序收集入List */
             if (B[Di].head) { /* 如果桶不为空 */
                 /* 整桶插入List表头 */
                 B[Di].tail->next = List;
                 List = B[Di].head;
                 B[Di].head = B[Di].tail = NULL; /* 清空桶 */
             }
         }
     }
     /* 将List倒入A[]并释放空间 */
     for (i=0; i<N; i++) {
        tmp = List;
        List = List->next;
        A[i] = tmp->key;
        free(tmp);
     } 
}


/* 基数排序 - 主位优先 */
 
/* 假设元素最多有MaxDigit个关键字，基数全是同样的Radix */
 
#define MaxDigit 4
#define Radix 10
 
/* 桶元素结点 */
typedef struct Node *PtrToNode;
struct Node{
    int key;
    PtrToNode next;
};
 
/* 桶头结点 */
struct HeadNode {
    PtrToNode head, tail;
};
typedef struct HeadNode Bucket[Radix];
  
int GetDigit ( int X, int D )
{ /* 默认次位D=1, 主位D<=MaxDigit */
    int d, i;
     
    for (i=1; i<=D; i++) {
        d = X%Radix;
        X /= Radix;
    }
    return d;
}
 
void MSD( ElementType A[], int L, int R, int D )
{ /* 核心递归函数: 对A[L]...A[R]的第D位数进行排序 */
     int Di, i, j;
     Bucket B;
     PtrToNode tmp, p, List = NULL; 
     if (D==0) return; /* 递归终止条件 */
      
     for (i=0; i<Radix; i++) /* 初始化每个桶为空链表 */
         B[i].head = B[i].tail = NULL;
     for (i=L; i<=R; i++) { /* 将原始序列逆序存入初始链表List */
         tmp = (PtrToNode)malloc(sizeof(struct Node));
         tmp->key = A[i];
         tmp->next = List;
         List = tmp;
     }
     /* 下面是分配的过程 */
     p = List;
     while (p) {
         Di = GetDigit(p->key, D); /* 获得当前元素的当前位数字 */
         /* 从List中摘除 */
         tmp = p; p = p->next;
         /* 插入B[Di]号桶 */
         if (B[Di].head == NULL) B[Di].tail = tmp;
         tmp->next = B[Di].head;
         B[Di].head = tmp;
     }
     /* 下面是收集的过程 */
     i = j = L; /* i, j记录当前要处理的A[]的左右端下标 */
     for (Di=0; Di<Radix; Di++) { /* 对于每个桶 */
         if (B[Di].head) { /* 将非空的桶整桶倒入A[], 递归排序 */
             p = B[Di].head;
             while (p) {
                 tmp = p;
                 p = p->next;
                 A[j++] = tmp->key;
                 free(tmp);
             }
             /* 递归对该桶数据排序, 位数减1 */
             MSD(A, i, j-1, D-1);
             i = j; /* 为下一个桶对应的A[]左端 */
         } 
     } 
}
 
void MSDRadixSort( ElementType A[], int N )
{ /* 统一接口 */
    MSD(A, 0, N-1, MaxDigit); 
}


