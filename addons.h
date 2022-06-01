#include <conio.h>
#include <stdio.h>
#include <Windows.h>
#include <math.h>
#include <stdlib.h>

#define ferr printf_s("fileErr\n\tfile: %s\n\tline: %d\n\n", __FILE__, __LINE__); system("pause>nul"); exit(88);
#define filename "stkChanges.txt"

int rnd(int min, int max);