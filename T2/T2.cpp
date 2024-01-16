#include <stdio.h>

void function_vulnerable(char* arg)
{
	char buf[128];
	int i;

	// Mistake is here, the loop is inclusive and we 
	// know array start from 0, so, there would be 128 + 1 this means off-by-one buffer overflow
	// This will lead to the corruption of the EBP
	for (i = 0; i <= 128; i++)
		buf[i] = arg[i];
}

int main(int argc, char** argv)
{
	function_vulnerable(argv[1]);
}