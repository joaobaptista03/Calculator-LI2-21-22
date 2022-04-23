/**
 * @file math_operations.h
 * 
 * Este ficheiro contêm as assinaturas das funções relacionadas com operações matemáticas.
 * 
 */

#ifndef MATH_OPERATIONS_H
#define MATH_OPERATIONS_H

#include "stack.h"

#include <stdbool.h>

/**
 *
 * Este é o header da função que executa a operação +, dada a stack e caso o token seja "+".
 * 
 */
bool add (STACK *s, char *token);

/**
 *
 * Este é o header da função que executa a operação -, dada a stack e caso o token seja "-".
 * 
 */
bool sub (STACK *s, char *token);

/**
 *
 * Este é o header da função que executa a operação *, dada a stack e caso o token seja "*".
 * 
 */
bool mult (STACK *s, char *token);

/**
 *
 * Este é o header da função que executa a operação /, dada a stack e caso o token seja "/".
 * 
 */
bool divi (STACK *s, char *token);

/**
 *
 * Este é o header da função que executa a operação (, dada a stack e caso o token seja "(".
 * 
 */
bool dec (STACK *s, char *token);

/**
 *
 * Este é o header da função que executa a operação ), dada a stack e caso o token seja ")".
 * 
 */
bool inc (STACK *s, char *token);

/**
 *
 * Este é o header da função que executa a operação %, dada a stack e caso o token seja "%".
 * 
 */
bool mod (STACK *s, char *token);

/**
 *
 * Este é o header da função que executa a operação #, dada a stack e caso o token seja "#".
 * 
 */
bool expo (STACK *s, char *token);

/**
 *
 * Este é o header da função que executa a operação &, dada a stack e caso o token seja "&".
 * 
 */
bool and (STACK *s, char *token);

/**
 *
 * Este é o header da função que executa a operação |, dada a stack e caso o token seja "|".
 * 
 */
bool or (STACK *s, char *token);

/**
 *
 * Este é o header da função que executa a operação ^, dada a stack e caso o token seja "^".
 * 
 */
bool xor (STACK *s, char *token);

/**
 *
 * Este é o header da função que executa a operação ~, dada a stack e caso o token seja "~".
 * 
 */
bool not (STACK *s, char *token);

#endif