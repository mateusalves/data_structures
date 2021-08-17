#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

/* In C a node will probably be a struct. In Object-oriented (C++) languages a class*/
// struct node {
//     int value;
//     struct node *next;
// };
// typedef struct node node_t;

void printlist(node_t *head){
    node_t *temporary = head;
    while(temporary != NULL)
    {
        printf("%d - ", temporary->value);
        temporary = temporary->next;
    }
    printf("\n");
}

/* We usually used linked list when we dont know how many nodes we are going to need.
 * So this function create new nodes
 */
node_t *create_new_node(int value)
{
    node_t *result = malloc(sizeof(node_t));
    result->value = value;
    result->next = NULL;
    return result;
}

node_t *insert_at_head(node_t **head, node_t *node_to_insert)
{
    node_to_insert->next = *head;
    *head = node_to_insert;
    return node_to_insert;
}

void insert_after_node(node_t *node_to_insert_after, node_t *newnode)
{
    newnode->next = node_to_insert_after->next;
    node_to_insert_after->next = newnode;
}

//remove and return the first ocurrence of value
void remove_value(node_t **head, int value){
    node_t *tmp = *head;

    //check the head
    if (*head != NULL && (*head)->value == value){
        tmp = *head;
        *head = (*head)->next;
        free(tmp);
        return;
    }

    //search the rest of the list
    while (tmp != NULL){
        if (tmp->next && tmp->next->value == value){
            node_t *result = tmp->next;
            tmp->next = tmp->next->next;
            free(result);
            return ;
        }
        tmp = tmp->next;
    }
    return;
}

void remove_node (node_t **head, node_t *node_to_remove){
    if (*head == node_to_remove){
        *head = node_to_remove->next;
        return;
    } else {
        //find the previous node in the list
        node_t *temp = *head;
        while( temp != NULL && temp->next != node_to_remove)
        {
            temp = temp->next;
        }
        if (temp == NULL)
            return;
        temp->next = node_to_remove->next;
        node_to_remove->next = NULL;
    }
    return;
}

node_t *find_node(node_t *head, int value)
{
    node_t *tmp = head;
    while(tmp != NULL)
    {
        if (tmp->value == value) 
            return tmp;
        tmp = tmp->next;
    }
    return NULL;
}

// int main(){
//     /*If I need a list to grown during runtime. Allocating it to heap memory
//      *Quite inefficient due to possibly need for copying content from a place to another
//      */
//     int *values = malloc(40*sizeof(int));
//     values[2] = 45;
//     int x = values [2];
//     values = realloc(values, 20000*sizeof(int));
//     x = values[600];
//     printf("%d\n", x);
//     free(values);

//     /* With linked list we have a way to insert and delete an item of a list in any place it is
//      * (start of the list, middle or end) without a lot of copying
//      */

//     /* Linked list means I will allocate memory for each element of the list (nodes) and also give it a
//      * pointer (edges or next pointers) to the next item of the list. I also need a Head tag for mark where
//      * the list starts and Tail if I need to know where it ends
//      */

//     node_t n1, n2, n3;
//     node_t *head;

//     n1.value = 45;
//     n2.value = 8;
//     n3.value = 32;
    
//     //linkind them up
//     head = &n3;
//     n3.next = &n2;
//     n2.next = &n1;
//     n1.next = NULL; // so we know when to stop

//     printlist(head);

//     //Rearranging
//     head = &n1;
//     n3.next = NULL;
//     n2.next = &n3;
//     n1.next = &n2; 

//     printlist(head);

//     //adding a new node to the list 

//     node_t n4;
//     n4.value = 13;
//     n4.next = &n3;
//     n2.next = &n4;

//     printlist(head);

//     //removing the first node

//     head = head->next;

//     printlist(head);

//     //removing the last node

//     n4.next = NULL;
    
//     printlist(head);

//     //Now with the code most likely to be used in real situations (not knowing how many nodes)

//     // node_t *head; // Already declared
//     head = NULL;
//     node_t *tmp;

//     tmp = create_new_node(32);
//     head = tmp;
//     tmp = create_new_node(8);
//     tmp->next = head;
//     head = tmp;
//     tmp = create_new_node(34);
//     tmp->next = head;
//     head = tmp;

//     printlist(head);

//     // creating a bunch of nodes 
//     for (int i = 0; i < 25; i++)
//     {
//         tmp = create_new_node(i);
//         // tmp->next = head;
//         // head = tmp;
//         insert_at_head(&head, tmp);
//     }

//     printlist(head);

//     tmp = find_node(head, 13);
//     printf("found node with value %d\n", tmp->value);

//     insert_after_node(tmp, create_new_node(75));
    
//     printlist(head);

//     remove_node(&head, tmp);

//     printlist(head);

//     remove_node(&head, head);

//     printlist(head);

//     return 0;
// }
