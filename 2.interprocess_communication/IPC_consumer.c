#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>        
#include <fcntl.h>           
#include <unistd.h>

int main() {
    const int SIZE = 4096;           // shared memory size
    const char *name = "OS";         // shared memory name

    int shm_fd;
    char *ptr;
    
    // create the shared memory object
    shm_fd = shm_open(name, O_RDONLY, 0666);

    // map the shared memory object
    ptr = (char *)mmap(0, SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);

    // read and print the content of shared memory
    printf("%s", (char *)ptr);

    // unlink the shared memory
    shm_unlink(name);

    return 0;
}