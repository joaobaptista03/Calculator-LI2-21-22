/**
 * @file stack.h
 * 
 * Este ficheiro contêm as assinaturas das funçãos do ficheiro "stack.c" e "operations.c".
 * 
 */

#include <limits.h>
#include <stdbool.h>

/**
 *
 * Este typedef enumera o tipo inserido, long corresponde a 1, double a 2, char a 3 e string a 4 : 
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
 */
typedef struct stack {
    //int stack[1000]; /**<Stack: Uma array de inteiros*/ 
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
DATA create_data (char a[]);

/**
 *
 * Este é o header da função que dá print à stack.
 * 
 */
void print_stack (STACK *s);

/**
 *
 * Este é o header da função que dada uma string, remove todos os 0's no fim, caso seja decimal.
 * 
 */
char* delete_zeros (char *a);

/**
 *
 * Este é o header da função que executa a operação i, dada a stack e caso o token seja "i".
 * 
 */
bool i_command (STACK *s, char *token);

/**
 *
 * Este é o header da função que executa a operação f, dada a stack e caso o token seja "f".
 * 
 */
bool f_command (STACK *s, char *token);

/**
 *
 * Este é o header da função que executa a operação c, dada a stack e caso o token seja "c".
 * 
 */
bool c_command (STACK *s, char *token);

/**
 *
 * Este é o header da função que executa a operação s, dada a stack e caso o token seja "s".
 * 
 */
bool s_command (STACK *s, char *token);

/**
 *
 * Este é o header da função que executa a operação _, dada a stack e caso o token seja "_".
 * 
 */
bool dup(STACK *s, char *token);

/**
 *
 * Este é o header da função que dada uma string, devolve true caso ela tenha um ponto, caso contrário devolve false.
 * 
 */
bool point(char a[]);

/**
 *
 * Este é o header da função que executa a operação \, dada a stack e caso o token seja "\".
 * 
 */
bool exchange_command (STACK *s, char *token);

/**
 *
 * Este é o header da função que executa a operação $, dada a stack e caso o token seja "$".
 * 
 */
bool copy_command (STACK *s, char *token);

/**
 *
 * Este é o header da função que executa a operação @, dada a stack e caso o token seja "@".
 * 
 */
bool rotate_command (STACK *s, char *token);

/**
 *
 * Este é o header da função que executa a operação ;, dada a stack e caso o token seja ";".
 * 
 */
bool pop_command (STACK *s, char *token);

int count_l(char a[]);