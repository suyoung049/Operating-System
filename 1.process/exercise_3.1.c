# include <stdio.h>
# include <wait.h>
# include <unistd.h>


/**
 * print 되는 value의 값은
 * value = 5
 */
int value = 5;

int main() {
    pid_t  pid;
    pid = fork();

    // child process
    if (pid == 0) {
        value += 15;
        return 0;
    }

    // parent process
    else if (pid > 0)
    {
        wait(NULL);
        printf( "parent: value = %d\n", value);
    }
    
}