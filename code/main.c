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
#include "main.h"
#include "val_handle.h"

/**
 * Esta é a função principal do programa que:
 * 
 * Cria uma nova Stack;
 * Lê uma linha;
 * Executa as operações lidas usando as funções definidas nos outros ficheiros.  
 */
int main() {
    STACK *s = new_stack(); /** <Cria uma stack nova com um espaço para 1000 elementos */

    char token[BUFSIZ]; /** <Array (String) onde vai ser guardado cada token */
    char read_temp[30]; /** <String que guarda cada linha lida pelo comando l, sendo apagada depois */
    
    assert (fgets (line, BUFSIZ, stdin) != NULL); /** <Linha que lê o primeiro input, guardando na string line */

    l = 0; /** <Variável que conta quantos l's existem em line */
    for (int i = 0; i < count_l(line); i++) { /** <Loop que lê as l linhas */
        assert (fgets (read_temp, 30, stdin) != NULL);
        strcpy(reads[i], read_temp);
        for(unsigned int j = 0; j < strlen(read_temp); j++) { /** <Loop que apaga a string str */
            read_temp[j] = '\0';
        }
    }

    while (sscanf (line, "%s %[^\n]", token, line) == 2) { /** <Linha que, para cada token de line, chama a função handle para o mesmo */
        handle (s, token);
    }
    handle (s, token);
    print_stack(s); /** <Linha que dá print à stack */
    free(s); /** <Linha que desaloca a memória no fim do programa */
    return 0;
}



// Comando gcc (tem de estar na pasta code)
// gcc -Wall -Wextra -pedantic-errors -O2 *.c -lm