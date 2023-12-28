#include <stdio.h>
#include <stdlib.h>

typedef struct tagNode {
    int Data;
} Node;

typedef struct tagStack {
    int Capacity;
    int Top;
    Node* Nodes;
} ArrayStack;

void CreateStack(ArrayStack** Stack, int Capacity) {
    *Stack = (Node*)malloc(sizeof(ArrayStack));
    (*Stack)->Nodes = (Node*)malloc(sizeof(Node) * Capacity); 

    (*Stack)->Top = -1;
    (*Stack)->Capacity = Capacity;
}

int main() {
    ArrayStack* Stack = NULL;

    CreateStack(&Stack, 5);

    printf("top: %d, capacity: %d\n", Stack->Top ,Stack->Capacity);

    return 0;
}