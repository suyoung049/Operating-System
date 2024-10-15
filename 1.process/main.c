#include <stdio.h>
#include <stdlib.h>

// data 영역 저장
int x;
int y = 15;

// stack 영역 저장
int main(int argc, char *argv[])
{
    // stack 영역 저장
    int *values;
    int i;
    
    // 메모리 할당(heap)영역에 저장
    values = (int *)malloc(sizeof(int) * 5);

    // 배열에 값 할당(텍스트 영역)
    for (i = 0; i < 5; i++)
        values[i] = i;

    // 주소 값 출력(텍스트 영역)
    for (i = 0; i < 5; i++)
        printf("Address of values[%d] = %p\n", i, (void *)&values[i]);

    // 메모리 해제
    free(values);
    
    return 0;
}