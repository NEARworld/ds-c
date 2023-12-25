#include <stdio.h>
#include <stdlib.h>

typedef struct tagNode
{
    int Data;
    struct tagNode* NextNode;
} Node;

Node* SLL_CreateNode(int NewData) {
    Node* NewNode = (Node*)malloc(sizeof(Node));

    NewNode->Data = NewData;
    NewNode->NextNode = NULL;

    return NewNode;
}

void SLL_DestroyNode(Node* Node) {
    free(Node);
}

void SLL_AppendNode(Node** Head, Node* NewNode) {
    if ((*Head) == NULL) {
        *Head = NewNode;
    } else {
        Node* Tail = (*Head);
        while (Tail->NextNode != NULL) {
            Tail = Tail->NextNode;
        }
        Tail->NextNode = NewNode;
    }
}

Node* GetNodeAt(Node* Head, int Location) {
    Node* Current = Head;

    while (Current != NULL && (--Location) >= 0) {
        printf("Location: %d\n", Location);
        Current = (*Current).NextNode;
    }
    printf("here\n");
    return Current;
}

int main() {
    Node* List = NULL;

    SLL_AppendNode(&List, SLL_CreateNode(10));
    SLL_AppendNode(&List, SLL_CreateNode(100));

    printf("Data is %d\n", List->Data);
    printf("hello world!\n");
    Node* MyNode = GetNodeAt(List, 1);
    printf("MyNode: %d\n", MyNode->Data);

    return 0;
}