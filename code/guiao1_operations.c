/**
 * @file guiao1_operations.c
 * 
 * Este ficheiro contêm o conteúdo das funções relacionadas com operações cujo header está no ficheiro "guiao1_pushstack.h".
 * 
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "guiao1_pushstack.h"

/**
 *
 * Esta é a função que executa a operação +, dada a stack e caso o token seja "+".
 * 
 */
bool add (STACK *s, char *token) {
    if (strcmp(token, "+") == 0) {
        int x = pop(s);
        int y = pop(s);
        push(s, y + x);
        return true;
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação *, dada a stack e caso o token seja "*".
 * 
 */
bool mult (STACK *s, char *token) {
    if (strcmp(token, "*") == 0) {
        int x = pop(s);
        int y = pop(s);
        push(s, y * x);
        return true;
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação -, dada a stack e caso o token seja "-".
 * 
 */
bool sub (STACK *s, char *token) {
    if (strcmp(token, "-") == 0) {
        int x = pop(s);
        int y = pop(s);
        push(s, y - x);
        return true;
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação /, dada a stack e caso o token seja "/".
 * 
 */
bool divi (STACK *s, char *token) {
    if (strcmp(token, "/") == 0) {
        int x = pop(s);
        int y = pop(s);
        push(s, y / x);
        return true;
    }
    return false;
}

/**
 *
 * Esta é a função que é utilizada para colocar os valores na stack, dada a stack e um token diferente de um token de operação.
 * 
 */
bool val (STACK *s, char *token) {
    int val;
    sscanf(token, "%d", &val);
    push(s, val);
    return true;
}

/**
 *
 * Esta função que decide que operação executar, dada a stack e um token.
 * 
 */
void handle (STACK *s, char *token) {
    if (add(s, token) || mult(s, token) || sub(s, token) || divi(s, token) || val(s, token)) {};
}