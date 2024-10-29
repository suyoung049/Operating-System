#include <stdio.h>
#include <stdlib.h>
#include <wait.h>
#include <unistd.h>
#include <pthread.h>

int x = 10;  // 부모 프로세스와 자식 프로세스는 독립된 x 변수를 갖게 됨
void *runner(void *param);

int main() {
    int i;
    pid_t pid1, pid2;
    pthread_t tid;
    pthread_attr_t attr;

    // 스레드 속성 초기화
    pthread_attr_init(&attr);

    // 첫 번째 fork
    pid1 = fork();

    if (pid1 == 0) {  // 자식 프로세스
        // 스레드 생성
        pthread_create(&tid, &attr, runner, NULL);
        pthread_join(tid, NULL);

        // 두 번째 fork
        pid2 = fork();
        if (pid2 > 0) {
            wait(NULL);
            x += 10;
        }
        printf("valueEEE = %d\n", x);
        
    }
    else {
        wait(NULL);
        printf("value = %d\n", x);
    }

    pthread_attr_destroy(&attr);  // 스레드 속성 해제
    return 0;
}

void *runner(void *param) {
    x += 10;
    pthread_exit(0);
}