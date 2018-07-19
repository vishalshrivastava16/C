#include <stdio.h>
#include <stdlib.h>

#define ERROR NULL
typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

Position Find( List L, ElementType X );
List Insert( List L, ElementType X, Position P );
List Delete( List L, Position P );

int main()
{
    List L;
    ElementType X;
    Position P, tmp;
    int N;

    L = NULL;
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        L = Insert(L, X, L);
        if ( L==ERROR ) printf("Wrong Answer\n");
    }
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        P = Find(L, X);
        if ( P == ERROR )
            printf("Finding Error: %d is not in.\n", X);
        else {
            L = Delete(L, P);
            printf("%d is found and deleted.\n", X);
            if ( L==ERROR )
                printf("Wrong Answer or Empty List.\n");
        }
    }
    L = Insert(L, X, NULL);
    if ( L==ERROR ) printf("Wrong Answer\n");
    else
        printf("%d is inserted as the last element.\n", X);
    P = (Position)malloc(sizeof(struct LNode));
    tmp = Insert(L, X, P);
    if ( tmp!=ERROR ) printf("Wrong Answer\n");
    tmp = Delete(L, P);
    if ( tmp!=ERROR ) printf("Wrong Answer\n");
    for ( P=L; P; P = P->Next ) printf("%d ", P->Data);
    system("pause");
    return 0;
}

Position Find( List L, ElementType X ){
  while(L){
    if(L->Data == X){
      return L;
    }
    L = L->Next;
  }
  return ERROR;
}
 
List Insert( List L, ElementType X, Position P ){
  if(P == L){
    List Node = (List)malloc(sizeof(List));
    Node->Data = X;
    Node->Next = L;
    return Node;
  }
  List q = L;
  while(q){
    if(q->Next == P){
      List Node = (List)malloc(sizeof(List));
      Node->Data = X;
      Node->Next = q->Next;
      q->Next = Node;
      return L;
    }
    q = q->Next;
  }
  printf("Wrong Position for Insertion\n");
  return ERROR;
}
 
List Delete( List L, Position P ){
  if(L == P){
    return L->Next;
  }
  List q = L;
  while(q){
    if(q->Next == P){
      q->Next = q->Next->Next;
      return L;
    }
    q = q->Next;
  }
  printf("Wrong Position for Deletion\n");
  return ERROR;
}