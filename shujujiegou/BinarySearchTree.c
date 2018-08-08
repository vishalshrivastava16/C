/* 二叉搜索树：
左子树比根节点小，右子树比根节点大
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct TNode *BinTree;
typedef BinTree Position;
struct TNode{
    int Data;
    struct TNode *Left;
    struct TNode *Right;
};

Position Find(int X, BinTree BST);
Position FindMin(BinTree BST);
Position FindMax(BinTree BST);
BinTree Insert(int X, BinTree BST);
BinTree Delete(int X, BinTree BST);
Position IterFind(int X, BinTree BST);
int main()
{


    return 0;
}

Position Find(int X, BinTree BST)
{
    if(!BST) return NULL;   /* 树空，查找失败 */
    if(BST->Data < X)
        return Find(X, BST->Right);
    else if(BST->Data > X)
        return Find(X, BST->Left);
    else
        return BST;
}

Position IterFind(int X, BinTree BST)
{
    while(BST){
        if(BST->Data > X)
            BST = BST->Left;
        else if (BST->Data < X)
            BST = BST->Right;
        else
            return BST;
    }
    return NULL;
}

Position FindMax(BinTree BST)
{
    while(BST->Right)
        BST = BST->Right;
    return BST;
}

Position FindMin(BinTree BST)
{
    if(!BST) return NULL;
    if(!BST->Left)
        return BST;
    else
        return FindMin(BST->Left);
}


BinTree Insert(int X, BinTree BST)
{
    if(!BST){
        BST = malloc(sizeof(struct TNode));
        BST->Data = X;
        BST->Left = BST->Right = NULL;
    }else{
        if(BST->Data > X)
            BST->Left = Insert(X, BST->Left);
        else if (BST->Data < X)
            BST->Right = Insert(X, BST->Right);
    }
    return BST;
}
BinTree Delete(int X, BinTree BST)
{
     Position Tmp;
     if(!BST)
        printf("ERROR\n");
    else if(X<BST->Data)
        BST->Left = Delete(X, BST->Left);
    else if(X>BST->Data)
        BST->Right = Delete(X, BST->Right);
    else{   /* 找到了要删除的结点 */
        if(BST->Left && BST->Right){ /* 结点有左右两个结点 */
            Tmp = FindMin(BST->Right);
            BST->Data = Tmp->Data;
            BST->Right = Delete(BST->Data,BST->Right);
        }else{ /* 结点有一个结点或无结点 */
            Tmp = BST;
            if(!BST->Left)
                BST = BST->Right;
            else if(!BST->Right)
                BST = BST->Left;
            free(Tmp);
        }
    }
    return BST;
}