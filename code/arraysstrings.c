/**
 * @file arraysstrings.c
 * 
 * Este ficheiro contém o conteúdo das funções de operações relacionadas com arrays.
 * 
 */

#include "arraysstrings.h"
#include "val_handle.h"
#include "main.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/**
 *
 * Este é o header da função que executa a operação "" para strings, dada a stack e caso os tokens sejam " " ".
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
 * Este é o header da função que executa a operação [] para arrays, dada a stack e caso os tokens sejam " [] ".
 * 
 * A operação [] cria uma array.
 * 
 */
bool create_array (STACK *s, char *token) {
    if (strcmp(token, "[") == 0) {
        strcpy (token, "\0");
        DATA a = create_data("", ARRAY);
        char line2[BUFSIZ];
        strcpy(line2, line);
        char token2[BUFSIZ];
        
        while (sscanf (line2, "%s %[^]] %[^\n]", token2, line2, line) >= 2) {
            handle(a.elem.ARRAY, token2);
        }
        handle(a.elem.ARRAY, token2);

        push(s, a);

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
        
        if (dx.type == CHAR) {
            char x = dx.elem.CHAR;
            dx.type = STRING;
            dx.elem.STRING = malloc(8);
            dx.elem.STRING[0] = x;
            dx.elem.STRING[1] = '\0';
        }
        if (dy.type == CHAR) {
            char y = dy.elem.CHAR;
            dy.type = STRING;
            dy.elem.STRING = malloc(8);
            dy.elem.STRING[0] = y;
            dy.elem.STRING[1] = '\0';
        }

        if (dx.type == STRING && dy.type == STRING) {
            pop(s);
            pop(s);
            strcat(dy.elem.STRING, dx.elem.STRING);
            push(s, create_data(dy.elem.STRING, STRING));
            free(dy.elem.STRING);
            free(dx.elem.STRING);
            return true;
        }
        if (dx.type == ARRAY && dy.type == ARRAY) {
            pop(s);
            pop(s);
            
            int len = dx.elem.ARRAY->sp + 1 + dy.elem.ARRAY->sp + 1;
            DATA array[len];

            for (int i = 0; i < dy.elem.ARRAY->sp + 1; i++) {
                array[i] = dy.elem.ARRAY->stack[i];
            }
            int j = 0;
            for (int i = dy.elem.ARRAY->sp + 1; i < len; i++) {
                array[i] = dx.elem.ARRAY->stack[j];
                j++;
            }

            DATA arraypush = create_data("", ARRAY);
            
            for (int i = 0; i < len; i++) {
                arraypush.elem.ARRAY->stack[i] = array[i];
            }

            arraypush.elem.ARRAY->sp = len - 1;

            push(s, arraypush);

            return true;
        }
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação =, dada a stack, caso o token seja = e os tipos dos 2 elementos do topo da stack forem STRING/ARRAY e LONG.
 * 
 * A operação = irá buscar um valor por índice
 * 
 */
bool equal_as (STACK *s, char *token) {
    if (strcmp (token, "=") == 0) {        
        DATA dx = s->stack[s->sp];
        DATA dy = s->stack[s->sp-1];
        
        if (dx.type == LONG && dy.type == STRING) {
            pop(s);
            pop(s);
            char x = '\0';

            for (long int i = 0; i <= dx.elem.LONG ; i++) {
                x = dy.elem.STRING[i];
            }

            char strpush[] = {x, '\0'};

            push(s, create_data(strpush, CHAR));

            return true;
        }
        if (dx.type == LONG && dy.type == ARRAY) {
            pop(s);
            pop(s);
            DATA x = create_data("0", LONG);

            for (long int i = 0; i <= dx.elem.LONG ; i++) {
                x = dy.elem.ARRAY->stack[i];
            }

            push(s, x);

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

bool range(STACK *s, char *token) {
    if (strcmp(token, ",") == 0) {
        DATA d = pop(s);

        for (int i = 0; i < d.elem.LONG; i++) {
            char stringdata[30];
            sprintf(stringdata, "%d", i);
            push(s, create_data(stringdata, LONG));
        }

        return true;
    }
    return false;
}