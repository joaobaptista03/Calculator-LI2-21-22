/**
 * @file guiao1_operations.c
 * 
 * Este ficheiro contêm o conteúdo das funções relacionadas com operações cujo header está no ficheiro "guiao1_pushstack.h".
 * 
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "guiao1_pushstack.h"

/**
 *
 * Esta é a função que executa a operação +, dada a stack e caso o token seja "+".
 * 
 */
bool add (STACK *s, char *token) {
    if (strcmp(token, "+") == 0) {
        int x = pop(s);
        int y = pop(s);
        push(s, y + x);
        return true;
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação *, dada a stack e caso o token seja "*".
 * 
 */
bool mult (STACK *s, char *token) {
    if (strcmp(token, "*") == 0) {
        int x = pop(s);
        int y = pop(s);
        push(s, y * x);
        return true;
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação -, dada a stack e caso o token seja "-".
 * 
 */
bool sub (STACK *s, char *token) {
    if (strcmp(token, "-") == 0) {
        int x = pop(s);
        int y = pop(s);
        push(s, y - x);
        return true;
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação /, dada a stack e caso o token seja "/".
 * 
 */
bool divi (STACK *s, char *token) {
    if (strcmp(token, "/") == 0) {
        int x = pop(s);
        int y = pop(s);
        push(s, y / x);
        return true;
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação #, dada a stack e caso o token seja "#".
 * 
 */
bool expo (STACK *s, char *token) {
    if (strcmp(token, "#") == 0) {
        int x = pop(s); 
        int y = pop(s);

        int y2 = y;
         
        for (; x > 1; x--) {
            y *= y2;
        }

        push(s, y);
        return true;
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação %, dada a stack e caso o token seja "%".
 * 
 */
bool mod (STACK *s, char *token) {
    if (strcmp(token, "%") == 0) {
        int x = pop(s);
        int y = pop(s);
        push(s, y % x);
        return true;
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação ^, dada a stack e caso o token seja "^".
 * 
 */
bool xor (STACK *s, char *token) {
    if (strcmp(token, "^") == 0) {
        int x = pop(s);
        int y = pop(s);
        push(s, y ^ x);
        return true;
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação |, dada a stack e caso o token seja "|".
 * 
 */
bool or (STACK *s, char *token) {
    if (strcmp(token, "|") == 0) {
        int x = pop(s);
        int y = pop(s);
        push(s, y | x);
        return true;
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação &, dada a stack e caso o token seja "&".
 * 
 */
bool and (STACK *s, char *token) {
    if (strcmp(token, "&") == 0) {
        int x = pop(s);
        int y = pop(s);
        push(s, y & x);
        return true;
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação ~, dada a stack e caso o token seja "~".
 * 
 */
bool not (STACK *s, char *token) {
    if (strcmp(token, "~") == 0) {
        int x = pop(s);
        push(s, ~x);
        return true;
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação (, dada a stack e caso o token seja "(".
 * 
 */
bool dec (STACK *s, char *token) {
    if (strcmp(token, "(") == 0) {
        int x = pop(s);
        push(s, x - 1);
        return true;
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação ), dada a stack e caso o token seja ")".
 * 
 */
bool inc (STACK *s, char *token) {
    if (strcmp(token, ")") == 0) {
        int x = pop(s);
        push(s, x + 1);
        return true;
    }
    return false;
}

/**
 *
 * Esta é a função que é utilizada para colocar os valores na stack, dada a stack e um token diferente de um token de operação.
 * 
 */
bool val (STACK *s, char *token) {
    int val;
    sscanf(token, "%d", &val);
    push(s, val);
    return true;
}

/**
 *
 * Esta função que decide que operação executar, dada a stack e um token.
 * 
 */
void handle (STACK *s, char *token) {
    if (add(s, token) || mult(s, token) || sub(s, token) || divi(s, token) || xor(s, token) || or(s, token) || and(s, token) || not(s, token) || mod(s, token) || dec(s, token) || inc (s, token) || expo (s, token) || val(s, token)) {};
}