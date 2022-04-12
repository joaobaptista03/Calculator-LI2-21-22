/**
 * @file guiao1_pushstack.h
 * 
 * Este ficheiro contêm as assinaturas das funçãos do ficheiro "guiao1_stack.c" e "guiao1_operations.c".
 * 
 */

#include <limits.h>

/** 
 * As linhas seguintes definem as constantes usadas na stack:
 */
#define MAX_STACK 1000  /**<MAX_STACK é o tamanho máximo da stack */ 
#define EPT_STACK -1 /**<EPT_STACK é o stack pointer quando a stack está vazia */

/**
 *
 * Esta struct define o que é uma STACK : 
 */
typedef struct {
    int stack[MAX_STACK]; /**<Stack: Uma array de inteiros*/ 
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
bool push (STACK *s, int elem);

/**
 *
 * Este é o header da função que retira o último elemnto adicionado à stack, dada a própria stack.
 * 
 */
int pop (STACK *s);

/**
 *
 * Este é o header da função que executa a operação +, dada a stack e caso o token seja "+".
 * 
 */
bool add (STACK *s, char *token);

/**
 *
 * Este é o header da função que executa a operação *, dada a stack e caso o token seja "*".
 * 
 */
bool mult (STACK *s, char *token);

/**
 *
 * Este é o header da função que executa a operação -, dada a stack e caso o token seja "-".
 * 
 */
bool sub (STACK *s, char *token);

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
 * Este é o header da função que é utilizada para colocar os valores na stack, dada a stack e um token diferente de um token de operação.
 * 
 */
bool val (STACK *s, char *token);

/**
 *
 * Este é o header da função que executa a operação /, dada a stack e caso o token seja "/".
 * 
 */
bool divi (STACK *s, char *token);

/**
 *
 * Este é o header da função que executa a operação #, dada a stack e caso o token seja "#".
 * 
 */
bool expo (STACK *s, char *token);

/**
 *
 * Este é o header da função que executa a operação %, dada a stack e caso o token seja "%".
 * 
 */
bool mod (STACK *s, char *token);

/**
 *
 * Este é o header da função que executa a operação ^, dada a stack e caso o token seja "^".
 * 
 */
bool xor (STACK *s, char *token);

/**
 *
 * Este é o header da função que executa a operação |, dada a stack e caso o token seja "|".
 * 
 */
bool or (STACK *s, char *token);

/**
 *
 * Este é o header da função que executa a operação &, dada a stack e caso o token seja "&".
 * 
 */
bool and (STACK *s, char *token);

/**
 *
 * Este é o header da função que executa a operação ~, dada a stack e caso o token seja "~".
 * 
 */
bool not (STACK *s, char *token);

/**
 *
 * Este é o header da função que decide que operação executar, dada a stack e um token.
 * 
 */
void handle (STACK *s, char *token);