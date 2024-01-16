//as the strcpy doesn't check the bound as in strlcpy, 
//it is a deprecated method I used this to enable the demonstration of this example
#pragma warning(disable : 4996) 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int CallBack(const char* szTemp)
{
	printf("CallBack(%s)\n", szTemp);
	return 0;
}

//for this example to work you need to run the script with 
//first correct running and let's forward these params 00401005 CallBack()
//Next what needed is to pass the first param with an address of different function
//As the strcpy method copy the buffer without any check, 
//it is possible to overflow the address of some other function and exploit it.
void main(int argc, char** argv)
{
	static char buffer[16];
	static int (*funcptr)(const char* szTemp);
	funcptr = (int (*)(const char* szTemp))CallBack;
	strcpy(buffer, argv[1]); // unchecked buffer
	(int)(*funcptr)(argv[2]);
}