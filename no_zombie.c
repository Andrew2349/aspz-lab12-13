#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    struct sigaction sa;
    sa.sa_handler = SIG_IGN;
    sa.sa_flags = SA_NOCLDWAIT;
    sigaction(SIGCHLD, &sa, NULL);

    pid_t pid = fork();
    if (pid == 0) {
        printf("Child PID: %d\n", getpid());
        _exit(0);
    } else {
        printf("Parent PID: %d\n", getpid());
        sleep(3);
    }
    return 0;
}

