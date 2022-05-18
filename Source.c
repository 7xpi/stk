#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include <math.h>
#include "stk.h"

int main() {

    struct stack* a = NULL;
    int n;

    a = (struct stack*)malloc(sizeof(struct stack));
    stkalloc(a);

    if (!a) {
        me99;
    }

    printf_s("data_t - char\n\n");
    printf_s("Input N: ");
    scanf_s("%d", &n);

    data_t tmp = 0;

    forn(i, 0, n) {
        printf_s("Enter a value: ");
        scanf_s(" %c", &tmp, 1);
        push(a, tmp);
    }

    printf_s("\nStack size = %d\nTop elem: %c\nStack:\n", a->size, a->top);
    prntfStk(a);

    printf_s("\nPop until the end:\n");
    while (a->size > 0) {
        printf_s("Top elem = %c\n", pop(a));
    }

    printf_s("\n\n\tPress any key to exit: ");
    system("pause>nul");
    free(a);
    return 0;
}

