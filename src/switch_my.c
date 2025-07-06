#include <stdio.h>
#include <stdlib.h>

void switch_show()
{

    // This is a simple C program that demonstrates the use of a switch statement.
    // The switch statement is used to execute different blocks of code based on the value of a variable.
    // int number = 1; // Change this value to test different cases
    const int two = 2;

    switch (2)
    {
    case 1:
        // Code block for case 1
        printf("You selected option 1.\n");
        break;
        //  case two:  // Using the constant pointer to demonstrate case 2
        // Code block for case 2
        // printf("You selected option 2.\n");
        // break;
    default:
        // Code block for default case
        printf("Invalid option selected.\n");
        break;
    }
    static_show();

    return 0;
}
