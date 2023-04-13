#include <stdio.h>
#include <unistd.h>

int 
main(int argc, char* argv[])
{
    int i;
    for (i = 0; i < 100; i++)
    {
        int pid = fork();
        if (pid == -1) {
            perror("fork");
        }
        else if (pid == 0) {
            sleep(10);
            return 0;
        }
        else {
        }
    }
    sleep(10);
    return 0;
}