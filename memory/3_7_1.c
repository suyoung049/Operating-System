#include <stdio.h>

int* func() {
    static int a = 2; // Make 'a' static so it persists after the function returns.
    return &a;
}

int main() {
    int* p = func();
    printf("%d\n", *p); // Use "%d" to print an integer value.
    
    *p = 20;
    printf("%d\n", *p); // Print the modified value.
    
    return 0;
}