#include <stdio.h>
#include <stdlib.h>
// implements a linked list that holds integer values

typedef struct _int_list_node {

    int value;
    struct _int_list_node *next;
    struct _int_list_node *prev;
} int_list_node;

int_list_node *create_int_list_node(int val) {
    int_list_node *new = (int_list_node *)malloc(sizeof(int_list_node));

    new->value = val;
    new->next = NULL;
    new->prev = NULL;

    return new;
}

int extend_int_list_front(int_list_node **list_front, int_list_node *node) {
    if (node == NULL || list_front == NULL) {
        return -1;
    }

    if (*list_front == NULL) {
        node->next = NULL;
        node->prev = NULL;
        *list_front = node;
        return 1;
    }

    node->next = *list_front;
    (*list_front)->prev = node;
    *list_front = node;

    return 0;
}

int extend_int_list_rear(int_list_node **list_front, int_list_node *node) {

    if (node == NULL || list_front == NULL) {
        return -1;
    }

    if (*list_front == NULL) {
        node->next = NULL;
        node->prev = NULL;
        *list_front = node;
        return 1;
    }
    int_list_node *trav = *list_front;
    while (trav->next != NULL) {
        trav = trav->next;
    }

    trav->next = node;
    node->prev = trav;
    node->next = NULL;

    return 0;
}

int insert_int_list_middle(int_list_node **list_front, int_list_node *node,
                           int pos) {

    if (pos <= 0 || list_front == NULL || node == NULL) {
        return -1;
    }

    if (*list_front == NULL) {
        node->next = NULL;
        node->prev = NULL;
        *list_front = node;
        return 1;
    }

    int_list_node *trav = *list_front;
    for (int i = 0; i < pos; i++) {
        if (trav->next == NULL) {
            return -1;
        };
        trav = trav->next;
    }
    int_list_node *prev = trav->prev;
    node->prev = prev;
    prev->next = node;

    trav->prev = node;
    node->next = trav;
    return 0;
}

int print_int_list(int_list_node *list_front) {

    if (list_front == NULL) {
        return -1;
    }

    printf("%d ", list_front->value);

    if (list_front->next == NULL) {
        printf("\n"); // Add a newline at the very end of the list
        return 0;
    }

    return print_int_list(list_front->next);
}

int delete_int_list(int_list_node **list_front) {
    if (list_front == NULL) {
        return -1;
    }

    if ((*list_front)->next == NULL) {
        free(*list_front);
        return 0;
    }
    int out = delete_int_list(&((*list_front)->next));
    free(*list_front);
    *list_front = NULL;
    return out;
}

int get_length_int_list(int_list_node *list_front) {
    if (list_front == NULL) {
        return 0;
    }

    int count = 1;
    int_list_node *trav = list_front;
    while (trav->next != NULL) {
        count++;
        trav = trav->next;
    }

    return count;
}
