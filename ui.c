#include "ui.h"

int selector(void) {
	char ch = -1;
	printf_s("\n\tChoose an operation:\n");
	printf_s("\t\t1 - automatical create stack.\n");
	printf_s("\t\t2 - input and push element.\n");
	printf_s("\t\t3 - pop element.\n");
	printf_s("\t\t4 - view stack elements.\n");
	printf_s("\t\t5 - pop elements until the end of the stack.\n");
	printf_s("\t\t6 - stack dump.\n");
	printf_s("\t\t7 - exit program.\n");
	printf_s("%*c> ", 3, ' ');
	ch = _getch();
	return (int)ch - (int)'0';
}