#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main() {
    // Stack s;
    // push(s, 1);
    // push(s, 2);
    // int data = pop(s);
    // printf("%d", data);

    int *ptr;
    int test = 10;
    ptr = &test;
    printf("角力 蔼: %d, 林家 蔼: %x ", *ptr, ptr);
    printf("促澜 林家: %x", ++ptr);
}