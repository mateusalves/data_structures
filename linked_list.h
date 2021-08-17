#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct node {
    int value;
    struct node *next;
} node_t;

void printlist(node_t *head);
node_t *create_new_node(int value);
node_t *insert_at_head(node_t **head, node_t *node_to_insert);
void insert_after_node(node_t *node_to_insert_after, node_t *newmode);
node_t *find_node_t(node_t *head, int value);
void remove_value(node_t **head, int value);

#endif