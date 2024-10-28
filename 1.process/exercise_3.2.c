# include <stdio.h>
# include <unistd.h>
# include <wait.h>

/**
 * How many processes are created?
 *  8개
 */

int value = 5;
int main() {
    fork(); // process : 2
    value += 5;
    printf("Hello, Process ! %d\n", value);
    fork(); // 위에서 생성된 프로세스 2개에서 fork() process: 4
    value += 5;
    printf("Hello, Process ! %d\n", value);
    return 0;
}