# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <sys/types.h>

# define BUFFER_SIZE 25
# define READ_END 0
# define WRITE_END 1

int main() {
    char write_msg[BUFFER_SIZE] = "Hi";
    char read_msg[BUFFER_SIZE];

    int fd[2];
    pid_t pid;

    //create the pipe(2개 생성)
    pipe(fd);

    pid = fork();

    if (pid > 0) { // parent process
        close(fd[READ_END]);
        write(fd[WRITE_END], write_msg, strlen(write_msg) + 1);
        printf("write %s\n", write_msg);
        close(fd[WRITE_END]);
    } else if (pid == 0) {
        close(fd[WRITE_END]);
        read(fd[READ_END], read_msg, BUFFER_SIZE);
        printf("reade %s\n", read_msg);
        if (strcmp(read_msg, "Hi") == 0) {
        char response_msg[BUFFER_SIZE] = "hello";
        printf("response %s\n", response_msg);
    } else {
        printf("read_msg는 'Hi'가 아닙니다.\n");
    }
        close(fd[READ_END]);
    }

    return 0;
}