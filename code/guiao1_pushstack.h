#include <limits.h>

#define MAX_STACK 1000
#define MIN_STACK INT_MIN
#define EPT_STACK -1

typedef struct {
    int stack[MAX_STACK];
    int sp;
} STACK;

STACK *new_stack(int size);
bool push (STACK *s, int elem);
int pop (STACK *s);
int add (STACK *s, char *token);
int mult (STACK *s, char *token);
int sub (STACK *s, char *token);
int val (STACK *s, char *token);
int divi (STACK *s, char *token);
void handle (STACK *s, char *token);