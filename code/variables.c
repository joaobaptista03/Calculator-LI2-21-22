/**
 * @file variables.c
 * 
 * Este ficheiro contêm o conteúdo das funções relacionadas com variáveis.
 * 
 */

#include "variables.h"

#include <string.h>

/**
 *
 * Esta é a função que executa a operação A, dada a stack e caso o token seja "A".
 * 
 */
bool A_command (STACK *s, char *token) {
    if (strcmp(token, "A") == 0) {
        push(s, create_data("10", 1));

        return true;
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação B, dada a stack e caso o token seja "B".
 * 
 */
bool B_command (STACK *s, char *token) {
    if (strcmp(token, "B") == 0) {
        push(s, create_data("11", 1));

        return true;
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação C, dada a stack e caso o token seja "C".
 * 
 */
bool C_command (STACK *s, char *token) {
    if (strcmp(token, "C") == 0) {
        push(s, create_data("12", 1));

        return true;
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação D, dada a stack e caso o token seja "D".
 * 
 */
bool D_command (STACK *s, char *token) {
    if (strcmp(token, "D") == 0) {
        push(s, create_data("13", 1));

        return true;
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação E, dada a stack e caso o token seja "E".
 * 
 */
bool E_command (STACK *s, char *token) {
    if (strcmp(token, "E") == 0) {
        push(s, create_data("14", 1));

        return true;
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação F, dada a stack e caso o token seja "F".
 * 
 */
bool F_command (STACK *s, char *token) {
    if (strcmp(token, "F") == 0) {
        push(s, create_data("15", 1));

        return true;
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação N, dada a stack e caso o token seja "N".
 * 
 */
bool N_command (STACK *s, char *token) {
    if (strcmp(token, "N") == 0) {
        push(s, create_data("\n", 3));

        return true;
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação S, dada a stack e caso o token seja "S".
 * 
 */
bool S_command (STACK *s, char *token) {
    if (strcmp(token, "S") == 0) {
        push(s, create_data(" ", 3));

        return true;
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação X, dada a stack e caso o token seja "X".
 * 
 */
bool X_command (STACK *s, char *token) {
    if (strcmp(token, "X") == 0) {
        push(s, create_data("0", 1));

        return true;
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação Y, dada a stack e caso o token seja "Y".
 * 
 */
bool Y_command (STACK *s, char *token) {
    if (strcmp(token, "Y") == 0) {
        push(s, create_data("1", 1));

        return true;
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação A, dada a stack e caso o token seja "A".
 * 
 */
bool Z_command (STACK *s, char *token) {
    if (strcmp(token, "Z") == 0) {
        push(s, create_data("2", 1));

        return true;
    }
    return false;
}

