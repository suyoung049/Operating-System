# include <stdio.h>
# include <unistd.h>
# include <wait.h>

int main(){
    pid_t  pid;
    // fork 후 부모 프로세스, 자식 프로세스 분리
    pid = fork();
    
    /**
     * wait()
     * 부모 프로세스는 wait queue에서 자식 프로세스가 종료할 때 까지 대기 
     */
    // parent process
    if (pid > 0) {
        wait(NULL);
    }

    //부모 프로세스에서 먼저 실행 후, 부모 프로세스의 복사본인 자식 프로세스에서 한번 더 실행
    printf("Hello, Process ! %d\n", pid);


}