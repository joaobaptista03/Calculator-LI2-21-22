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
 * Este é o header da função que executa a operação "" para strings e arrays, dada a stack e caso os tokens sejam " " ".
 * 
 * A operação "" cria uma string.
 * 
 */
bool create_string (STACK *s, char *token);

/**
 *
 * Esta é a função que executa a operação +, dada a stack, caso o token seja + e os tipos dos 2 elementos do topo da stack forem STRING/ARRAY.
 * 
 * A operação + concatena 2 strings ou arrays.
 * 
 */
bool conc_as (STACK *s, char *token);

/**
 *
 * Esta é a função que executa a operação =, dada a stack, caso o token seja = e os tipos dos 2 elementos do topo da stack forem STRING/ARRAY.
 * 
 * A operação = testa se 2 strings são iguais.
 * 
 */
bool equal_as (STACK *s, char *token);

/**
 *
 * Esta é a função que executa a operação *, dada a stack, caso o token seja *, o elemento do topo for LONG e o segundo for STRING/ARRAY.
 * 
 * A operação * concatena a mesma string várias vezes.
 * 
 */
bool mult_as (STACK *s, char *token);

/**
 *
 * Esta é a função que executa a operação <, dada a stack, caso o token seja < e o tipo do elemento do topo da stack for LONG e o segundo
 * for STRING/ARRAY.
 * 
 * A operação < irá buscar X elementos/caractéres do início, e retornará 0 se o elemento do topo não for long, e o segundo for STRING/ARRAY.
 * 
 */
bool init_as (STACK *s, char *token);

/**
 *
 * Esta é a função que executa a operação >, dada a stack, caso o token seja > e o tipo do elemento do topo da stack for LONG e o segundo
 * for STRING/ARRAY.
 * 
 * A operação > irá buscar X elementos/caractéres do fim, e retornará 1 se o elemento do topo não for long, e o segundo for STRING/ARRAY.
 * 
 */
bool last_as (STACK *s, char *token);

bool range(STACK *s, char *token);

#endif