#define _GNU_SOURCE #必须放在最前面
#include <stdio.h>
#include <stdlib.h>
#include <threads.h>
#include <sys/types.h>   // pid_t
#include <sys/syscall.h> // syscall(), SYS_gettid
#include <unistd.h>

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
    thrd_t self = thrd_current();
    // print_current_thread_id();
    /**获取真正的线程 ID（Linux 特有） */
    pid_t tid = syscall(SYS_gettid);
    printf("System Thread ID: %d\n", tid);
    return 0;
}