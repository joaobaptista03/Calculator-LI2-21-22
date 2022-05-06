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
 * Este é o header da função que executa a operação "" para strings, dada a stack e caso os tokens sejam " " ".
 * 
 * A operação "" cria uma string.
 * 
 */
bool create_string (STACK *s, char *token);

/**
 *
 * Este é o header da função que executa a operação [] para arrays, dada a stack e caso os tokens sejam " [] ".
 * 
 * A operação [] cria uma array.
 * 
 */
bool create_array (STACK *s, char *token);

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

/**
 *
 * Esta é a função que executa a operação ",", dada a stack, caso o token seja ,
 * 
 * Se o elemento do topo for CHAR, converte o mesmo para LONG.
 * Se o elemento do topo for LONG, a operação devolve para a stack uma array que contém os números de 0 até ao elemento.
 * Se o elemento do topo for STRING ou ARRAY, devolve para a stack o tamanho da mesma.
 * 
 */
bool range(STACK *s, char *token);

/**
 *
 * Esta é a função que executa a operação (, dada a stack, caso o token seja ( e o tipo do elemento do topo da stack for STRING/ARRAY.
 * 
 * A operação ( para STRINGS e ARRAYS irá retirar o primeiro elemento da mesma, dando lhe push.
 * 
 */
bool rem_init (STACK *s, char *token);

/**
 *
 * Esta é a função que executa a operação ), dada a stack, caso o token seja ) e o tipo do elemento do topo da stack for STRING/ARRAY.
 * 
 * A operação ) para STRINGS e ARRAYS irá retirar o último elemento da mesma, dando lhe push.
 * 
 */
bool rem_last (STACK *s, char *token);

#endif