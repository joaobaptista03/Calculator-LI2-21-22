#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "guiao1_pushstack.h"

int add (STACK *s, char *token) {
    if (strcmp(token, "+") == 0) {
        int x = pop(s);
        int y = pop(s);
        push(s, y + x);
        return 1;
    }
    return 0;
}

int mult (STACK *s, char *token) {
    if (strcmp(token, "*") == 0) {
        int x = pop(s);
        int y = pop(s);
        push(s, y * x);
        return 1;
    }
    return 0;
}

int sub (STACK *s, char *token) {
    if (strcmp(token, "-") == 0) {
        int x = pop(s);
        int y = pop(s);
        push(s, y - x);
        return 1;
    }
    return 0;
}

int divi (STACK *s, char *token) {
    if (strcmp(token, "/") == 0) {
        int x = pop(s);
        int y = pop(s);
        push(s, y / x);
        return 1;
    }
    return 0;
}

int val (STACK *s, char *token) {
    int val;
    sscanf(token, "%d", &val);
    push(s, val);
    return 1;
}

void handle (STACK *s, char *token) {
    if (add(s, token) || mult(s, token) || sub(s, token) || divi(s, token) || val(s, token)) {};
}

int main() {
    STACK *s = new_stack(MAX_STACK);
    char line[BUFSIZ];
    char token[BUFSIZ];
    if (fgets (line, BUFSIZ, stdin) != NULL) {
        while (sscanf (line, "%s %[^\n]", token, line) == 2) {
            handle (s, token);
        }
        handle (s, token);
        for (int i = 0; i <= s->sp; i++) printf ("%d", s->stack[i]);
        printf("\n");
    }
    free(s);
    return 0;
}