# include <wait.h>
# include <unistd.h>
# include <stdio.h>

int x = 10;

int main() {
    pid_t pid = fork();
    if (pid == 0) {
        x += 10;
    } else {
        wait(NULL);
        pid = fork();
        x += 10;
        if (pid > 0) {
            wait(NULL);
        } else {
            x += 10;
        }
    }
    printf("%d", x);
}