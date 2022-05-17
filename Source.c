#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <malloc.h>

#define me99 printf_s("memerr line: %d", __LINE__); system("pause>nul"); exit(99);
#define forn(i, j, n) for(int i = j; i < n; ++i)

typedef int data_t;

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

int main() {

    struct stack* a = NULL;
    int n;

    a = (struct stack*)malloc(sizeof(struct stack));
    stkalloc(a);

    if (!a) {
        me99;
    }

    printf_s("Input N: ");
    scanf_s("%d", &n);

    int tmp = 0;

    forn(i, 0, n) {
        printf_s("Enter a value: ");
        scanf_s("%d", &tmp);
        push(a, tmp);
    }

    printf_s("Stack size = %d\nTop elem: %d\nStack:\n", a->size, a->top);
    prntfStk(a);

    printf_s("Pop until the end:\n");
    while (a->size > 0) {
        printf_s("Top elem = %d\n", pop(a));
    }

    printf_s("\n\n\tPress any key to exit: ");
    system("pause>nul");
    free(a);
    return 0;
}

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
    stk->top = -2934;
    stk->data = NULL;
}
void prntfStk(struct stack* stk) {
    forn(i, 0, stk->size) {
        printf_s("%d ", stk->data[i]);
    }
    printf_s("\n");
}
void stkalloc(struct stack* stk) {
    stk->size = 0;
    stk->data = (data_t*)malloc((stk->size + 1) * sizeof(int));
}

