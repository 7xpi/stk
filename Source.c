#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include <math.h>
#include "stk.h"

int main(void) {

    struct stack* a = NULL;
    int n;

    a = (struct stack*)malloc(sizeof(struct stack));
    stkalloc(a);

    if (!a) {
        me99;
    }

    printf_s("\n\tData type = char\n\n");
    printf_s("\tInput N: ");
    scanf_s("%d", &n);

    data_t tmp = 0;

    forn(i, 0, n) {
        printf_s("\tEnter a value: ");
        scanf_s(" %c", &tmp, 1);
        push(a, tmp);
    }

    printf_s("\n\tStack size = %d\n\tTop elem: %c\n\tStack:\n", a->size, a->top);
    prntfStk(a);

    printf_s("\n\tPop until the end:\n");
    while (a->size > 0) {
        printf_s("\tTop elem = %c\n", pop(a));
    }

    if (a) {
        free(a);
    }

    printf_s("\n\n\tPress any key to exit: ");
    system("pause>nul");
    return 0;
}

