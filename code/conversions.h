/**
 * @file conversions.h
 * 
 * Este ficheiro contêm as assinaturas das funções de operações relacionadas com conversões de tipos.
 * 
 */

#ifndef CONVERTIONS_H
#define CONVERTIONS_H

#include "stack.h"

#include <stdbool.h>

/**
 *
 * Este é o header da função que executa a operação i, dada a stack e caso o token seja "i".
 * 
 */
bool i_command (STACK *s, char *token);

/**
 *
 * Este é o header da função que executa a operação f, dada a stack e caso o token seja "f".
 * 
 */
bool f_command (STACK *s, char *token);

/**
 *
 * Este é o header da função que executa a operação c, dada a stack e caso o token seja "c".
 * 
 */
bool c_command (STACK *s, char *token);

/**
 *
 * Este é o header da função que executa a operação s, dada a stack e caso o token seja "s".
 * 
 */
bool s_command (STACK *s, char *token);

/**
 *
 * String que irá ser útil para guardar elementos.
 * 
 */
char elem[30];

#endif