#include <stdio.h>
#include <stdlib.h>

typedef struct tagNode {
    int Data;
    struct tagNode* PrevNode;
    struct tagNode* NextNode;
} Node;

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
    NewNode->NextNode = *Head;
    (*Head)->PrevNode = NewNode;
}

Node* CreateNode(int Data) {
    Node* NewNode = (Node*)malloc(sizeof(Node));
    NewNode->Data = Data;
    NewNode->NextNode = NULL;
    NewNode->PrevNode = NULL;

    return NewNode;    
}

int main() {
    Node* List = NULL;

    AppendNode(&List, CreateNode(10));
    AppendNode(&List, CreateNode(100));

    printf("%d\n", List->NextNode->NextNode->NextNode->Data);
    printf("%d\n", List->PrevNode->PrevNode->Data);

    return 0;
}