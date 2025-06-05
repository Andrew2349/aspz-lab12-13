#include <signal.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    sigset_t set;
    sigemptyset(&set);
    sigaddset(&set, SIGINT);
    sigprocmask(SIG_BLOCK, &set, NULL);

    printf("SIGINT is now blocked. Try Ctrl+C\n");
    sleep(10);

    sigprocmask(SIG_UNBLOCK, &set, NULL);
    printf("SIGINT unblocked\n");
    while (1) pause();
}

