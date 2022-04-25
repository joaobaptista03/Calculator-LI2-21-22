/**
 * @file stack.c
 * 
 * Este ficheiro contém o conteúdo das funções relacionadas com a stack.
 * 
 */

#include "stack.h"
#include "random_funcs.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 *
 * Esta é a função que cria uma nova stack, dado um tamanho para essa stack.
 * 
 */
STACK *new_stack(int size) {
    STACK *s = malloc(size * sizeof(STACK));

    /**As seguintes linhas de código estão a criar as DATA's referentes às variáveis A-Z**/
    s->alphabet[0] = create_data("10",1);
    s->alphabet[1] = create_data("11",1);
    s->alphabet[2] = create_data("12",1);
    s->alphabet[3] = create_data("13",1);
    s->alphabet[4] = create_data("14",1);
    s->alphabet[5] = create_data("15",1);
    s->alphabet[6] = create_data("0",1);
    s->alphabet[7] = create_data("0",1);
    s->alphabet[8] = create_data("0",1);
    s->alphabet[9] = create_data("0",1);
    s->alphabet[10] = create_data("0",1);
    s->alphabet[11] = create_data("0",1);
    s->alphabet[12] = create_data("0",1);
    s->alphabet[13] = create_data("\n",3);
    s->alphabet[14] = create_data("0",1);
    s->alphabet[15] = create_data("0",1);
    s->alphabet[16] = create_data("0",1);
    s->alphabet[17] = create_data("0",1);
    s->alphabet[18] = create_data(" ",3);
    s->alphabet[19] = create_data("0",1);
    s->alphabet[20] = create_data("0",1);
    s->alphabet[21] = create_data("0",1);
    s->alphabet[22] = create_data("0",1);
    s->alphabet[23] = create_data("0",1);
    s->alphabet[24] = create_data("1",1);
    s->alphabet[25] = create_data("2",1);

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
    if (strcmp(a,"0.0") == 0) return 2;
    char *p;
    if (strtod(a, &p) != 0) {
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
DATA create_data (char a[], TYPE t) {
    char *p;
    DATA d;
    
    if (t == 1) { 
        d.type = 1;
        d.elem.LONG = strtol(a, &p, 10);
    }

    if (t == 2) { 
        d.type = 2;
        d.elem.DOUBLE = strtod(a, &p);
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
        }
        if (s->stack[i].type == 2) {
            char str[30];
            sprintf(str, "%g", s->stack[i].elem.DOUBLE);
            printf("%s", str);
        }
        if (s->stack[i].type == 3) {
            printf("%c", s->stack[i].elem.CHAR);
        }
        if (s->stack[i].type == 4) {
            printf("%s", s->stack[i].elem.STRING);
        }
    }
    printf("\n");
}