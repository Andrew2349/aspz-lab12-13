#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void handler(int sig, siginfo_t *info, void *ucontext) {
    printf("=== Caught signal %d (%s) ===\n", sig, strsignal(sig));
    printf("Fault address: %p\n", info->si_addr);
    printf("Signal code: %d\n", info->si_code);
    printf("Sending PID: %d\n", info->si_pid);
    printf("User ID: %d\n", info->si_uid);
    exit(EXIT_FAILURE);
}

int main() {
    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));
    sa.sa_sigaction = handler;
    sa.sa_flags = SA_SIGINFO;

    if (sigaction(SIGSEGV, &sa, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    printf("Triggering segmentation fault...\n");
    int *p = NULL;
    *p = 42;

    return 0;
}
