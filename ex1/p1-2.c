#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int 
main(int argc, void *argv[]) {

    pid_t pid = fork();

    for (int i = 0; i < 9; i++) {
        if (pid == 0) {
            pid = fork();
        } else if (pid > 0) {
            break;
        } else if (pid == -1) {
            perror("fork");
        }
    }

    getchar();

    return 0;
}