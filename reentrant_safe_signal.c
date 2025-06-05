#include <signal.h>
#include <unistd.h>
#include <string.h>

void handler(int sig) {
    const char *msg = "Signal received\n";
    write(STDOUT_FILENO, msg, strlen(msg));
}

int main() {
    signal(SIGINT, handler);
    while (1) {
        pause();
    }
}
