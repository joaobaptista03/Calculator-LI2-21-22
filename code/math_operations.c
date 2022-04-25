/**
 * @file math_operations.c
 * 
 * Este ficheiro contêm o conteúdo das funções relacionadas com operações matemáticas.
 * 
 */

#include "math_operations.h"

#include <stdio.h>
#include <math.h>
#include <string.h>

/**
 *
 * Esta é a função que executa a operação +, dada a stack e caso o token seja "+".
 * 
 * A operação + dá pop aos 2 elementos do topo da stack e dá push à soma dos dois.
 * 
 */
bool add (STACK *s, char *token) {
    if (strcmp(token, "+") == 0) {
        char str[30];
        DATA dx = pop(s);
        DATA dy = pop(s);
        DATA d;
        
        if (dx.type == 1 && dy.type == 1) {
            sprintf(str, "%ld", dx.elem.LONG + dy.elem.LONG); 
            d = create_data(str, 1);
        }

        if (dx.type == 2 && dy.type == 2) {
            sprintf(str, "%g", dx.elem.DOUBLE + dy.elem.DOUBLE); 
            d = create_data(str, 2);
        }

        if (dx.type == 1 && dy.type == 2) {
            sprintf(str, "%g", dx.elem.LONG + dy.elem.DOUBLE); 
            d = create_data(str, 2);
        }

        if (dx.type == 2 && dy.type == 1) {
            sprintf(str, "%g", dx.elem.DOUBLE + dy.elem.LONG); 
            d = create_data(str, 2);
        }

        push(s, d);
        return true;
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação -, dada a stack e caso o token seja "-".
 * 
 * A operação - dá pop aos 2 elementos do topo da stack e dá push à subtração do segundo pelo do topo.
 * 
 */
bool sub (STACK *s, char *token) {
    if (strcmp(token, "-") == 0) {
        char str[30];
        DATA dx = pop(s);
        DATA dy = pop(s);
        DATA d;
        
        if (dx.type == 1 && dy.type == 1) {
            sprintf(str, "%ld", dy.elem.LONG - dx.elem.LONG); 
            d = create_data(str, 1);
        }

        if (dx.type == 2 && dy.type == 2) {
            sprintf(str, "%g", dy.elem.DOUBLE - dx.elem.DOUBLE); 
            d = create_data(str, 2);
        }

        if (dx.type == 1 && dy.type == 2) {
            sprintf(str, "%g", dy.elem.LONG - dx.elem.DOUBLE); 
            d = create_data(str, 2);
        }

        if (dx.type == 2 && dy.type == 1) {
            sprintf(str, "%g", dy.elem.DOUBLE - dx.elem.LONG); 
            d = create_data(str, 2);
        }

        push(s, d);
        return true;
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação *, dada a stack e caso o token seja "*".
 * 
 * A operação * dá pop aos 2 elementos do topo da stack e dá push ao produto dos dois.
 * 
 */
bool mult (STACK *s, char *token) {
    if (strcmp(token, "*") == 0) {
        char str[30];
        DATA dx = pop(s);
        DATA dy = pop(s);
        DATA d;
        
        if (dx.type == 1 && dy.type == 1) {
            sprintf(str, "%ld", dx.elem.LONG * dy.elem.LONG); 
            d = create_data(str, 1);
        }

        if (dx.type == 2 && dy.type == 2) {
            sprintf(str, "%g", dx.elem.DOUBLE * dy.elem.DOUBLE); 
            d = create_data(str, 2);
        }

        if (dx.type == 1 && dy.type == 2) {
            sprintf(str, "%g", dx.elem.LONG * dy.elem.DOUBLE); 
            d = create_data(str, 2);
        }

        if (dx.type == 2 && dy.type == 1) {
            sprintf(str, "%g", dx.elem.DOUBLE * dy.elem.LONG); 
            d = create_data(str, 2);
        }

        push(s, d);
        return true;
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação /, dada a stack e caso o token seja "/".
 * 
 * A operação / dá pop aos 2 elementos do topo da stack e dá push ao quociente do segundo pelo do topo.
 * 
 */
bool divi (STACK *s, char *token) {
    if (strcmp(token, "/") == 0) {
        char str[30];
        DATA dx = pop(s);
        DATA dy = pop(s);
        DATA d;

        if (dx.type == 1 && dy.type == 1) {
            sprintf(str, "%ld", dy.elem.LONG / dx.elem.LONG); 
            d = create_data(str, 1);
        }

        if (dx.type == 2 && dy.type == 2) {
            sprintf(str, "%g", dy.elem.DOUBLE / dx.elem.DOUBLE); 
            d = create_data(str, 2);
        }

        if (dx.type == 1 && dy.type == 2) {
            double r = dy.elem.DOUBLE / dx.elem.LONG;
            sprintf(str, "%g", r); 
            d = create_data(str, 2);
        }

        if (dx.type == 2 && dy.type == 1) {
            double r = dy.elem.LONG / dx.elem.DOUBLE;
            sprintf(str, "%g", r); 
            d = create_data(str, 2);
        }

        push(s, d);
        return true;
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação (, dada a stack e caso o token seja "(".
 * 
 * A operação ( dá pop ao elemento do topo da stack e dá push ao próprio somado 1.
 * 
 */
bool dec (STACK *s, char *token) {
    if (strcmp(token, "(") == 0) {
        char str[30];
        DATA dx = pop(s);
        DATA d;
        
        if (dx.type == 1) {
            sprintf(str, "%ld", dx.elem.LONG - 1); 
            d = create_data(str, 1);
        }

        if (dx.type == 2) {
            sprintf(str, "%g", dx.elem.DOUBLE - 1.0); 
            d = create_data(str, 2);
        }
        if (dx.type == 3) {
            sprintf(str, "%c", dx.elem.CHAR - 1); 
            d = create_data(str, 3);
        }

        push(s, d);
        return true;
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação ), dada a stack e caso o token seja ")".
 * 
 * A operação ) dá pop ao elemento do topo da stack e dá push ao próprio subtraído 1.
 * 
 */
bool inc (STACK *s, char *token) {
    if (strcmp(token, ")") == 0) {
        char str[30];
        DATA dx = pop(s);
        DATA d;
        
        if (dx.type == 1) {
            sprintf(str, "%ld", dx.elem.LONG + 1); 
            d = create_data(str, 1);
        }

        if (dx.type == 2) {
            sprintf(str, "%g", dx.elem.DOUBLE + 1.0); 
            d = create_data(str, 2);
        }
        if (dx.type == 3) {
            sprintf(str, "%c", dx.elem.CHAR + 1); 
            d = create_data(str, 3);
        }

        push(s, d);
        return true;
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação %, dada a stack e caso o token seja "%".
 * 
 * A operação % dá pop aos 2 elementos do topo da stack e dá push ao resto da divisão do segundo pelo do topo.
 * 
 */
bool mod (STACK *s, char *token) {
    if (strcmp(token, "%") == 0) {
        char str[30];
        DATA dx = pop(s);
        DATA dy = pop(s);
        DATA d;
        
        sprintf(str, "%ld", dy.elem.LONG % dx.elem.LONG); 
        d = create_data(str, 1);

        push(s, d);
        return true;
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação #, dada a stack e caso o token seja "#".
 * 
 * A operação # dá pop aos 2 elementos do topo da stack e dá push à potência dois dois, sendo que a base é o segundo e o expoente o do topo.
 * 
 */
bool expo (STACK *s, char *token) {
    if (strcmp(token, "#") == 0) {
        char str[30];
        DATA dx = pop(s);
        DATA dy = pop(s);
        DATA d;

        if (dx.type == 1 && dy.type == 1) {

            long int yy = pow(dy.elem.LONG, dx.elem.LONG);

            sprintf(str, "%ld", yy); 
            d = create_data(str, 1);
        }

        if (dx.type == 2 && dy.type == 2) {

            double yy = pow(dy.elem.DOUBLE, dx.elem.DOUBLE);
            sprintf(str, "%g", yy); 
            d = create_data(str, 2);
        }

        if (dx.type == 1 && dy.type == 2) {
            
            double yy = pow(dy.elem.DOUBLE,(double)dx.elem.LONG);
            sprintf(str, "%g", yy); 
            d = create_data(str, 2);
        }

        if (dx.type == 2 && dy.type == 1) {

            double yy = pow((double)dy.elem.LONG,dx.elem.DOUBLE);

            sprintf(str, "%g", yy); 
            d = create_data(str, 2);
        }

        push(s, d);
        return true;
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação &, dada a stack e caso o token seja "&".
 * 
 * A operação & dá pop aos 2 elementos do topo da stack e dá push ao resultado da operação binária "and" entre os dois.
 * 
 */
bool and (STACK *s, char *token) {
    if (strcmp(token, "&") == 0) {
        char str[30];
        DATA dx = pop(s);
        DATA dy = pop(s);
        DATA d;

        sprintf(str, "%ld", dy.elem.LONG & dx.elem.LONG); 
        d = create_data(str, 1);

        push(s, d);
        return true;
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação |, dada a stack e caso o token seja "|".
 * 
 * A operação | dá pop aos 2 elementos do topo da stack e dá push ao resultado da operação binária "or" entre os dois.
 * 
 */
bool or (STACK *s, char *token) {
    if (strcmp(token, "|") == 0) {
        char str[30];
        DATA dx = pop(s);
        DATA dy = pop(s);
        DATA d;

        sprintf(str, "%ld", dy.elem.LONG | dx.elem.LONG); 
        d = create_data(str, 1);

        push(s, d);
        return true;
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação ^, dada a stack e caso o token seja "^".
 * 
 * A operação ^ dá pop aos 2 elementos do topo da stack e dá push ao resultado da operação binária "xor" entre os dois.
 * 
 */
bool xor (STACK *s, char *token) {
    if (strcmp(token, "^") == 0) {
        char str[30];
        DATA dx = pop(s);
        DATA dy = pop(s);
        DATA d;

        sprintf(str, "%ld", dy.elem.LONG ^ dx.elem.LONG); 
        d = create_data(str, 1);

        push(s, d);
        return true;
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação ~, dada a stack e caso o token seja "~".
 * 
 * A operação ~ dá pop ao elemento do topo da stack e dá push ao resultado da operação binária "not" do próprio.
 * 
 */
bool not (STACK *s, char *token) {
    if (strcmp(token, "~") == 0) {
        char str[30];
        DATA dx = pop(s);
        DATA d;

        sprintf(str, "%ld", ~dx.elem.LONG); 
        d = create_data(str, 1);

        push(s, d);
        return true;
    }
    return false;
}