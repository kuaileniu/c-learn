#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <threads.h>

tss_t key;

void destructor(void *value)
{
    printf("Destructor called for value: %s\n", (char *)value);
    free(value);
    printf("Freed.\n");
}

static void do_print(void)
{
    printf("%s.\n", (char *)tss_get(key));
    thrd_sleep(&(struct timespec){2, 0}, 0);
}

static int thrd_proc(void *arg)
{
    // printf("Key: %s .\n", (char );
    tss_set(key, malloc(strlen((char *)arg) + 10));
    strcpy((char *)tss_get(key), "Hello, ");
    strcat((char *)tss_get(key), (char *)arg);
    do_print();
    return 0;
}

void run_tssdemo(void)
{
    printf("Running TSS Demo...\n");
    tss_create(&key, destructor);

    thrd_t t1, t2;
    thrd_create(&t1, thrd_proc, "world");
    thrd_create(&t2, thrd_proc, "kitty");
    thrd_join(t1, &(int){0});
    thrd_join(t2, &(int){0});
    tss_delete(key);
}
