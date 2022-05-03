/**
 * @file arraysstrings.c
 * 
 * Este ficheiro contém o conteúdo das funções de operações relacionadas com arrays.
 * 
 */

#include "arraysstrings.h"

#include <string.h>
#include <stdio.h>

/**
 *
 * Esta é a função que executa a operação +, dada a stack e caso o token seja +.
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
            
            int j = 0;
            int i = 0;

            int len_x = strlen(dx.elem.STRING);
            int len_y = strlen(dy.elem.STRING);

            char new_string[len_x + len_y + 1];

            while(i < len_y) {
                new_string[i] = dy.elem.STRING[i];
                i++;
            }
            for(i = len_y; j < len_x; i++) {
                new_string[i] = dx.elem.STRING[j];
                j++;
            }

            new_string[len_x + len_y] = '\0';

            push(s, create_data(new_string, STRING));

            return true;
        }
    }
    return false;
}