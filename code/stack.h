/**
 * @file stack.h
 * 
 * Este ficheiro contêm as assinaturas das funções relacionadas com a stack.
 * 
 */

#ifndef STACK_H
#define STACK_H

/**
 *
 * Este typedef enumera o tipo inserido, long corresponde a 1, double a 2, char a 3 e string a 4 : 
 * 
 */
typedef enum {
    LONG = 1,
    DOUBLE = 2,
    CHAR = 3,
    STRING = 4,
} TYPE ;

/**
 *
 * Este typedef struct corresponde aos elementos da array da stack, sendo que cada struct contém a informação
 * do tipo desse elemento da stack e uma union com o próprio elemento: 
 * 
 */
typedef struct data {
    TYPE type;

    union elem {
        long LONG;
        double DOUBLE;
        char CHAR;
        char* STRING;
    } elem;
} DATA;

/**
 *
 * Esta struct define o que é uma STACK : 
 * 
 */
typedef struct stack {
    DATA stack [1000];
    int sp; /**<SP: Um apontador para o último elmento da stack*/
} STACK;

/**
 *
 * Este é o header da função que cria uma nova stack, dado um tamanho para essa stack.
 * 
 */
STACK *new_stack(int size);

/**
 *
 * Este é o header da função que adiciona algo à stack, dado uma stack e um elemento.
 * 
 */
void push(STACK *s, DATA elem);

/**
 *
 * Este é o header da função que retira o último elemnto adicionado à stack, dada a própria stack.
 * 
 */
DATA pop (STACK *s);

/**
 *
 * Este é o header da função que decide que tipo tem o input dado, dada uma string.
 * 
 */
TYPE data_selector(char a[]);

/**
 *
 * Este é o header da função que cria a struct data, dada uma string (token).
 * 
 */
DATA create_data (char a[], TYPE t);

/**
 *
 * Este é o header da função que dá print à stack.
 * 
 */
void print_stack (STACK *s);

#endif