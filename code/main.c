/**
 * @file main.c
 * Este ficheiro contém a função main que é a função principal do programa.
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
    STACK *s = new_stack(1000); /** <Cria uma stack nova com um espaço para 1000 elementos */

    char line[BUFSIZ]; /** <Array (String) onde vai ser guardada cada linha de input */
    char token[BUFSIZ]; /** <Array (String) onde vai ser guardado cada token */

    
    assert (fgets (line, BUFSIZ, stdin) != NULL); /** <Linha que lê o primeiro input, guardando na string line */

    DATA reads[count_l(line)]; /** <Array de DATA's que vai guardar cada elemento dado pelas linhas lidas do comando l */
    char str[30]; /** <String que guarda cada linha lida pelo comando l, sendo apagada depois */

    int l = 0; /** <Variável que conta quantos l's existem em line */
    for (int i = 0; i < count_l(line); i++) { /** <Loop que lê as l linhas */
        assert (fgets (str, 30, stdin) != NULL);
        reads[i] = create_data(str, data_selector(str));
        for(unsigned int j = 0; j < strlen(str); j++) { /** <Loop que apaga a string str */
            str[j] = '\0';
        }
    }
    while (sscanf (line, "%s %[^\n]", token, line) == 2) { /** <Linha que, para cada token de line, dá push para a stack do input correspondente
                                                                caso o token seja "l", caso contrário chama a função handle para o mesmo */
        if (strcmp(token, "l") == 0) {
            push(s, reads[l]);
            l++;
        }
            else handle (s, token);
    }
    handle (s, token);
    print_stack(s); /** <Linha que dá print à stack */
    free(s); /** <Linha que desaloca a memória no fim do programa */
    return 0;
}



// Comando gcc (tem de estar na pasta code)
// gcc -Wall -Wextra -pedantic-errors -O2 *.c -lm