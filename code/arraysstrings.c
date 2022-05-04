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
 * Este é o header da função que executa a operação [] para strings e arrays, dada a stack e caso os tokens sejam " [] ".
 * 
 * A operação [] cria uma array.
 * 
 */
bool create_array (char *token) {
    if (strcmp(token, "[") == 0 || strcmp(token, "]") == 0) {
        return true;
    }
    return false;
}


/**
 *
 * Esta é a função que executa a operação +, dada a stack, caso o token seja + e os tipos dos 2 elementos do topo da stack forem STRING/ARRAY.
 * 
 * A operação + concatena 2 strings ou arrays.
 * 
 */
bool conc_as (STACK *s, char *token) {
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
 * Esta é a função que executa a operação =, dada a stack, caso o token seja = e os tipos dos 2 elementos do topo da stack forem STRING/ARRAY.
 * 
 * A operação = testa se 2 strings são iguais.
 * 
 */
bool equal_as (STACK *s, char *token) {
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

/**
 *
 * Esta é a função que executa a operação *, dada a stack, caso o token seja *, o elemento do topo for LONG e o segundo for STRING/ARRAY.
 * 
 * A operação * concatena a mesma string várias vezes.
 * 
 */
bool mult_as (STACK *s, char *token) {
    if (strcmp (token, "*") == 0) {        
        DATA dx = s->stack[s->sp];
        DATA dy = s->stack[s->sp-1];

        if (dx.type == LONG && dy.type == STRING) {
            pop(s);
            pop(s);

            char *new_str = malloc((strlen(dy.elem.STRING) * dx.elem.LONG + 1) * 4);

            strcpy(new_str, dy.elem.STRING);

            for(long int i = 1; i < dx.elem.LONG; i++) {
                strcat(new_str, dy.elem.STRING);
            }
            
            push(s, create_data(new_str, STRING));
            free(new_str);
            return true;
        }
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação <, dada a stack, caso o token seja < e o tipo do elemento do topo da stack for LONG e o segundo
 * for STRING/ARRAY.
 * 
 * A operação < irá buscar X elementos/caractéres do início, e retornará 0 se o elemento do topo não for long, e o segundo for STRING/ARRAY.
 * 
 */
bool init_as (STACK *s, char *token) {
    if (strcmp (token, "<") == 0) {        
        DATA dx = s->stack[s->sp];
        DATA dy = s->stack[s->sp-1];
        
        if (dy.type == STRING) {
            pop(s);
            pop(s);
            if (dx.type == LONG) {
                char *new_arr = malloc(dx.elem.LONG * 4 + 1);
                for (int i = 0; i < dx.elem.LONG; i++) new_arr[i] = dy.elem.STRING[i];
                new_arr[dx.elem.LONG] = '\0';
                push(s, create_data(new_arr, STRING));
                free(new_arr);
            }
            else push(s, create_data("0", LONG));
            return true;
        }
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação >, dada a stack, caso o token seja > e o tipo do elemento do topo da stack for LONG e o segundo
 * for STRING/ARRAY.
 * 
 * A operação > irá buscar X elementos/caractéres do fim, e retornará 1 se o elemento do topo não for long, e o segundo for STRING/ARRAY.
 * 
 */
bool last_as (STACK *s, char *token) {
    if (strcmp (token, ">") == 0) {        
        DATA dx = s->stack[s->sp];
        DATA dy = s->stack[s->sp-1];
        
        if (dy.type == STRING) {
            pop(s);
            pop(s);
            if (dx.type == LONG) {
                int len = strlen(dy.elem.STRING), i, j = 0;
                char *new_arr = malloc(dx.elem.LONG * 4 + 1);
                for (i = len - dx.elem.LONG; i < len; i++) {
                    new_arr[j] = dy.elem.STRING[i];
                    j++;
                }
                new_arr[dx.elem.LONG] = '\0';
                push(s, create_data(new_arr, STRING));
                free(new_arr);
            }
            else push(s, create_data("1", LONG));
            return true;
        }
    }
    return false;
}