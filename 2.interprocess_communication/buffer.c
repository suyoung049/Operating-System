# define BUFFER_SIZE 10

typedef struct {

} item;

// 변수 in은 버퍼 내에서 다음으로 비어 있는 위치
// 변수 out은 버퍼 내에서 첫번째로 채워 져 있는 위치
item buffer[BUFFER_SIZE];
int in = 0;
int out = 0;

//생산자 프로세스
item next_produced;

while (true)
{
    //(in + 1) % BUFFER_SIZE == out 이면 buffer가 가득 차있기 때문에 대기
    while ((in + 1) % BUFFER_SIZE == out)
    {
        /*do nothing */
    }

    buffer[in] = next_produced;
    in = (in + 1) % BUFFER_SIZE;
};

//소비자 프로세스
item next_consumed;

while (true)
{
    // in == out 이면 buffer가 비워있기 때문에 대기
    while (in == out)
    {
        /* do nothing */
    }

    next_consumed = buffer[out];
    out = (out + 1) % BUFFER_SIZE;    
};

