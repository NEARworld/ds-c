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
        Current = (*Current).NextNode;
    }
    return Current;
}

Node* RemoveNode(Node** Head, Node* Target) {
    if (*Head == Target) {
        *Head = (*Head)->NextNode;
        return Target;
    }    

    Node* Current = *Head;
    
    while (Current != NULL && Current->NextNode != Target) {
        Current = (*Current).NextNode;
    }

    (Current)->NextNode = Target->NextNode;

    return Target;
}

int main() {
    Node* List = NULL;

    SLL_AppendNode(&List, SLL_CreateNode(10));
    SLL_AppendNode(&List, SLL_CreateNode(100));
    SLL_AppendNode(&List, SLL_CreateNode(1000));

    Node* MyNode = GetNodeAt(List, 0);

    Node* RemovedNode = RemoveNode(&List, MyNode);
    SLL_DestroyNode(RemovedNode);

    printf("Head Data: %d\n", List->Data);

    return 0;
}