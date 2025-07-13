#include "stdio.h"
#include "pointer.h"
#include "mem_test.h"
#include "pointer_constant.h"
#include "file_test.h"
#include "switch_test.h"
#include "tsingal.h"
#include "tsetjmp.h"
#include "my_threads.h"
#include "condcoop.h"
#include "atomoprs.h"
#include "spinlock.h"
#include "thrdloca.h"
#include "tssdemo.h"

int main()
{
    // run_tsingal();
    // switch_show();
    // printf("Main Start !\n");

    // show_pointer_constant();
    // test_memory();
    // test_pointer();
    // file_show_test();
    //  run_tsetjmp();
    // run_mythreads();
    // run_condcoop();
    // run_atomoprs();
    // run_spinlock();
    // run_thrdloca();
    run_tssdemo();
    return 0;
}