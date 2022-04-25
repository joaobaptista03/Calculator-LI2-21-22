/**
 * @file val_handle.c
 * 
 * Este ficheiro contém o conteúdo das funções val e handle.
 * 
 */

#include "val_handle.h"

#include "random_funcs.h"
#include "math_operations.h"
#include "stack_manipulation.h"
#include "logical_operations.h"
#include "variables.h"
#include "arrays.h"
#include "conversions.h"


/**
 *
 * Esta é a função que é utilizada para colocar os valores na stack, dada a stack e um token diferente de um token de operação.
 * 
 */
bool val (STACK *s, char *token) {
    push(s, create_data(token, data_selector(token)));
    return true;
}

/**
 *
 * Esta função que decide que operação executar, dada a stack e um token.
 * 
 */
void handle (STACK *s, char *token) {
    if (
       add(s, token) || sub(s, token) || mult(s, token) || divi(s, token)
    || dec(s, token) || inc (s, token) || mod(s, token) || expo (s, token) 
    || xor(s, token) || or(s, token) || and(s, token) || not(s, token)

    || dup_command(s, token) || pop_command(s, token) || exchange_command(s, token) || rotate_command(s, token) || copy_command(s, token)

    || i_command(s, token) || f_command(s, token) || c_command(s, token) || s_command(s, token)
    
    || equal_command(s, token) || lower_command(s, token) || higher_command(s, token) || no_command(s, token)
    || and_command(s, token) || or_command(s, token) || lower2_command(s, token) || higher2_command(s, token) || if_command(s, token) 
    
    || SP_command(s, token) || V_commands(s, token)

    || make_string(s, token)
    
    || val(s, token)) {};
}