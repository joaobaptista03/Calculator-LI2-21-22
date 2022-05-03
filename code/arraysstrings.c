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
 * Esta é a função que executa a operação "", dada a stack e caso os tokens sejam " "" ".
 * 
 * A operação "" cria uma String
 * 
 */
bool conc_strings (STACK *s, char *token) {
    if (strcmp (token, "+") == 0) {        
        DATA dx = s->stack[s->sp];
        DATA dy = s->stack[s->sp-1];
        
        if (dx.type == STRING && dy.type == STRING) {
            
            return true;
        }
    }
    return false;
}