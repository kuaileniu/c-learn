#include <stdio.h>
#include <stdlib.h>
/**
 *  long *const p1, 指针常量 是常量，是指针的常量，是地址的常量，要求地址不能变，*(地址)是常量不可改。
 *  const int *t常量指针 是指针,是常量的指针，是指向的值的常量，要求指向的值不能变,int值 是常量不可改。
 *  谁在后面是谁
 */
void show_pointer_constant(void)
{
    int a = 3;
    int b = 4;
    int c = 5;
    long *const p1 = &a; // 指针常量，指向的地址不能改变
    // p1 = &b; // 这行代码会报错，因为 p1 是指针常量，不能改变指向的地址
    *p1 = 6; // 这行代码是合法的，因为我们可以改变指针常量指向的值

    const int *t;
    t = &b; // 常量指针，指向的值不能改变
    t = &c; // 这行代码是合法的，因为我们可以改变常量指针指向的地址
    // *t = 6; // 这行代码会报错，因为 t 是常量指针，不能改变指向的值

    printf("a: %d, b: %d, c:%d \n", a, b, c);

    int k1 = 10;
    int *const pp1 = &k1; // 指针常量，指向的地址不能改变
    printf("Before changePConst, k1: %d,", k1);
    changePConst(pp1);                          // 修改指针常量指向的值
    printf("After changePConst, k1: %d\n", k1); // Before changeInt, k1: 10,After changeInt, k1: 90

    int k2 = 30;
    const int *pp2 = &k2; // 常量指针，指向的值和地址都不能改变
    printf("Before changeConstInt, k2: %d,", k2);
    changeConstInt(pp2);                          // 修改常量指针指向的地址
    printf("After changeConstInt, k2: %d\n", k2); // Before changeIntConst, k2: 30,Value pointed by const pointer: 40
    printf("show_pointer_constant called\n");
}

void changePConst(int *const p)
{
    int k3 = 20;
    // p = &k;  // 这行代码会报错，因为 p 是指针常量，不能改变指向的地址
    *p = 90; // 修改指针指向的值
}
void changeConstInt(const int *p)
{
    int k4 = 40;
    p = &k4; // 这行代码是合法的，因为我们可以改变常量指针指向的地址
    // *p = 10; // 这行代码会报错，因为 p 是常量指针，不能改变指向的值
    printf("Value pointed by const pointer: %d\n", *p);
} 