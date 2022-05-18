#include <malloc.h>
#include <stdlib.h>

#define me99 printf_s("memerr line: %d", __LINE__); system("pause>nul"); exit(99);
#define forn(i, j, n) for(int i = j; i < n; ++i)

typedef char data_t; // ------------------------------- char

struct stack {
    int size;
    data_t* data;
    data_t top;
};

void push(struct stack* stk, data_t d);
data_t pop(struct stack* stk);
void clear(struct stack* stk);
void prntfStk(struct stack* stk);
void stkalloc(struct stack* stk);