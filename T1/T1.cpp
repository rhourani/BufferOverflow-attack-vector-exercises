#include <iostream>

int main() {
    char buffer[1]; // Buffer with a size of 1 byte

    // User input (and let us assume the user will enter more than 1 byte of data)
    std::cout << "Enter data: ";
    std::cin >> buffer;

    /*
    The user after inserting the data which is bigger than 1 byte, the application crashed and
    gave a run time error with 'Stack around the variable 'buffer' was corrupted', this indicates
    that an unlimited buffer overflow error happened by not checking the user's input and led to
    the unavailability of the application
    */


    // Display the contents of the buffer
    std::cout << "Buffer contents: " << buffer << std::endl;

    return 0;
}
