/**
 * @file operations.c
 * 
 * Este ficheiro contêm o conteúdo das funções relacionadas com operações cujo header está no ficheiro "stack.h".
 * 
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

/**
 *
 * Esta é a função que executa a operação +, dada a stack e caso o token seja "+".
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
            d = create_data(str);
        }

        if (dx.type == 2 && dy.type == 2) {
            sprintf(str, "%f", dx.elem.DOUBLE + dy.elem.DOUBLE); 
            d = create_data(str);
        }

        if (dx.type == 1 && dy.type == 2) {
            sprintf(str, "%f", dx.elem.LONG + dy.elem.DOUBLE); 
            d = create_data(str);
        }

        if (dx.type == 2 && dy.type == 1) {
            sprintf(str, "%f", dx.elem.DOUBLE + dy.elem.LONG); 
            d = create_data(str);
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
 */
bool mult (STACK *s, char *token) {
    if (strcmp(token, "*") == 0) {
        char str[30];
        DATA dx = pop(s);
        DATA dy = pop(s);
        DATA d;
        
        if (dx.type == 1 && dy.type == 1) {
            sprintf(str, "%ld", dx.elem.LONG * dy.elem.LONG); 
            d = create_data(str);
        }

        if (dx.type == 2 && dy.type == 2) {
            sprintf(str, "%f", dx.elem.DOUBLE * dy.elem.DOUBLE); 
            d = create_data(str);
        }

        if (dx.type == 1 && dy.type == 2) {
            sprintf(str, "%f", dx.elem.LONG * dy.elem.DOUBLE); 
            d = create_data(str);
        }

        if (dx.type == 2 && dy.type == 1) {
            sprintf(str, "%f", dx.elem.DOUBLE * dy.elem.LONG); 
            d = create_data(str);
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
 */
bool sub (STACK *s, char *token) {
    if (strcmp(token, "-") == 0) {
        char str[30];
        DATA dx = pop(s);
        DATA dy = pop(s);
        DATA d;
        
        if (dx.type == 1 && dy.type == 1) {
            sprintf(str, "%ld", dy.elem.LONG - dx.elem.LONG); 
            d = create_data(str);
        }

        if (dx.type == 2 && dy.type == 2) {
            sprintf(str, "%f", dy.elem.DOUBLE - dx.elem.DOUBLE); 
            d = create_data(str);
        }

        if (dx.type == 1 && dy.type == 2) {
            sprintf(str, "%f", dy.elem.LONG - dx.elem.DOUBLE); 
            d = create_data(str);
        }

        if (dx.type == 2 && dy.type == 1) {
            sprintf(str, "%f", dy.elem.DOUBLE - dx.elem.LONG); 
            d = create_data(str);
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
 */
bool divi (STACK *s, char *token) {
    if (strcmp(token, "/") == 0) {
        char str[30];
        DATA dx = pop(s);
        DATA dy = pop(s);
        DATA d;

        if (dx.type == 1 && dy.type == 1) {
            sprintf(str, "%f", (double)dy.elem.LONG / (double)dx.elem.LONG); 
            d = create_data(str);
        }

        if (dx.type == 2 && dy.type == 2) {
            sprintf(str, "%f", dy.elem.DOUBLE / dx.elem.DOUBLE); 
            d = create_data(str);
        }

        if (dx.type == 1 && dy.type == 2) {
            sprintf(str, "%f", (double)dy.elem.DOUBLE / dx.elem.LONG); 
            d = create_data(str);
        }

        if (dx.type == 2 && dy.type == 1) {
            sprintf(str, "%f", dy.elem.LONG / (double)dx.elem.DOUBLE); 
            d = create_data(str);
        }

        push(s, d);
        return true;
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação #, dada a stack e caso o token seja "#".
 * 
 */
bool expo (STACK *s, char *token) {
    if (strcmp(token, "#") == 0) {
        char str[30];
        DATA dx = pop(s);
        DATA dy = pop(s);
        DATA d;

        if (dx.elem.LONG == 0) {
            push (s, create_data("1"));
            return true;
        }

        if (dx.type == 1 && dy.type == 1) {

            int y2 = dy.elem.LONG;
            for (; dx.elem.LONG > 1; dx.elem.LONG--) {
                dy.elem.LONG *= y2;
            }

            sprintf(str, "%ld", dy.elem.LONG); 
            d = create_data(str);
        }

        if (dx.type == 2 && dy.type == 2) {

            int y2 = dy.elem.DOUBLE;
            for (; dx.elem.DOUBLE > 1; dx.elem.DOUBLE--) {
                dy.elem.DOUBLE *= y2;
            }

            sprintf(str, "%f", dy.elem.DOUBLE); 
            d = create_data(str);
        }

        if (dx.type == 1 && dy.type == 2) {

            int y2 = dy.elem.DOUBLE;
            for (; dx.elem.LONG > 1; dx.elem.LONG--) {
                dy.elem.DOUBLE *= y2;
            }

            sprintf(str, "%f", dy.elem.DOUBLE); 
            d = create_data(str);
        }

        if (dx.type == 2 && dy.type == 1) {

            double yy = dy.elem.LONG;

            double y2 = yy;
            for (; dx.elem.DOUBLE > 1; dx.elem.DOUBLE--) {
                yy *= y2;
            }

            sprintf(str, "%f", yy); 
            d = create_data(str);
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
 */
bool mod (STACK *s, char *token) {
    if (strcmp(token, "%") == 0) {
        char str[30];
        DATA dx = pop(s);
        DATA dy = pop(s);
        DATA d;
        
        sprintf(str, "%ld", dy.elem.LONG % dx.elem.LONG); 
        d = create_data(str);

        push(s, d);
        return true;
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação ^, dada a stack e caso o token seja "^".
 * 
 */
bool xor (STACK *s, char *token) {
    if (strcmp(token, "^") == 0) {
        char str[30];
        DATA dx = pop(s);
        DATA dy = pop(s);
        DATA d;

        sprintf(str, "%ld", dy.elem.LONG ^ dx.elem.LONG); 
        d = create_data(str);

        push(s, d);
        return true;
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação |, dada a stack e caso o token seja "|".
 * 
 */
bool or (STACK *s, char *token) {
    if (strcmp(token, "|") == 0) {
        char str[30];
        DATA dx = pop(s);
        DATA dy = pop(s);
        DATA d;

        sprintf(str, "%ld", dy.elem.LONG | dx.elem.LONG); 
        d = create_data(str);

        push(s, d);
        return true;
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação &, dada a stack e caso o token seja "&".
 * 
 */
bool and (STACK *s, char *token) {
    if (strcmp(token, "&") == 0) {
        char str[30];
        DATA dx = pop(s);
        DATA dy = pop(s);
        DATA d;

        sprintf(str, "%ld", dy.elem.LONG & dx.elem.LONG); 
        d = create_data(str);

        push(s, d);
        return true;
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação ~, dada a stack e caso o token seja "~".
 * 
 */
bool not (STACK *s, char *token) {
    if (strcmp(token, "~") == 0) {
        char str[30];
        DATA dx = pop(s);
        DATA d;

        sprintf(str, "%ld", ~dx.elem.LONG); 
        d = create_data(str);

        push(s, d);
        return true;
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação (, dada a stack e caso o token seja "(".
 * 
 */
bool dec (STACK *s, char *token) {
    if (strcmp(token, "(") == 0) {
        char str[30];
        DATA dx = pop(s);
        DATA d;
        
        if (dx.type == 1) {
            sprintf(str, "%ld", dx.elem.LONG - 1); 
            d = create_data(str);
        }

        if (dx.type == 2) {
            sprintf(str, "%f", dx.elem.DOUBLE - 1.0); 
            d = create_data(str);
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
 */
bool inc (STACK *s, char *token) {
    if (strcmp(token, ")") == 0) {
        char str[30];
        DATA dx = pop(s);
        DATA d;
        
        if (dx.type == 1) {
            sprintf(str, "%ld", dx.elem.LONG + 1); 
            d = create_data(str);
        }

        if (dx.type == 2) {
            sprintf(str, "%f", dx.elem.DOUBLE + 1.0); 
            d = create_data(str);
        }

        push(s, d);
        return true;
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação i, dada a stack e caso o token seja "i".
 * 
 */
bool i_command (STACK *s, char *token) {
    if (strcmp(token, "i") == 0) {
        if (s->stack[s->sp].type == 2) {
            char str[30];
            double x = pop(s).elem.DOUBLE;
            long int y = (long int)x;
            sprintf(str, "%ld", y);
            push(s, create_data(str));
        }
        if (s->stack[s->sp].type == 3) {
            char str[30];
            char x = pop(s).elem.CHAR;
            sprintf(str, "%i", x);
            push(s, create_data(str));
        }
        return true;
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação f, dada a stack e caso o token seja "f".
 * 
 */
bool f_command (STACK *s, char *token) {
    if (strcmp(token, "f") == 0) {
        if (s->stack[s->sp].type == 1) {
            char str[30];
            double x = (double)pop(s).elem.LONG;
            sprintf(str, "%0.7f", x);
            push(s, create_data(str));
        }
        if (s->stack[s->sp].type == 3) {
            char str[30];
            char x = pop(s).elem.CHAR;
            sprintf(str, "%.7f", (double)x);
            push(s, create_data(str));
        }
    return true;
    }
    return false;
}

/**
 *
 * Esta é a função que é utilizada para colocar os valores na stack, dada a stack e um token diferente de um token de operação.
 * 
 */
bool val (STACK *s, char *token) {
    push(s, create_data(token));
    return true;
}

/**
 *
 * Esta função que decide que operação executar, dada a stack e um token.
 * 
 */
void handle (STACK *s, char *token) {
    if (add(s, token) || mult(s, token) || sub(s, token) || divi(s, token) || xor(s, token) || or(s, token) || and(s, token) || not(s, token) || mod(s, token) || dec(s, token) || inc (s, token) || expo (s, token) || i_command(s, token) || f_command(s, token) || val(s, token)) {};
}