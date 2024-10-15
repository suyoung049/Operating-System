#include <stdio.h>
#include <unistd.h>
#include <wait.h>

int main()
{
    pid_t pid;
    //fork a child process
    pid = fork();
    if (pid < 0) {//에러 발생
        fprintf(stderr, "Fork Failed");
        return;
    }
    else if (pid == 0) {// child process
        execlp("/bin/ls", "ls", NULL);
    }
    else {//parent process
        wait(NULL);
        printf("Child Complete");
    }
    return 0;
}