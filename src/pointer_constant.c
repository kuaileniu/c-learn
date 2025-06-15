#include <stdio.h>
#include <stdlib.h>
/**
 * 指针常量 是常量
 * 常量指针 是指针
 * 谁在后面是谁
 */
void show_pointer_constant(void)
{
    int a = 3;
    int b = 4;
    int c = 5;
    int *const p1 = &a; // 指针常量，指向的地址不能改变
    // p1 = &b; // 这行代码会报错，因为 p1 是指针常量，不能改变指向的地址
    *p1 = 6; // 这行代码是合法的，因为我们可以改变指针常量指向的值

    const int *t;
    t = &b; // 常量指针，指向的值不能改变
    t = &c; // 这行代码是合法的，因为我们可以改变常量指针指向的地址
    // *t = 6; // 这行代码会报错，因为 t 是常量指针，不能改变指向的值
     
    printf("a: %d, b: %d, c:%d \n", a, b, c);
    printf("show_pointer_constant called\n");
}