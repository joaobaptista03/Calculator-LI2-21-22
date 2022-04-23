/**
 * @file random_funcs.c
 * 
 * Este ficheiro contêm o conteúdo das funções aleatórias que podem ser usadas em vários assuntos.
 * 
 */

#include "random_funcs.h"

#include <string.h>

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

/**
 *
 * Este é a função que, dada uma string, calcula quantos 'l' existem nela.
 * 
 */
int count_l(char a[]) {
    int l = 0;
    for (unsigned int i = 0; i < strlen(a); i++) {
        if (a[i] == 'l') l++;
    }
    return l;
}