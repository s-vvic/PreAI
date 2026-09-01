#include <stdio.h>
#include "stack.h"

int main() {
    Stack s;
    init(&s);
    push(&s, 1);
    push(&s, 2);
    int data = pop(&s);
    printf("%d \n", data);
}