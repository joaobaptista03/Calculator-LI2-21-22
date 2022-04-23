/**
 * @file stack.c
 * 
 * Este ficheiro contêm o conteúdo das funções relacionadas com a stack cujo header está no ficheiro "stack.h".
 * 
 */

#include <stdio.h>
#include <float.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "stack.h"

/**
 *
 * Esta é a função que cria uma nova stack, dado um tamanho para essa stack.
 * 
 */
STACK *new_stack(int size) {
    STACK *s = malloc(size * sizeof(STACK));
    s->sp = -1;
    return s;
}

/**
 *
 * Este é a função que adiciona algo à stack, dado uma stack e um elemento.
 * 
 */
void push(STACK *s, DATA elem) {
    (s->sp)++;
    s->stack[s->sp] = elem;
}

/**
 *
 * Este é a função que retira o último elemnto adicionado à stack, dada a própria stack.
 * 
 */
DATA pop (STACK *s) {
    DATA d = (s->stack[s->sp]);
    s->sp--;
    return d;
}

/**
 *
 * Esta é a função que decide que tipo tem o input dado, dada uma string.
 * 
 */
TYPE data_selector(char a[]) {
    if (strcmp(a,"0") == 0) return 1;
    char *p;
    if (strtof(a, &p) != 0) {
        if (point(a)) return 2;
        return 1;
    }
    if (strtol(a, &p, 10) != 0) return 1;
    if (strlen(a) == 1) return 3;
    return 4;
}

/**
 *
 * Esta é a função que cria a struct data, dada uma string (token).
 * 
 */
DATA create_data (char a[]) {
    char *p;
    TYPE t = data_selector(a);
    DATA d;
    
    if (t == 1) { 
        d.type = 1;
        d.elem.LONG = strtol(a, &p, 10);
    }

    if (t == 2) { 
        d.type = 2;
        d.elem.DOUBLE = strtof(a, &p);
    }

    if (t == 3) { 
        d.type = 3;
        d.elem.CHAR = a[0];
    }

    if (t == 4) { 
        d.type = 4;
        d.elem.STRING = a;
    }

    return d;
}

/**
 *
 * Esta é a função que dá print à stack.
 * 
 */
void print_stack (STACK *s) {
    for (int i = 0; i <= s->sp; i++) {
        if (s->stack[i].type == 1) {
            printf("%ld", s->stack[i].elem.LONG);
            //if (i != s->sp) printf(" ");
        }
        if (s->stack[i].type == 2) {
            char str[30];
            sprintf(str, "%g", s->stack[i].elem.DOUBLE);
            char str2[30]; 
            strcpy(str2, delete_zeros(str));
            printf("%s", str2);
            //if (i != s->sp) printf(" ");
        }
        if (s->stack[i].type == 3) {
            printf("%c", s->stack[i].elem.CHAR);
            //if (i != s->sp) printf(" ");
        }
        if (s->stack[i].type == 4) {
            printf("%s", s->stack[i].elem.STRING);
            //if (i != s->sp) printf(" ");
        }
    }
    printf("\n");
}

/**
 *
 * Esta é a função que dada uma string, remove todos os 0's no fim, caso seja decimal.
 * 
 */
char* delete_zeros (char a[]) {
    bool p = point(a);
    for(int i = strlen(a)-1; i > 0; i--) {
        if (a[i] == '0') a[i] = '\0';
        else if (p && a[i] == '.') {
            a[i+1] = '0';
            //printf("%s", a);
            return a;
        }
        else return a;
    }
    return 0;
}

/**
 *
 * Esta é a função que dada uma string, devolve true caso ela tenha um ponto, caso contrário devolve false.
 * 
 */
bool point(char a[]) {
    for(unsigned int i = 0; i < strlen(a); i++) {
        if (a[i] == '.') return true;
    }
    return false;
}

int count_l(char a[]) {
    int l = 0;
    for (unsigned int i = 0; i < strlen(a); i++) {
        if (a[i] == 'l') l++;
    }
    return l;
}