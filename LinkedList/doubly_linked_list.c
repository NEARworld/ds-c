#include <stdio.h>
#include <stdlib.h>

typedef struct tagNode {
    int Data;
    struct tagNode* PrevNode;
    struct tagNode* NextNode;
} Node;

Node* CreateNode(int Data) {
    Node* NewNode = (Node*)malloc(sizeof(Node));
    NewNode->Data = Data;
    NewNode->NextNode = NULL;
    NewNode->PrevNode = NULL;

    return NewNode;    
}

void AppendNode(Node** Head, Node* NewNode) {
    if (*Head == NULL) {
        *Head = NewNode;
        return;
    }

    Node* Tail = *Head;

    while(Tail->NextNode != NULL) {
        Tail = Tail->NextNode;
    }
    Tail->NextNode = NewNode;
    NewNode->PrevNode = Tail;
}

int main() {
    Node* List = NULL;

    AppendNode(&List, CreateNode(10));
    AppendNode(&List, CreateNode(100));

    printf("first: %d\n", List->NextNode->PrevNode->Data);
    printf("second: %d\n", List->NextNode->Data);
}