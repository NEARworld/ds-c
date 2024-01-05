typedef struct tagNode
{
    int Data;
    struct tagNode* NextNode;
} Node;

Node* SLL_CreateNode(int NewData);
void SLL_DestroyNode(Node* Node);
void SLL_AppendNode(Node** Head, Node* NewNode);
Node* GetNodeAt(Node* Head, int Location);
Node* RemoveNode(Node** Head, Node* Target);
void InsertNodeAfter(Node* Current, Node* NewNode);
void Traverse(Node* Head);