#include <stdio.h>
#include <stdlib.h>

typedef struct tagNode {
    int Data;
    struct tagNode* PrevNode;
    struct tagNode* NextNode;
} Node;

void DestroyNode(Node* Node) {
    free(Node);
}

Node* CreateNode(int Data) {
    Node* NewNode = (Node*)malloc(sizeof(Node));
    NewNode->Data = Data;
    NewNode->NextNode = NULL;
    NewNode->PrevNode = NULL;

    return NewNode;    
}

Node* GetNodeAt(Node* Head, int Location) {
    Node* Current = Head;

    while(Current != NULL && (--Location) >= 0) {
        Current = Current->NextNode;
    }

    return Current;
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
    printf("Node Data at index 1: %d\n", GetNodeAt(List, 1)->Data);
}