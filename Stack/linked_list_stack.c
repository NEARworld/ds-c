#include "../LinkedList/singly_linked_list.h"
#include <stdlib.h>
#include <stdio.h>

// linking different c files
// gcc -c linked_list_stack.c -o linked_list_stack.o
// gcc -c ../LinkedList/singly_linked_list.c -o ../LinkedList/singly_linked_list.o
// gcc linked_list_stack.o ../LinkedList/singly_linked_list.o -o program

typedef struct tagLinkedListStack {
    int top;
    Node* Node;
} LinkedListStack;

void Push(Node** Stack, int Data) {
    Node* NewNode = (Node*)malloc(sizeof(Node));
    NewNode->Data = Data;

    if (*Stack == NULL) {
        *Stack = NewNode;
        return;
    }

    printf("%d\n", (*Stack)->Data);

    NewNode->NextNode = *Stack;
    *Stack = NewNode;
}

void Pop(Node** Stack) {
    if (*Stack == NULL) {
        printf("Empty Stack");
        return;
    }
    Node* PoppedNode = *Stack;
    *Stack = (*Stack)->NextNode;
    free(PoppedNode);
}

int main() {
    Node* list = NULL;

    Push(&list, 10);
    Push(&list, 20);
    Push(&list, 30);
    Push(&list, 40);

    Pop(&list);

    Traverse(list);
    return 0;
}