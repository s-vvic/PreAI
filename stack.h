#include <stdlib.h>

typedef struct Stack{
    int *top;
} Stack;

void push(Stack s, int data) {
    s.top = (int *)malloc(sizeof(int));
    s.top = &data;
    s.top = s.top++;
}

int pop(Stack s) {
    if (s.top == NULL) {
        return -1;
    }

    int data = *(s.top);
    s.top = s.top--;
    return data;
}

void del(Stack s) {
    
}