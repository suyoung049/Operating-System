# include <wait.h>
# include <unistd.h>
# include <stdio.h>

// B-D-C-D-A-D
int main() {
    pid_t pid = fork();
    if (pid > 0) {
        wait(NULL);
        printf("LINE A\n");
    } else {
        pid = fork();
        if (pid == 0) {
            printf("LINE B\n");
        } else {
            wait(NULL);
            printf("LINE C\n");
        }
    }
    printf("LINE D\n");
}