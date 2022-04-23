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
        TYPE type = s->stack[s->sp].type;
        if (type == 2) {
            double x = pop(s).elem.DOUBLE;
            long int y = (long int)x;
            sprintf(elem, "%ld", y);
            push(s, create_data(elem));
        }
        if (type == 3) {
            char x = pop(s).elem.CHAR;
            sprintf(elem, "%i", x);
            push(s, create_data(elem));
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
        TYPE type = s->stack[s->sp].type;
        if (type == 1) {
            double x = (double)pop(s).elem.LONG;
            sprintf(elem, "%f", x);
            push(s, create_data(elem));
        }
        if (type == 3) {
            char x = pop(s).elem.CHAR;
            sprintf(elem, "%f", (double)x);
            push(s, create_data(elem));
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
        char elem2[2] = {x, '\0'};
        push(s, create_data(elem2));
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
        TYPE type = s->stack[s->sp].type;
        if (type == 1) {
            long int x = pop(s).elem.LONG;
            sprintf(elem, "%ld", x);
            push(s, create_data(elem));
        }
        if (type == 2) {
            double x = pop(s).elem.DOUBLE;
            sprintf(elem, "%g", x);
            push(s, create_data(elem));
        }
        if (type == 3) {
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