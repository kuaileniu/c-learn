#include <stdlib.h>
#include <stdio.h>

/*
malloc(sizeof(int));// 分配一个内存为size的内存区域
calloc(4, sizeof(int)); // 分配n个大小为size的联系内存区域
realloc(p, sizeof(int)); // 重新分配通过mallock 或 calloc 开辟的内存区域
free(p); // 释放内存
*/
void test_memory(void)
{
    int *p = NULL;
    p = (int *)malloc(sizeof(int));// 分配一个内存为size的内存区域
    *p = 123;
    printf("Allocated memory for integer,p: %d\n", *p);
    free(p);
    p = NULL; // Avoid dangling pointer
    // 释放内存后将指针置为NULL，避免悬空指针
    // 这是一种良好的内存管理实践

    int *m = NULL;
    m = (int *)calloc(4, sizeof(int)); // 分配n个大小为size的联系内存区域
        m[0] = 1;
    m[1] = 2;
    m[2] = 3;
    m[3] = 4;
    printf("Allocated memory for array m: %d, %d, %d, %d\n", m[0], m[1], m[2], m[3]);
    free(m);
    m = NULL; // Avoid dangling pointer

    m = (int *)realloc(m, sizeof(int) * 10); // 重新分配通过mallock 或 calloc 开辟的内存区域
    m[9] = 9;
    printf("Allocated memory for array m with realloc: %d\n", m[9]);   \
    free(m);
    printf("test_memory called\n");
}