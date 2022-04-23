/**
 * @file operations.c
 * 
 * Este ficheiro contêm o conteúdo das funções relacionadas com operações cujo header está no ficheiro "stack.h".
 * 
 */

#include <stdio.h>
#include <math.h>
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
            sprintf(str, "%g", dx.elem.DOUBLE + dy.elem.DOUBLE); 
            d = create_data(str);
        }

        if (dx.type == 1 && dy.type == 2) {
            sprintf(str, "%g", dx.elem.LONG + dy.elem.DOUBLE); 
            d = create_data(str);
        }

        if (dx.type == 2 && dy.type == 1) {
            sprintf(str, "%g", dx.elem.DOUBLE + dy.elem.LONG); 
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
            sprintf(str, "%g", dx.elem.DOUBLE * dy.elem.DOUBLE); 
            d = create_data(str);
        }

        if (dx.type == 1 && dy.type == 2) {
            sprintf(str, "%g", dx.elem.LONG * dy.elem.DOUBLE); 
            d = create_data(str);
        }

        if (dx.type == 2 && dy.type == 1) {
            sprintf(str, "%g", dx.elem.DOUBLE * dy.elem.LONG); 
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
            sprintf(str, "%g", dy.elem.DOUBLE - dx.elem.DOUBLE); 
            d = create_data(str);
        }

        if (dx.type == 1 && dy.type == 2) {
            sprintf(str, "%g", dy.elem.LONG - dx.elem.DOUBLE); 
            d = create_data(str);
        }

        if (dx.type == 2 && dy.type == 1) {
            sprintf(str, "%g", dy.elem.DOUBLE - dx.elem.LONG); 
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
            sprintf(str, "%ld", dy.elem.LONG / dx.elem.LONG); 
            d = create_data(str);
        }

        if (dx.type == 2 && dy.type == 2) {
            sprintf(str, "%g", dy.elem.DOUBLE / dx.elem.DOUBLE); 
            d = create_data(str);
        }

        if (dx.type == 1 && dy.type == 2) {
            double r = dy.elem.DOUBLE / dx.elem.LONG;
            sprintf(str, "%g", r); 
            d = create_data(str);
        }

        if (dx.type == 2 && dy.type == 1) {
            double r = dy.elem.LONG / dx.elem.DOUBLE;
            sprintf(str, "%g", r); 
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

        if (dx.elem.LONG == 0 && dx.type == 1) {
            push (s, create_data("1"));
            return true;
        }

        if (dx.type == 1 && dy.type == 1) {

            long int yy = pow(dy.elem.LONG, dx.elem.LONG);

            sprintf(str, "%ld", yy); 
            d = create_data(str);
        }

        if (dx.type == 2 && dy.type == 2) {

            double yy = pow(dy.elem.DOUBLE, dx.elem.DOUBLE);
            sprintf(str, "%g", yy); 
            d = create_data(str);
        }

        if (dx.type == 1 && dy.type == 2) {
            
            double yy = pow(dy.elem.DOUBLE,(double)dx.elem.LONG);
            sprintf(str, "%g", yy); 
            d = create_data(str);
        }

        if (dx.type == 2 && dy.type == 1) {

            double yy = pow((double)dy.elem.LONG,dx.elem.DOUBLE);

            sprintf(str, "%g", yy); 
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
            sprintf(str, "%g", dx.elem.DOUBLE - 1.0); 
            d = create_data(str);
        }
        if (dx.type == 3) {
            sprintf(str, "%c", dx.elem.CHAR - 1); 
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
            sprintf(str, "%g", dx.elem.DOUBLE + 1.0); 
            d = create_data(str);
        }
        if (dx.type == 3) {
            sprintf(str, "%c", dx.elem.CHAR + 1); 
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
            sprintf(str, "%f", x);
            push(s, create_data(str));
        }
        if (s->stack[s->sp].type == 3) {
            char str[30];
            char x = pop(s).elem.CHAR;
            sprintf(str, "%f", (double)x);
            push(s, create_data(str));
        }
    return true;
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação c, dada a stack e caso o token seja "c".
 * 
 */
bool c_command (STACK *s, char *token) {
    if (strcmp(token, "c") == 0) {
        int x = pop(s).elem.LONG;
        char str[2];
        str[0] = x;
        str[1] = '\0';
        push(s, create_data(str));
        return true;
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação s, dada a stack e caso o token seja "s".
 * 
 */
bool s_command (STACK *s, char *token) {
    if (strcmp(token, "s") == 0) {
        if (s->stack[s->sp].type == 1) {
            long int x = pop(s).elem.LONG;
            char str[30];
            sprintf(str, "%ld", x);
            push(s, create_data(str));
        }
        if (s->stack[s->sp].type == 2) {
            double x = pop(s).elem.DOUBLE;
            char str[30];
            sprintf(str, "%g", x);
            push(s, create_data(str));
        }
        if (s->stack[s->sp].type == 3) {
            char x = pop(s).elem.CHAR;
            char str[2];
            str[0] = x;
            str[1] = '\0';
            push(s, create_data(str));
        }
    return true;
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação _, dada a stack e caso o token seja "_".
 * 
 */
bool dup(STACK *s, char *token) {
    if (strcmp(token, "_") == 0) {
        DATA d = pop(s);
        push(s, d);
        push(s, d);
    return true;
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação \, dada a stack e caso o token seja "\".
 * 
 */
bool exchange_command (STACK *s, char *token) {
    if (strcmp(token, "\\") == 0) {
        DATA x = pop(s);
        DATA y = pop(s);
        push(s, x);
        push(s, y);
        return true;
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação $, dada a stack e caso o token seja "$".
 * 
 */
bool copy_command (STACK *s, char *token) {
    if (strcmp(token, "$") == 0) {
        int x = pop(s).elem.LONG;
        DATA y = s->stack[s->sp - x];
        push(s, y);
        return true;
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação @, dada a stack e caso o token seja "@".
 * 
 */
bool rotate_command (STACK *s, char *token) {
    if (strcmp(token, "@") == 0) {
        DATA x = pop(s);
        DATA y = pop(s);
        DATA z = pop(s);

        push(s, y);
        push(s, x);
        push(s, z);
        return true;
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação ;, dada a stack e caso o token seja ";".
 * 
 */
bool pop_command (STACK *s, char *token) {
    if (strcmp(token, ";") == 0) {
        pop(s);
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
    if (add(s, token) || mult(s, token) || sub(s, token) || divi(s, token) || xor(s, token) || or(s, token) || and(s, token) || not(s, token) || mod(s, token) || dec(s, token) || inc (s, token) || expo (s, token) || i_command(s, token) || f_command(s, token) || c_command(s, token) || s_command(s, token) || dup(s, token) || exchange_command(s, token) || copy_command(s, token) || rotate_command(s, token) || pop_command(s, token) || val(s, token)) {};
}