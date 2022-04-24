/**
 * @file variables.h
 * 
 * Este ficheiro contêm o conteúdo das funções relacionadas com variáveis.
 * 
 */

#ifndef VARIABLES_H
#define VARIABLES_H

#include "stack.h"

#include <stdbool.h> 

/**
 *
 * Este é o header da função que executa a operação A, dada a stack e caso o token seja "A".
 * 
 */
bool A_command (STACK *s, char *token);

/**
 *
 * Este é o header da função que executa a operação B, dada a stack e caso o token seja "B".
 * 
 */
bool B_command (STACK *s, char *token);

/**
 *
 * Este é o header da função que executa a operação C, dada a stack e caso o token seja "C".
 * 
 */
bool C_command (STACK *s, char *token);

/**
 *
 * Este é o header da função que executa a operação D, dada a stack e caso o token seja "D".
 * 
 */
bool D_command (STACK *s, char *token);

/**
 *
 * Este é o header da função que executa a operação E, dada a stack e caso o token seja "E".
 * 
 */
bool E_command (STACK *s, char *token);

/**
 *
 * Este é o header da função que executa a operação F, dada a stack e caso o token seja "F".
 * 
 */
bool F_command (STACK *s, char *token);

/**
 *
 * Este é o header da função que executa a operação N, dada a stack e caso o token seja "N".
 * 
 */
bool N_command (STACK *s, char *token);

/**
 *
 * Este é o header da função que executa a operação S, dada a stack e caso o token seja "S".
 * 
 */
bool S_command (STACK *s, char *token);

/**
 *
 * Este é o header da função que executa a operação X, dada a stack e caso o token seja "X".
 * 
 */
bool X_command (STACK *s, char *token);

/**
 *
 * Este é o header da função que executa a operação Y, dada a stack e caso o token seja "Y".
 * 
 */
bool Y_command (STACK *s, char *token);

/**
 *
 * Este é o header da função que executa a operação Z, dada a stack e caso o token seja "Z".
 * 
 */
bool Z_command (STACK *s, char *token);

#endif