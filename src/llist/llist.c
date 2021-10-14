#include "llist/llist.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

void print_pointer(void *data) {
    printf("data=%p", data);
}

void print_list(node *list, void print_data(void *data)) {
    int items = 0;
    node *tmp = list;
    void (*print_function)(void *data) = (void *)print_data;

    if (print_function == NULL) {
        print_function = print_pointer;
    }

    while (tmp != NULL) {
        printf("%d. node=%p, prev=%p, next=%p, ", items++, tmp, tmp->prev, tmp->next);
        print_function(tmp->data);
        printf("\n");
        tmp = tmp->next;
    }
}

int llist_len(node *list){
    int len = 0;
    node *tmp = list;
    while (tmp != NULL) {
        len++;
        tmp = tmp->next;
    }
    return len;
}

node *add_node(node **list, void *data) {
    node *tmp = *list;
    node *last = NULL;
    while (tmp != NULL) {
        last = tmp;
        tmp = tmp->next;
    }
    tmp = malloc(sizeof(node));

    if (tmp == NULL) {
        return tmp;
    }

    if (*list == NULL) {
        *list = tmp;
    }

    tmp->prev = last;
    tmp->next = NULL;
    tmp->data = data;
    
    if (last != NULL) {
        last->next = tmp;
    }
    return tmp;
}

node *insert_node(node **list, void *data) {
    node *tmp;

    tmp = malloc(sizeof(node));

    if (tmp == NULL) {
        return tmp;
    }

    if (*list == NULL) {
        //*list = tmp;
        tmp->next = NULL;
    } else {
        tmp->next = *list;
        tmp->next->prev = tmp;
    }

    *list = tmp;
    tmp->prev = NULL;
    tmp->data = data;
    return tmp;
    
}