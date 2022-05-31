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
    if (isEmpty(stk)) {
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
    if (isEmpty(stk)) {
        clear(stk);
    }
    return rval;
}
void clear(struct stack* stk) {
    stk->size = 0;
    stk->top = (data_t)0;
    stk->data = NULL;
}
int isEmpty(struct stack* stk) {
    return stk->size == 0;
}
void prntfStk(struct stack* stk) {
    printf_s("\t");
    forn(i, 0, stk->size) {
        printf_s("%c ", stk->data[i]);
    }
    printf_s("\n");
}
struct stack* stkalloc(struct stack* stk) {
    stk = (struct stack*)malloc(sizeof(struct stack));
    if (!stk) {
        me99;
    }
    stk->size = 0;
    stk->data = (data_t*)malloc((stk->size + 1) * sizeof(data_t));
    if (!stk->data) {
        me99;
    }
    return stk;
}