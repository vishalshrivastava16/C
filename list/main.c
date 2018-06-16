#include <stdio.h>
#include <stdlib.h>
#include "NODE.h"

void add(Node **phead, int number);

int main()
{
    printf("Hello world!\n");

    Node * head = NULL;

    int number;
    do {
        scanf("%d",&number);
        if (number != -1){
            add(head, number);
        }
    }while(number!=-1);


    return 0;
}

void add(Node **phead, int number)
{
            // add to linked-list
            Node *p = (Node*)malloc(sizeof(Node));
            p->value = number;
            p->next = NULL;
            // find the last
            Node *last = *phead;
            if (last){
                while (last->next){
                    last = last->next;
                }
                // attach
                last->next = p;
            }else{
                *phead = p;
            }
}
