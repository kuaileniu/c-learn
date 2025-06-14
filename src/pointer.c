#include <stdio.h>
#include <stdlib.h>

struct MyStu
{
    int id;
    char *pName;
};

void test_pointer(void)
{
    struct MyStu stu;
    stu.id = 1;
    stu.pName = (char *)malloc(20 * sizeof(char));
    if (stu.pName == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    snprintf(stu.pName, 20, "Student %d", stu.id);

    printf("ID: %d, Name: %s\n", stu.id, stu.pName);

    free(stu.pName);
}