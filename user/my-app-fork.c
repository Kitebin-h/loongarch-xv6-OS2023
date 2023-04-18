#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int 
main(int argc, char* argv[])
{
    int pid = -1;
    int cnt = 0;
    printf("This is my own app! It can fork some child process!\n");
    pid = fork();
    printf("pid is %d\n", pid);
    pid = fork();
    printf("pid is %d\n", pid);
    while (1)
    {
        /* code */
        cnt++;
    }
    exit(0);
}