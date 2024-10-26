# include <stdio.h>
# include <unistd.h>
# include <wait.h>
int main() {
    pid_t pid, pid1;
    pid = fork();
    if (pid == 0) {
        pid1 = getpid();
        // pid는 0, 즉 자식 프로세스가 fork()에서 받은 값
        printf("child : pid = %d\n", pid);
        // pid1은 자식 프로세스의 실제 pid 값
        printf("child : pid = %d\n", pid1);
    }
    else if (pid > 0) {
        wait(NULL);
        pid1 = getpid();
        //pid는 자식 프로세스의 PID
        printf("parent : pid = %d\n", pid);
        // pid1은 부모 프로세스의 실제 PID 값
        printf("parent : pid = %d\n", pid1);
    }

    return 0;
}