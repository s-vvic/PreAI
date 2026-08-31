#include <stdlib.h>

typedef struct Stack{
    int *top;
} Stack;

void push(Stack s, int data) {
    s.top = &data;
    s.top = s.top++;
}

int pop(Stack s) {
    int data = *(s.top);
    s.top = s.top--;
    return data;
}
