//as the strcpy doesn't check the bound as in strlcpy, 
//it is a deprecated method I used this to enable the demonstration of this example
#pragma warning(disable : 4996) 

/*
In printf vulnerability, when programmers do not use formatting, this might lead to 
bypassing the check on the inputted data and lead to injection of malicious code,
as seen in the pervious excises how buffer overflow works. The attacker have possibility to 
corrupt the EBP and make it point to the malicious code address, by inputting unsanitized data 
through the code down
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int vuln(char buffer[256])
{
	int nReturn = 0;
	printf(buffer); // print out command line
	//printf(“%s”,buffer); // correct-way
	return(nReturn);
}

//A possible way to exploit the code is by injecting a malicious code number which then going to be converted to a hex address i.e.
//C:>T5.exe AAAA%x%x%n where AAAA is the malicious code's address before being converted to Hex and %X is a format specifier 
// that is intercepted as next address. This means skipping the EBS and ESP and then by using the %n which allow
//the write to an address the total number of bytes to the word written before of it.
// 
//And therefore it passes the pointers by buffer overflow and wrote the AAAA to the next memory cell
// after converting AAAA to hexadecimal would result in a memory address 0x41414141
// let's assume the above mentioned address is a malicious code address file and therefore we
// now exploited the system.

void main(int argc, char* argv[])
{
	char buffer[256] = ""; // allocate buffer
	if (argc == 2)
	{
		strncpy(buffer, argv[1], 255); // copy command line
	}
	vuln(buffer); // pass buffer to bad function
}