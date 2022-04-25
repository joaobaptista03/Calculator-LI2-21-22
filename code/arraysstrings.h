/**
 * @file arraysstrings.h
 * 
 * Este ficheiro contém o conteúdo das funções de operações relacionadas com arrays.
 * 
 */

#ifndef ARRAYS_H
#define ARRAYS_H

#include "stack.h"

#include <stdbool.h>

/**
 *
 * Este é o header da função que executa a operação "", dada a stack e caso os tokens sejam " "" ".
 * 
 * A operação "" cria uma String
 * 
 */
bool make_string (STACK *s, char *token);

#endif