/**
 * @file stack_manipulation.c
 * 
 * Este ficheiro contêm o conteúdo das funções relacionadas com operações de manipulação de stack.
 * 
 */

#include "stack_manipulation.h"

#include <string.h>

/**
 *
 * Esta é a função que executa a operação _, dada a stack e caso o token seja "_".
 * 
 */
bool dup_command(STACK *s, char *token) {
    if (strcmp(token, "_") == 0) {
        DATA d = pop(s);
        push(s, d);
        push(s, d);
    return true;
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação ;, dada a stack e caso o token seja ";".
 * 
 */
bool pop_command (STACK *s, char *token) {
    if (strcmp(token, ";") == 0) {
        pop(s);
        return true;
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação \, dada a stack e caso o token seja "\".
 * 
 */
bool exchange_command (STACK *s, char *token) {
    if (strcmp(token, "\\") == 0) {
        DATA x = pop(s);
        DATA y = pop(s);
        push(s, x);
        push(s, y);
        return true;
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação @, dada a stack e caso o token seja "@".
 * 
 */
bool rotate_command (STACK *s, char *token) {
    if (strcmp(token, "@") == 0) {
        DATA x = pop(s);
        DATA y = pop(s);
        DATA z = pop(s);

        push(s, y);
        push(s, x);
        push(s, z);
        return true;
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação $, dada a stack e caso o token seja "$".
 * 
 */
bool copy_command (STACK *s, char *token) {
    if (strcmp(token, "$") == 0) {
        int x = pop(s).elem.LONG;
        DATA y = s->stack[s->sp - x];
        push(s, y);
        return true;
    }
    return false;
}