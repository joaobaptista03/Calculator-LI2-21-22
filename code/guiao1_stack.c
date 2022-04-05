#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "guiao1_pushstack.h"

STACK *new_stack(int size) {
    STACK *s = malloc(size * sizeof(STACK));
    s->sp = -1;
    return s;
}

bool push(STACK *s, int elem) {
    if (s->sp >= MAX_STACK) return false;
    
    (s->sp)++;
    s->stack[s->sp] = elem;
    //printf("Pushed %d to Stack.\n", elem);
    return true;
}

int pop (STACK *s) {
    if (s->sp == EPT_STACK) {
        printf("Stack is empty!\n");
        return EPT_STACK;
    };

    int r = s->stack[s->sp];
    s->sp--;
    //printf("Popped %d from Stack\n", r);
    return r;
}