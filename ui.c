#include "ui.h"

int selector(void) {
	char ch = -1;
	printf_s("\n\tChoose an operation:\n");
	printf_s("\t\t1 - input and push element.\n");
	printf_s("\t\t2 - pop element.\n");
	printf_s("\t\t3 - show stack.\n");
	printf_s("\t\t4 - pop elements until the end of the stack.\n");
	printf_s("\t\t5 - stack dump.\n");
	printf_s("\t\t6 - exit program.\n");
	ch = _getch();
	return (int)ch - (int)'0';
}