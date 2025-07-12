#include "stdio.h"
#include "stdlib.h"
#include "threads.h"
#include <stdatomic.h>

_Atomic long long counter = 0;

int thd_proc1(void *arg)
{
    printf("Thread 1 is running...\n");
    struct timespec interv = {0, 20}; // 2 milliseconds

    for (size_t x = 0; x < 5000; x++)
    {
        long long old = atomic_load(&counter), new;
        do
        {
            new = old + 1;
        } while (!atomic_compare_exchange_weak(&counter, &old, new)); /**如果old值与counter相同则将new值写入counter；否则重放弃，继续while循环；atomic_compare_exchange_weak执行期间其他线程无法对 counter进行操作 */

        thrd_sleep(&interv, 0);
    }
    return 0;
}

int thd_proc2(void *arg)
{
    printf("Thread 1 is running...\n");

    struct timespec interv = {0, 300}; // 300 milliseconds
    for (size_t x = 0; x < 5000; x++)
    {
        long long old = atomic_load(&counter);
        long long new;
        do
        {
            new = old - 1;
        } while (!atomic_compare_exchange_weak(&counter, &old, new));
        thrd_sleep(&interv, 0);
    }
    return 0;
}


void run_atomoprs(void)
{
    printf("Running run_atomoprs...\n");
    thrd_t t1, t2;
    thrd_create(&t1, thd_proc1, 0);
    thrd_create(&t2, thd_proc2, 0);

    thrd_join(t1, &(int){0});
    thrd_join(t2, &(int){0});

    printf("%lld\n", counter);
}
