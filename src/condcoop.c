#include <stdio.h>
// #include <stdlib.h>
#include <threads.h>

int data1 = -1, data2 = -1;
mtx_t mtx;
cnd_t cnd;

int thrd_task1(void *arg)
{

    thrd_sleep(&(struct timespec){
                   .tv_sec = 3,
                   .tv_nsec = 0},
               NULL);
    data1 = 10;
    mtx_lock(&mtx);
    if (data2 != -1)
        cnd_signal(&cnd);
    else
        cnd_wait(&cnd, &mtx);

    printf("Task 1: %d\n", data1 + data2);
    mtx_unlock(&mtx);
    return 0;
}

int thrd_task2(void *arg)
{
    thrd_sleep(&(struct timespec){
                   .tv_sec = 3,
                   .tv_nsec = 0},
               0);
    data2 = 80;
    mtx_lock(&mtx);

    if (data1 != -1)
        cnd_signal(&cnd);
    else
        cnd_wait(&cnd, &mtx);
    printf("Task 2: %d\n", data1 + data2);
    mtx_unlock(&mtx);
    return 0;
}

void run_condcoop(void)
{
    thrd_t t1, t2;

    mtx_init(&mtx, mtx_plain);
    cnd_init(&cnd);

    thrd_create(&t1, thrd_task1, 0);
    thrd_create(&t2, thrd_task2, 0);

    thrd_join(t1, &(int){0});
    thrd_join(t2, &(int){0});
    printf("Running conditional cooperation example...\n");
}
