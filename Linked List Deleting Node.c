#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void transerverse(struct Node *ptr)
{
    while(ptr != NULL)
    {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node * deletingFirstNode(struct Node * head)
{
    struct Node * ptr = head;
    head = head->next;
    free(ptr);
    return(head);
}

struct Node * deletingInBetweenNode(struct Node * head, int index)
{
    struct Node * ptr = head;
    int i = 0;
    while(i < index-1)
    {
        ptr = ptr->next;
        i++;
    }
    struct Node * q = ptr->next;
    ptr->next = q->next;
    free(q);
    return head;

}


struct Node * deletingLastNode(struct Node * head)
{
    struct Node * ptr = head;
    struct Node * q = ptr->next;
    while(q->next != NULL)
    {
        ptr = ptr->next;
        q = q->next;
    }
    ptr->next = NULL;
    free(q);
    return (head);
}


struct Node * deletingNodeHavingValue(struct Node * head, int value)
{
    struct Node * ptr = head;
    struct Node * q = ptr->next;
    while(q->data!=value && (q->next)!= NULL)
    {
        ptr = ptr->next;
        q = q->next;
    }
    if(q->data = value)
    {
        ptr->next = q->next;
        free(q);
    }
    return (head);
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
    transerverse(head);

    /*
    printf("\nElements after deletion of first node\n");
    head = deletingFirstNode(head);
    transerverse(head);
    */

    /*
    int index = 2;
    printf("\nElements after deletion of node at index %d\n", index);
    head = deletingInBetweenNode(head, index);
    transerverse(head);
    */

    /*
    printf("\nElements after deletion of last node\n");
    head = deletingLastNode(head);
    transerverse(head);
    */

    int value = 9;
    printf("\nElements after deletion of node having data value = %d\n", value);
    head = deletingNodeHavingValue(head, value);
    transerverse(head);

    return 0;
}
