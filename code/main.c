/**
 * @file main.c
 * Este ficheiro contêm a função main que é a função principal do programa.
 * 
 */

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

#include "random_funcs.h"
#include "val_handle.h"

/**
 * Esta é a função principal do programa que:
 * 
 * Cria uma nova Stack;
 * Lê uma linha;
 * Executa as operações lidas usando as funções definidas nos outros ficheiros.  
 */
int main() {
    STACK *s = new_stack(1000);
    char line[BUFSIZ];
    char token[BUFSIZ];
    int l = 0;
    assert (fgets (line, BUFSIZ, stdin) != NULL);
    DATA reads[count_l(line)];
    char str[30];
    for (int i = 0; i < count_l(line); i++) {
        assert (fgets (str, 30, stdin) != NULL);
        reads[i] = create_data(str);
        for(unsigned int j = 0; j < strlen(str); j++) {
            str[j] = '\0';
        }
    }
    while (sscanf (line, "%s %[^\n]", token, line) == 2) {
        if (strcmp(token, "l") == 0) {
            push(s, reads[l]);
            l++;
        }
            else handle (s, token);
    }
    handle (s, token);
    print_stack(s);
    free(s);
    return 0;
}



// Comando gcc (tem de estar na pasta code)
// gcc -Wall -Wextra -pedantic-errors -O2 .\stack.c .\random_funcs.c .\conversions.c .\input_output.c .\math_operations.c .\stack_manipulation.c .\val_handle.c .\main.c -lm