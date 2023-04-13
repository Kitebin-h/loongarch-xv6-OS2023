#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int 
main(int argc, char *argv[]) {

    // 生成3层子进程，每一层子进程个数为：2^n个
    pid_t pid_1 = 0, pid_2 = 0;
    for (int i = 0; i < 3; i++) {
        pid_1 = fork();
        if (pid_1 > 0) {
            pid_2 = fork();
        }
        if (pid_1 > 0 && pid_2 > 0) break;
        pid_1 = 0, pid_2 = 0;
    }

    getchar();

    return 0;
}

// 最终生成 2^3 = 8个进程
    // for (int i = 0; i < 3; i++) {
    //     pid_t pid = fork();
    //     //pid_t pid_2 = fork();
    //     if (pid == 0) {
    //         pid = fork();
    //        // pid_2 = fork();
    //     } else if (pid > 0) {
    //         pid = fork();
    //     } else if (pid == -1) {
    //         perror("fork");
    //     }
    // }
