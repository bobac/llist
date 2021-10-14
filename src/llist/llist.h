#ifndef LLIST_LLIST_H
#define LLIST_LLIST_H

typedef struct node {
    void *data;
    struct node *prev;
    struct node *next;
} node;

void print_list(node *list, void print_data(void *data));
int llist_len(node *list);
node *add_node(node **list, void *data);
node *insert_node(node **list, void *data);

#endif
