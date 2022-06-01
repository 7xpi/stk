#include "stk.h"
#include "ui.h"
#include "addons.h"

int main(void) {

    struct stack* a = NULL;

    a = stkalloc(a);

    data_t tmp = 0;
    int sl = selector();
    while (sl != 7) {
        switch (sl) {
            case 1: {
                printf_s("\n\tPushed elements: ");
                char tchar;
                forn(i, 0, 8) {
                    tchar = (char)rnd((int)'a', (int)'z');
                    push(a, tchar);
                    printf_s("%c ", tchar);
                }
                printf_s("\n\tStack's elements: ");
                prntfStk(a);
                printf_s("\n");
                break;
            }
            case 2: {
                printf_s("\n\tInput char: ");
                scanf_s(" %c", &tmp, 1);
                push(a, tmp);
                printf_s("\tPushed %c to stack!\n\n", tmp);
                break;
            }
            case 3: {
                if (!isEmpty(a)) {
                    printf_s("\n\tPopped = %c\n", pop(a));
                }
                else {
                    printf_s("\n\tCant pop! Stack is empty!\n");
                }
                break;
            }
            case 4: {
                printf_s("\n\tStack: ");
                if (!isEmpty(a)) {
                    prntfStk(a);
                }
                else {
                    printf_s("\n\tStack is empty!\n");
                }
                break;
            }
            case 5: {
                printf_s("\n\tPop elements until the end:\n");
                if (!isEmpty(a)) {
                    while (a->size > 0) {
                        printf_s("\tTop elem = %c\n", pop(a));
                    }
                }
                else {
                    printf_s("\tStack is empty!\n");
                }
                break;
            }
            case 6: {
                printf_s("\n\tStack dump: ");
                if (!isEmpty(a)) {
                    printf_s("\n\tStack size = %d\n\tTop elem: %c\n\tStack: ", a->size, a->top);
                    prntfStk(a);
                }
                else {
                    printf_s("\n\tStack is empty!\n");
                }
                break;
            }
            default: {
                printf_s("\n\tWrong selection!\n");
                break;
            }
        }
        sl = selector();
    }

    if (a) {
        free(a);
    }

    return 0;
}