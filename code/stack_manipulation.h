/**
 * @file stack_manipulation.h
 * 
 * Este ficheiro contêm as assinaturas das funções relacionadas com operações de manipulação de stack.
 * 
 */

#ifndef STACK_MANIPULATION_H
#define STACK_MANIPULATION_H

#include "stack.h"

#include <stdbool.h>

/**
 *
 * Este é o header da função que executa a operação _, dada a stack e caso o token seja "_".
 * 
 */
bool dup_command(STACK *s, char *token);

/**
 *
 * Este é o header da função que executa a operação ;, dada a stack e caso o token seja ";".
 * 
 */
bool pop_command (STACK *s, char *token);

/**
 *
 * Este é o header da função que executa a operação \, dada a stack e caso o token seja "\".
 * 
 */
bool exchange_command (STACK *s, char *token);

/**
 *
 * Este é o header da função que executa a operação @, dada a stack e caso o token seja "@".
 * 
 */
bool rotate_command (STACK *s, char *token);

/**
 *
 * Este é o header da função que executa a operação $, dada a stack e caso o token seja "$".
 * 
 */
bool copy_command (STACK *s, char *token);

#endif