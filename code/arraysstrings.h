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
 * Este é o header da função que executa a operação + para strings e arrays, dada a stack e caso o token seja "+".
 * 
 * A operação + concatena 2 strings ou arrays.
 * 
 */
bool conc_strings (STACK *s, char *token);

#endif