/**
 * @file arraysstrings.c
 * 
 * Este ficheiro contém o conteúdo das funções de operações relacionadas com arrays.
 * 
 */

#include "arraysstrings.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/**
 *
 * Este é o header da função que executa a operação "" para strings e arrays, dada a stack e caso os tokens sejam " " ".
 * 
 * A operação "" cria uma string.
 * 
 */
bool create_string (STACK *s, char *token) {
    if (token[0] == '\"') {
        int len = strlen(token) -2;
        char str[len + 1];

        for (int i = 0; token[i+1] != '\"'; i++) {
            str[i] = token[i+1];
        }

        str[len] = '\0';

        push(s, create_data(str, STRING));
        
        return true;
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação +, dada a stack, caso o token seja + e os tipos dos 2 elementos do topo da stack forem STRING.
 * 
 * A operação + concatena 2 strings ou arrays.
 * 
 */
bool conc_strings (STACK *s, char *token) {
    if (strcmp (token, "+") == 0) {        
        DATA dx = s->stack[s->sp];
        DATA dy = s->stack[s->sp-1];
        
        if (dx.type == STRING && dy.type == STRING) {
            pop(s);
            pop(s);
            strcat(dy.elem.STRING, dx.elem.STRING);
            push(s, create_data(dy.elem.STRING, STRING));
            free(dy.elem.STRING);
            free(dx.elem.STRING);
            return true;
        }
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação =, dada a stack, caso o token seja = e os tipos dos 2 elementos do topo da stack forem STRING.
 * 
 * A operação = testa se 2 strings são iguais.
 * 
 */
bool equal_strings (STACK *s, char *token) {
    if (strcmp (token, "=") == 0) {        
        DATA dx = s->stack[s->sp];
        DATA dy = s->stack[s->sp-1];
        
        if (dx.type == STRING && dy.type == STRING) {
            pop(s);
            pop(s);
            if (dx.elem.STRING[0] != dy.elem.STRING[0]) push(s, create_data("0", LONG));
            else if (strcmp (dx.elem.STRING, dy.elem.STRING) == 0) push(s, create_data("1", LONG));
            else push(s, create_data("0", LONG));
            return true;
        }
    }
    return false;
}