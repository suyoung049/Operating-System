# include <wait.h>
# include <unistd.h>
# include <stdio.h>

# define SIZE 5
int nums[SIZE] = {0, 1, 2, 3, 4};

int main() {
    pid_t pid;
    int i;
    pid = fork();

    if (pid == 0) {
        // 자식 프로세스
        for (i = 0; i < SIZE; i++) {
            nums[i] *= i;  // 배열 값 수정
            printf("CHILD: %d \n", nums[i]);
        }
    }
    else if (pid > 0) {
        // 부모 프로세스
        wait(NULL);  // 자식 프로세스가 종료될 때까지 대기
        for (i = 0; i < SIZE; i++) {
            printf("PARENT: %d \n", nums[i]);
        }
    }

    return 0;
}