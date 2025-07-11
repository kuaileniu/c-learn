#include <signal.h>
#include <stdio.h>

void handler(int sig);

void raise_sig(void);

int run_tsingal(void)
{
    void (*orig_handler)(int);
    printf("Installing handler for signal %d\n", SIGINT);
    orig_handler = signal(SIGINT, handler);
    raise_sig();

    printf("Changing handler for signal SIG_IGN\n");
    signal(SIGINT, SIG_IGN);
    raise_sig();

    printf("Restoring original handle\n");
    signal(SIGINT, orig_handler);
    raise_sig();

    printf("Program terminates normally\n");
    return 0;
}

void handler(int sig)
{
    printf("handler called for Signal %d   \n", sig);
}

void raise_sig(void)
{
    raise(SIGINT);
}