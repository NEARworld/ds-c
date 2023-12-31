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
    *Stack = (ArrayStack*)malloc(sizeof(ArrayStack));
    (*Stack)->Nodes = (Node*)malloc(sizeof(Node) * Capacity); 

    (*Stack)->Top = -1;
    (*Stack)->Capacity = Capacity;
}

void PushNode(ArrayStack* Stack, int Data) {
    if (Stack->Top <Stack->Capacity - 1) {
        Stack->Top++;
        Stack->Nodes[Stack->Top].Data = Data;
    }
}

int PopNode(ArrayStack* Stack, int Position) {
    if (Stack->Top <= -1) {
        printf("Error: You cannot access the index\n");
    } else {
        Stack->Top--;
    }
    return Stack->Nodes[Position].Data;
}

int main() {
    ArrayStack* Stack = NULL;
    CreateStack(&Stack, 5);

    PushNode(Stack, 10);
    PushNode(Stack, 20);
    PushNode(Stack, 30);
    PushNode(Stack, 40);
    PushNode(Stack, 50);
    PushNode(Stack, 60);
    PushNode(Stack, 70);

    for (int i = 0; i < 7; i++) {
        printf("%d\n", PopNode(Stack, i));
    }

    printf("top: %d, capacity: %d\n", Stack->Top ,Stack->Capacity);

    return 0;
}