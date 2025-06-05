#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler(int sig) {
    static int count = 0;
    printf("Signal %d caught! Count: %d\n", sig, ++count);

    if (count < 3) {
        raise(sig);
    } else {
        printf("Handler called 3 times, exiting.\n");
    }
}

int main() {
    struct sigaction sa = {0};
    sa.sa_handler = handler;
    sa.sa_flags = SA_RESETHAND;

    sigaction(SIGINT, &sa, NULL);

    printf("PID: %d\nPress Ctrl+C...\n", getpid());

    while (1) {
        pause();
    }

    return 0;
}
