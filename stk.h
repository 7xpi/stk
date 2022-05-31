#include <malloc.h>
#include <stdlib.h>

#define me99 printf_s("memerr\n\tfile: %s\n\tline: %d\n\n", __FILE__, __LINE__); system("pause>nul"); exit(99);
#define forn(i, j, n) for(int i = j; i < n; ++i)

typedef char data_t; // ---------- char, or int, or double and so on...

struct stack {
    int size;
    data_t* data;
    data_t top;
};

void push(struct stack* stk, data_t d);
data_t pop(struct stack* stk);
void clear(struct stack* stk);
int isEmpty(struct stack* stk);
void prntfStk(struct stack* stk);
struct stack* stkalloc(struct stack* stk);