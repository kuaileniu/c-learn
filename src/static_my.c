#include <stdio.h>
#include <stdlib.h>

// static void static_show(void) //函数被static修饰后，
// 该函数只能在本文件中被调用，其他文件无法访问到这个函数。
 void static_show(void)
{
    // This is a simple C program that demonstrates the use of a static variable.
    // The static variable retains its value between function calls.
    static int count = 0; // Static variable to keep track of the number of times the function is called

    count++; // Increment the count each time the function is called
    printf("This function has been called %d times.\n", count);
}