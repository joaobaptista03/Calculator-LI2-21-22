/**
 * @file logical_operations.h
 * 
 * Este ficheiro contêm a assinatura das funções relacionadas com operações lógicas.
 * 
 */

#ifndef LOGICAL_OPERATIONS_H
#define LOGICAL_OPERATIONS_H

#include "stack.h"

#include <stdbool.h>

/**
 *
 * Este é o header da função que executa a operação ?, dada a stack e caso o token seja "?".
 * 
 */
bool if_command (STACK *s, char *token);

/**
 *
 * Este é o header da função que executa a operação e>, dada a stack e caso o token seja "e>".
 * 
 */
bool higher2_command (STACK *s, char *token);

/**
 *
 * Este é o header da função que executa a operação e<, dada a stack e caso o token seja "e<".
 * 
 */
bool lower2_command (STACK *s, char *token);

/**
 *
 * Este é o header da função que executa a operação e|, dada a stack e caso o token seja "e|".
 * 
 */
bool or_command (STACK *s, char *token);

/**
 *
 * Este é o header da função que executa a operação e&, dada a stack e caso o token seja "e&".
 * 
 */
bool and_command (STACK *s, char *token);

/**
 *
 * Este é o header da função que executa a operação >, dada a stack e caso o token seja ">".
 * 
 */
bool higher_command (STACK *s, char *token);

/**
 *
 * Este é o header da função que executa a operação <, dada a stack e caso o token seja "<".
 * 
 */
bool lower_command (STACK *s, char *token);

/**
 *
 * Este é o header da função que executa a operação =, dada a stack e caso o token seja "=".
 * 
 */
bool equal_command (STACK *s, char *token);

/**
 *
 * Este é o header da função que executa a operação !, dada a stack e caso o token seja "!".
 * 
 */
bool no_command (STACK *s, char *token);

#endif