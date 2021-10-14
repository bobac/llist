#include <stdio.h>
#include "llist/llist.h"
node *list = NULL;
node *current = NULL;
int data = 0;

int main(int argc, char **argv) {
    current = add_node(&list, &data);
    printf("Linked lists test list=%p\n", list);

}
