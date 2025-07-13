#include <stdio.h>
#include <stdlib.h>
#include <threads.h>
#include <stdatomic.h>

atomic_llong spin_counter = 0;
atomic_flag aflag = ATOMIC_FLAG_INIT;

int thrd_proc1(void *arg)
{
    printf("Thread 1 is running...\n");
    struct timespec interv = {0, 20}; // 20 nanoseconds

    for (size_t x = 0; x < 5000; x++)
    {
        while (atomic_flag_test_and_set(&aflag))
            ;
        spin_counter = spin_counter + 1;
        atomic_flag_clear(&aflag);
        thrd_sleep(&interv, NULL);
    }
    return 0;
}

int thrd_proc2(void *arg)
{
    printf("Thread 2 is running...\n");
    struct timespec interv = {0, 30}; // 300 nanoseconds

    for (size_t x = 0; x < 5000; x++)
    {
        while (atomic_flag_test_and_set(&aflag))
            ;
        spin_counter = spin_counter - 1;
        atomic_flag_clear(&aflag);
        thrd_sleep(&interv, 0);
    }
    return 0;
}

void run_spinlock(void)
{
    printf("5555 Running run_spinlock...\n");
    thrd_t t1, t2;
    thrd_create(&t1, thrd_proc1, 0);
    thrd_create(&t2, thrd_proc2, 0);
    thrd_join(t1, &(int){0});
    thrd_join(t2, &(int){0});
    printf("spin_counter value: %lld\n", spin_counter);
     
}