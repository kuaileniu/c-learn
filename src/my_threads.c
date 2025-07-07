#include <stdio.h>
#include <stdlib.h>
#include <threads.h>

/**在CMakeLists.txt中添加
 *  target_link_libraries(learn PRIVATE pthread) 
 */

int thread_func(void *arg)
{
    printf("Hello from thread !\n");
    return 0;
}

void run_mythreads(void)
{
    printf("Running my threads...\n");
    thrd_t thread;
    thrd_create(&thread, thread_func, NULL);
    thrd_join(thread, NULL);
}