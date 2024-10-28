# include <stdio.h>
# include <unistd.h>

/**
 * How many processes are created?
 * 16게
 */

int main() {
    int i;
    pid_t pid;

    for (i = 0; i < 3; i++) {
        pid = fork();
        printf("Hello, Process !%d\n", pid);
    }

    return 0;
}