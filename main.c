#include "stdio.h"
#include "pointer.h"
#include "mem_test.h"
#include "pointer_constant.h"
int main()
{
    printf("Hello, World!\n");

    show_pointer_constant();
    test_memory();
    test_pointer();
    return 0;
}