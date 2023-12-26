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

int main() {
    Node* List = NULL;
    Node* MyNode = CreateNode(10);

    printf("%d\n", MyNode->Data);
}