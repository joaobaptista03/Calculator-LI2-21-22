/**
 * @file guiao1_main.c
 * Este ficheiro contêm a função main que é a função principal do programa.
 * 
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

/**
 * Esta é a função principal do programa que:
 * 
 * Cria uma nova Stack;
 * Lê uma linha;
 * Executa as operações lidas usando as funções definidas nos outros ficheiros.  
 */
int main() {
    STACK *s = new_stack(1000);
    char line[BUFSIZ];
    char token[BUFSIZ];
    if (fgets (line, BUFSIZ, stdin) != NULL) {
        while (sscanf (line, "%s %[^\n]", token, line) == 2) handle (s, token);
        handle (s, token);
        for (int i = 0; i <= s->sp; i++) printf ("%d", s->stack[i]);
        printf("\n");
    }
    free(s);
    return 0;
}

// gcc -Wall -Wextra -pedantic-errors -O2 .\operations.c .\pushstack.h .\stack.c .\main.c -lm