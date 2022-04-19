/**
 * @file stack.c
 * 
 * Este ficheiro contêm o conteúdo das funções relacionadas com a stack cujo header está no ficheiro "guiao1_pushstack.h".
 * 
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

/**
 *
 * Esta é a função que cria uma nova stack, dado um tamanho para essa stack.
 * 
 */
STACK *new_stack(int size) {
    STACK *s = malloc(size * sizeof(STACK));
    s->sp = -1;
    return s;
}

/**
 *
 * Este é a função que adiciona algo à stack, dado uma stack e um elemento.
 * 
 */
void push(STACK *s, int elem) {
    (s->sp)++;
    s->stack[s->sp] = elem;
}

/**
 *
 * Este é a função que retira o último elemnto adicionado à stack, dada a própria stack.
 * 
 */
int pop (STACK *s) {
    int r = s->stack[s->sp];
    s->sp--;
    return r;
}