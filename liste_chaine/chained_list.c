#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct n
{
    int data;
    struct n* next;
}Node;

void print_linked_list(Node* n) {
    while (n != NULL) {
        printf("%d ", n->data);
        if (n->next != NULL) {
            printf("-> ");
        }
        n = n->next;
    }
}

void insert_after_value(Node *head, Node *insert, int value) {
    Node *n = head;
    while (n->next != NULL) {
        n = n->next;
    }
    n->next = insert;
    insert->next = NULL;
}

int sum(Node* n) {
    if (n == NULL) {
        return 0;
    } else {
        return n->data + sum(n->next);
    }
}

int power(int n, int p) {
    if (p == 0) {
        return 1;
    } else {
        return n * power(n, p-1);
    }
}

char invers_list(Node* n) {
    printf("\n");
    if (n != NULL) {
        invers_list(n->next);
        if (n->next != NULL) {
            printf("-> ");
        }
        return  printf("%d ", n->data);
    }
}

int main() {
    Node *head = malloc(sizeof(Node));
    head->data = 1;

    for (int i=2;i<5;i++) {
        Node *node = malloc(sizeof(Node));
        node->data = i;
        insert_after_value(head, node, i);
    }

    printf("%c\n", invers_list(head));
}