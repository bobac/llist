#include <criterion/criterion.h>
#include <stdio.h>

#include "llist/llist.h"

void print_int(void *data) {
    if (data != NULL) {
        printf("data=%p, (int)(*data)=%d", data, *((int *)data));
    } else {
        printf("data=%p, (int)(*data)=*NULL", data);
    }
}

Test(LLIST_LLIST, print_list) {
    node *list = NULL;
    int data = 0;

    print_list(list, NULL);
    cr_expect(true, "just should not crash");
    print_list(list, print_int);
    cr_expect(true, "just should not crash");

    add_node(&list, &data);
    print_list(list, NULL);
    cr_expect(true, "just should not crash");
    print_list(list, print_int);
    cr_expect(true, "just should not crash");

    add_node(&list, NULL);
    print_list(list, NULL);
    cr_expect(true, "just should not crash");
    print_list(list, print_int);
    cr_expect(true, "just should not crash");

    add_node(&list, &data);
    print_list(list, NULL);
    cr_expect(true, "just should not crash");
    print_list(list, print_int);
    cr_expect(true, "just should not crash");
}

Test(LLIST_LLIST, llist_len) {
    node *list = NULL;

    cr_expect(llist_len(list) == 0, "list length should be 0");
    add_node(&list, NULL);
    cr_expect(llist_len(list) == 1, "list length should be 1");

    add_node(&list, NULL);
    cr_expect(llist_len(list) == 2, "list length should be 2");

    add_node(&list, NULL);
    cr_expect(llist_len(list) == 3, "list length should be 3");
}

Test(LLIST_LLIST, add_node) {
    node *list = NULL;
    node *current = NULL;
    int data = 0;

    cr_expect(llist_len(list) == 0, "list length should be 0");
    current = add_node(&list, &data);
    cr_expect(current != NULL, "current should not be NULL");
    cr_expect(list != NULL, "list should not be NULL");
    cr_expect(list == current, "list and current should be equal");
    cr_expect(list->prev == NULL, "list->prev should be NULL");
    cr_expect(list->next == NULL, "list->next should be NULL");
    cr_expect(current->prev == NULL, "current->prev should be NULL");
    cr_expect(current->next == NULL, "current->next should be NULL");
    cr_expect(llist_len(list) == 1, "list length should be 1");

    current = add_node(&list, NULL);
    cr_expect(current != NULL, "current should not be NULL");
    cr_expect(list != NULL, "list should not be NULL");
    cr_expect(list != current, "list and current should not be equal");
    cr_expect(list->prev == NULL, "list->prev should be NULL");
    cr_expect(list->next != NULL, "list->next should not be NULL");
    cr_expect(current->prev != NULL, "current->prev should not be NULL");
    cr_expect(current->next == NULL, "current->next should be NULL");
    cr_expect(current->prev->next == current, "previous node should point to current as it's next");
    cr_expect(llist_len(list) == 2, "list length should be 2");

    current = add_node(&list, &data);
    cr_expect(current != NULL, "current should not be NULL");
    cr_expect(list != NULL, "list should not be NULL");
    cr_expect(list != current, "list and current should not be equal");
    cr_expect(list->prev == NULL, "list->prev should be NULL");
    cr_expect(list->next != NULL, "list->next should not be NULL");
    cr_expect(current->prev != NULL, "current->prev should not be NULL");
    cr_expect(current->next == NULL, "current->next should be NULL");
    cr_expect(current->prev->next == current, "previous node should point to current as it's next");
    cr_expect(llist_len(list) == 3, "list length should be 3");

    print_list(list, print_int);
}

Test(LLIST_LLIST, insert_node) {
    node *list = NULL;
    node *current = NULL;
    int data = 0;

    cr_expect(llist_len(list) == 0, "list length should be 0");
    current = insert_node(&list, &data);
    cr_expect(current != NULL, "current should not be NULL");
    cr_expect(list != NULL, "list should not be NULL");
    cr_expect(list == current, "list and current should be equal");
    cr_expect(list->prev == NULL, "list->prev should be NULL");
    cr_expect(list->next == NULL, "list->next should be NULL");
    cr_expect(current->prev == NULL, "current->prev should be NULL");
    cr_expect(current->next == NULL, "current->next should be NULL");
    cr_expect(llist_len(list) == 1, "list length should be 1");

    current = insert_node(&list, &data);
    cr_expect(current != NULL, "current should not be NULL");
    cr_expect(list != NULL, "list should not be NULL");
    cr_expect(list == current, "list and current should be equal");
    cr_expect(list->prev == NULL, "list->prev should be NULL");
    cr_expect(list->next != NULL, "list->next should not be NULL");
    cr_expect(current->prev == NULL, "current->prev should be NULL");
    cr_expect(current->next != NULL, "current->next should not be NULL");
    cr_expect(llist_len(list) == 2, "list length should be 2");

    current = insert_node(&list, &data);
    cr_expect(current != NULL, "current should not be NULL");
    cr_expect(list != NULL, "list should not be NULL");
    cr_expect(list == current, "list and current should be equal");
    cr_expect(list->prev == NULL, "list->prev should be NULL");
    cr_expect(list->next != NULL, "list->next should not be NULL");

    cr_expect(list->next->prev == current, "list->next->prev should be equal to current");
    cr_expect(list->next->next != NULL, "list->next->next should not be NULL");

    cr_expect(current->prev == NULL, "current->prev should be NULL");
    cr_expect(current->next != NULL, "current->next should not be NULL");
    cr_expect(llist_len(list) == 3, "list length should be 3");

    print_list(list, print_int);
}