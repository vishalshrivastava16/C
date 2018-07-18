#include <stdio.h>
#include <stdlib.h>

typedef struct tree{
    int data;
    struct tree *Left;
    struct tree *Right;
} *BinTree;

typedef struct Node{
    BinTree t;
    struct Node *next;
} QNode;

typedef struct {
    QNode *front;
    QNode *rear;
} Queue;

BinTree CreatBinTree(BinTree Tree);

/* 递归遍历 */
void PreOrderTraversal(BinTree BT);
void InOrderTraversal(BinTree BT);
void PostOrderTraversal(BinTree BT);

/* 队列层序遍历 */
void LevelOrderTraversal(BinTree BT);

/* 队列 */
Queue* CreateQ();
void AddQ(Queue *Q, BinTree X);
BinTree DeleteQ(Queue *Q);




int main()
{
    /* 创建二叉树 */
    BinTree Tree;
    Tree = CreatBinTree(Tree);

    /* 遍历 */
    PreOrderTraversal(Tree);
    printf("\n");
    InOrderTraversal(Tree);
    printf("\n");
    PostOrderTraversal(Tree);
    printf("\n");

    LevelOrderTraversal(Tree);
    printf("\n");


    system("pause");
    return 0;
}

Queue* CreateQ()
{
    Queue *Q;
    Q->front = NULL;
    Q->rear = NULL;
    return Q;
}

void AddQ(Queue *Q, BinTree X)
{
    QNode *TailCell = (QNode*)malloc(sizeof(QNode));
    TailCell->t = X;
    TailCell->next = NULL;
    if(Q->front == NULL)
        Q->front = Q->rear = TailCell;
    else if(Q->rear == Q->front){
        Q->rear = TailCell;
        Q->front->next = Q->rear;
    }else{
        Q->rear->next = TailCell;
        Q->rear = Q->rear->next;
    }
}

BinTree DeleteQ(Queue *Q)
{
    if(Q->front == NULL)    return NULL;
    QNode* FrontCell;
    BinTree T;
    FrontCell = Q->front;
    T = FrontCell->t;
    if(Q->front == Q->rear)
        Q->rear = Q->front = NULL;
    else
        Q->front = Q->front->next;
    free(FrontCell);
    return T;
}

void LevelOrderTraversal(BinTree BT)
{
/*     Queue *Q = CreateQ(); */
    Queue *Q;
    Q->front = NULL;
    Q->rear = NULL;
    BinTree T;
    if(!BT) return;
    
    AddQ(Q,BT);
    while(Q->front){
        T=DeleteQ(Q);
        printf("%d\t",T->data);
        if(T->Left) AddQ(Q,T->Left);
        if(T->Right) AddQ(Q,T->Right);
    }
}


BinTree CreatBinTree(BinTree Tree)
{
    int n;
    scanf("%d",&n);
    if(n == -1)
        return Tree;
    else{
        Tree = (BinTree)malloc(sizeof(struct tree));
        Tree->Left = NULL;Tree->Right = NULL;
        Tree->data = n;
        Tree->Left = CreatBinTree(Tree->Left);
        Tree->Right = CreatBinTree(Tree->Right);
        return Tree;
    }

}

int IsEmpty(BinTree T)
{
    return T == NULL;
}

void PreOrderTraversal(BinTree T)
{
    /* 根   左子树  右子树 */
    if(T){
        printf("%d\t",T->data);
        PreOrderTraversal(T->Left);
        PreOrderTraversal(T->Right);
    }
}

void InOrderTraversal(BinTree T)
{
    /* 左子树   根  右子树 */
    if(T){
        InOrderTraversal(T->Left);
        printf("%d\t",T->data);
        InOrderTraversal(T->Right);
    }
}

void PostOrderTraversal(BinTree T)
{
    /* 左子树  右子树   根*/
    if(T){ 
        PostOrderTraversal(T->Left);
        PostOrderTraversal(T->Right);
        printf("%d\t",T->data);
    }
}