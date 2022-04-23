/**
 * @file conversions.c
 * 
 * Este ficheiro contêm o conteúdo das funções de operações relacionadas com conversões de tipos.
 * 
 */

#include "conversions.h"

#include <stdio.h>
#include <string.h>

/**
 *
 * Esta é a função que executa a operação i, dada a stack e caso o token seja "i".
 * 
 */
bool i_command (STACK *s, char *token) {
    if (strcmp(token, "i") == 0) {
        if (s->stack[s->sp].type == 2) {
            char str[30];
            double x = pop(s).elem.DOUBLE;
            long int y = (long int)x;
            sprintf(str, "%ld", y);
            push(s, create_data(str));
        }
        if (s->stack[s->sp].type == 3) {
            char str[30];
            char x = pop(s).elem.CHAR;
            sprintf(str, "%i", x);
            push(s, create_data(str));
        }
        return true;
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação f, dada a stack e caso o token seja "f".
 * 
 */
bool f_command (STACK *s, char *token) {
    if (strcmp(token, "f") == 0) {
        if (s->stack[s->sp].type == 1) {
            char str[30];
            double x = (double)pop(s).elem.LONG;
            sprintf(str, "%f", x);
            push(s, create_data(str));
        }
        if (s->stack[s->sp].type == 3) {
            char str[30];
            char x = pop(s).elem.CHAR;
            sprintf(str, "%f", (double)x);
            push(s, create_data(str));
        }
    return true;
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação c, dada a stack e caso o token seja "c".
 * 
 */
bool c_command (STACK *s, char *token) {
    if (strcmp(token, "c") == 0) {
        int x = pop(s).elem.LONG;
        char str[2];
        str[0] = x;
        str[1] = '\0';
        push(s, create_data(str));
        return true;
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação s, dada a stack e caso o token seja "s".
 * 
 */
bool s_command (STACK *s, char *token) {
    if (strcmp(token, "s") == 0) {
        if (s->stack[s->sp].type == 1) {
            long int x = pop(s).elem.LONG;
            char str[30];
            sprintf(str, "%ld", x);
            push(s, create_data(str));
        }
        if (s->stack[s->sp].type == 2) {
            double x = pop(s).elem.DOUBLE;
            char str[30];
            sprintf(str, "%g", x);
            push(s, create_data(str));
        }
        if (s->stack[s->sp].type == 3) {
            char x = pop(s).elem.CHAR;
            char str[2];
            str[0] = x;
            str[1] = '\0';
            push(s, create_data(str));
        }
    return true;
    }
    return false;
}