#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

void handler(int sig) {
    printf("\nCaught signal %d\n", sig);
}

int main() {
    struct sigaction sa;
    sa.sa_handler = handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART;

    sigaction(SIGINT, &sa, NULL);

    char buf[100];
    printf("Enter input (Ctrl+C won't interrupt fgets): ");
    fgets(buf, sizeof(buf), stdin);
    printf("You entered: %s", buf);
}

