#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int 
main(int argc, char* argv[]) {

    pid_t pid = fork();
    if (pid > 0) {
        while (1)
        {
            /* code */
        }
    } else if (pid == 0) {
        for (int i = 0; i < 8; i++) {
            printf("sleep time is %d\n", i);
            sleep(1);
        }
    }

    return 0;
}