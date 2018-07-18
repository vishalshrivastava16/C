#include <stdio.h>
#include <stdlib.h>


/* 兄弟-儿子表示法 */
typedef struct tree{
    int value;
    struct tree *FirstChild;    //下一个儿子
    struct tree *FirstSibing;   //下一个兄弟
}   Tree;
