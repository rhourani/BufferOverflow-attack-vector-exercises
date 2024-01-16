#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
//as the strcpy doesn't check the bound as in strlcpy, 
//it is a deprecated method I used this to enable the demonstration of this example
#pragma warning(disable : 4996) 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void vulnerable_function(char* input) {
    // Allocate 8 bytes on the heap
    char* buffer = (char*)malloc(9);

    // Manually set the buffer content
    strncpy(buffer, "ABCDEFGH", 9);
    buffer[9] = '\0'; // Null-terminate the string

    printf("Before overflow:\n");
    printf("Buffer: %s\n", buffer);

    // Use strcpy without bounds checking (to demonstrate vulnerability)
    // it will write after heap memory end which will cause a corrupted heap memory
    strcpy(buffer, input);

    printf("\nAfter overflow:\n");
    printf("Buffer: %s\n", buffer);

    free(buffer);
}

int main(int argc, char** argv) {

    //When an input is beigger than 8 bytes 
    char* input = (char*)malloc(9);

    std::cout << "Enter data: ";
    std::cin >> input;

    vulnerable_function(input);

    return 0;
}
