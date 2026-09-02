#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *NextNode;
    struct Node *PrevNode;
} Node;

typedef struct Stack {
    Node *top;
    int count;
} Stack;

Node *MakeNode(int data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->NextNode = NULL;
    node->PrevNode = NULL;

    return node;
}

void init(Stack *s) {
    Node *InitNode = (Node *)malloc(sizeof(Node));
    InitNode->data = ' ';
    InitNode->NextNode = NULL;
    InitNode->PrevNode = NULL;

    s->top = InitNode;
    s->count = 0;
}

void push(Stack *s, int data) {
    Node *NewNode = MakeNode(data);
    Node *PrevNode = s->top;
    
    PrevNode->NextNode = NewNode;
    NewNode->PrevNode = PrevNode;
    s->top = NewNode;
    s->count++;
}

int pop(Stack *s) {
    if (s->count == 0) {
        printf("Empty Stack");
        return -1;
    }

    int data = s->top->data;

    Node *tmp = s->top;
    s->top = tmp->PrevNode;
    free(tmp);
    s->count--;

    return data;
}
