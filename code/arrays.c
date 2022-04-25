/**
 * @file arrays.c
 * 
 * Este ficheiro contém o conteúdo das funções de operações relacionadas com arrays.
 * 
 */

#include "arrays.h"

/**
 *
 * Esta é a função que executa a operação "", dada a stack e caso os tokens sejam " "" ".
 * 
 * A operação "" cria uma String
 * 
 */
bool make_string (STACK *s, char *token) {
    if (strcmp (token, "\"") == 0) {
        

        return true;
    }
    return false;
}