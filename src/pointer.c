#include <stdio.h>
#include <stdlib.h>

struct MyStu
{
    int id;
    char *pName;
};

void test_pointer(void)
{
    int *p = NULL;
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
    printf("一个指针的大小是%d\n", sizeof(char *));
    printf("name:%s\n", stu.pName);
    if (stu.pName != NULL)
    {
        free(stu.pName);
        stu.pName = NULL; // Avoid dangling pointer
    }

    test_pointer_multi();
    show_union();
    static_show();
    // show_enum();
}

void test_pointer_multi(void)
{
    int a = 10;
    int *p = &a;
    int **pp = &p;
    printf("a = %d\n", a);
    printf("p = %d\n", *p);
    printf("pp = %d\n", **pp);
    printf("a = %d, p = %d, pp = %d\n", a, *p, **pp);
    printf("a的地址是%p, p的地址是%p, pp的地址是%p\n", &a, &p, &pp);
}