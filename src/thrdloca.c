#include "stdlib.h"
#include "stdio.h"
#include "threads.h"

_Thread_local int g;

void do_print(void *arg)
{
    printf("do_print  %s:%s\t%p.\n", (char *)arg, __func__, &g);
}

void do_calc(void *arg)
{
    printf("do_calc   %s:%s\t%p.\n", (char *)arg, __func__, &g); // do_calc   Thread 1:do_calc      0x7ffff7da06fc.
    do_print(arg);
}

int thrd_proc(void *arg)
{
    printf("thrd_proc   Thread %s is running...\n", (char *)arg); // thrd_proc   Thread Thread 1 is running...
    g = 100;
    do_calc(arg);
    return 0;
}

void run_thrdloca(void)
{
    printf("Running run_thrdloca...\n");
    thrd_t t1, t2;
    thrd_create(&t1, thrd_proc, "Thread 1");
    thrd_create(&t2, thrd_proc, "Thread 2");
    printf("%s:%s\t %p\n", "main", __func__, &g);
    do_calc("main");
    thrd_join(t1, &(int){0});
    thrd_join(t2, &(int){0});
}