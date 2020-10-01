#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
void transerverse(struct Node *ptr); //transverserse function protocalling
struct Node * insertAtFirst(struct Node *ptr, int element); //Inserting at first function protocalling
struct Node * insertAtIndex(struct Node *ptr, int element, int index); //Inserting the node at index function protocalling
struct Node * insertAtLast(struct Node *ptr, int element); //Inserting at last function protocalling
struct Node * insertAfterNode(struct Node *ptr, struct Node *prevNode, int element); //Inserting node after a given node function protocalling


void transerverse(struct Node *ptr) //transverserse function defination
{
    while(ptr != NULL)
    {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node * insertAtFirst(struct Node *ptr, int element) //Inserting at first function defination
{
    struct Node * node =  (struct Node*)malloc(sizeof(struct Node));
    node->data = element;
    node->next = ptr;
    return node;
}

struct Node * insertAtIndex(struct Node *ptr, int element, int index)  //Inserting the node at index function defination
{
    struct Node * node = (struct Node *)malloc(sizeof(struct Node));
    struct Node * p = ptr; //because we don't want to losse the head we will return the same
    int i =0;
    while(i != index-1)
    {
        p = p->next;
        i++;
    }
    node->data = element;
    node->next = p->next;
    p->next = node;
    return ptr;
}

struct Node * insertAtLast(struct Node *ptr, int element)
{
    struct Node * node = (struct Node*)malloc(sizeof(struct Node));
    struct Node * p = ptr;
    while(p->next!=NULL)
    {
        p = (p->next);
    }
    node->data = element;
    p->next = node;
    node->next = NULL;
    return ptr;
}

struct Node * insertAfterNode(struct Node *ptr, struct Node *prevNode, int element) ////Inserting node after a given node function defination
{
    struct Node * node = (struct Node*)malloc(sizeof(struct Node));

    node->data = element;
    node->next = prevNode->next;
    prevNode->next = node;
    return ptr;

}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    //linking 1 and 2
    head->data = 7;
    head->next = second;

    //linking 2 and 3
    second->data = 8;
    second->next = third;

    //linking 3 and 4
    third->data = 9;
    third->next = fourth;

    //initializing 4th one
    fourth->data = 10;
    fourth->next = NULL;
    printf("Elements of linked list\n");
    transerverse(head); //transverserse function calling

    int index = 2;
    head = insertAtFirst(head, 78); //Inserting at first function calling
    printf("\n\n");

    printf("Elements of linked list after inserting at start of linked list\n");
    transerverse(head); //transverserse function calling


    head = insertAtIndex(head, 56, index);  //Inserting the node at index function calling
    printf("\nElements of linked list after inserting at index %d of linked list\n", index);
    transerverse(head); //transverserse function calling


    head = insertAtLast(head, 145);
    printf("\nElements of linked list after inserting at the last of linked list\n");
    transerverse(head); //transverserse function calling


    head = insertAfterNode(head, third, 552); ////Inserting node after a given node function calling
    printf("\nElements of linked list after inserting ater a node which is known to us linked list\nHere we are passing the third node\n");
    transerverse(head); //transverserse function calling
    return 0;
}
