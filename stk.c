#include "stk.h"
#include <stdio.h>

void push(struct stack* stk, data_t d) {
    if (stk->data) {
        data_t* t;
        t = (data_t*)realloc(stk->data, (stk->size + 1) * sizeof(data_t));
        if (t != NULL) {
            stk->data = t;
        }
    }
    else {
        stk->data = (data_t*)calloc(stk->size + 1, sizeof(data_t));
    }
    if (stk->data == NULL) {
        me99;
    }
    stk->data[stk->size++] = d;
    stk->top = stk->data[stk->size - 1];
}
data_t pop(struct stack* stk) {
    data_t err = -1;
    if (stk->size == 0) {
        printf_s("\n\nstk is empty\n\n");
        exit(3221225477);
    }

    data_t rval = stk->data[--stk->size];

    data_t* t;
    t = (data_t*)realloc(stk->data, (stk->size) * sizeof(data_t));
    if (t != NULL) {
        stk->data = t;
    }

    if (stk->data == NULL) {
        me99;
    }

    stk->top = rval;

    return rval;
}
void clear(struct stack* stk) {
    stk->size = 0;
    stk->top = 0.0;/*NULL;*/
    stk->data = NULL;
}
void prntfStk(struct stack* stk) {
    forn(i, 0, stk->size) {
        printf_s("%g ", stk->data[i]);
    }
    printf_s("\n");
}
void stkalloc(struct stack* stk) {
    stk->size = 0;
    stk->data = (data_t*)malloc((stk->size + 1) * sizeof(data_t));
}