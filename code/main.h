/**
 * @file main.h
 * Este ficheiro contém a informações importantes da main para outros ficheiros.
 * 
 */

#ifndef MAIN
#define MAIN

#include "stack.h"
#include "random_funcs.h"

#include <stdio.h>

int l; /** <Variável que conta quantos l's existem em line */

char line[BUFSIZ]; /** <Array (String) onde vai ser guardada cada linha de input */

char reads[1000][30]; /** <Array de DATA's que vai guardar cada elemento dado pelas linhas lidas do comando l */

#endif