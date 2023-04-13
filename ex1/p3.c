#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define __NR_gettid 186
void task(void* p)
{
    pthread_attr_t attr;
    void* stack_addr;
    size_t stack_size;
    
    pthread_getattr_np(pthread_self(), &attr);
    pthread_attr_getstack(&attr, &stack_addr, &stack_size);

    pid_t pid = getpid();
    long int tid = (long int)syscall(__NR_gettid);

    printf("pid: %lu, tid: %lu, stack address: %p, stack size: %lu\n", pid, tid, stack_addr, stack_size);

    getchar();
}

int 
main(int argc, char* argv[])
{
    for(int i=0; i<3; i++)
    {
        pthread_t tid;
        pthread_create(&tid, NULL, (void*)&task, NULL);
    }
    printf("\n");
    getchar();

    return 0;
}