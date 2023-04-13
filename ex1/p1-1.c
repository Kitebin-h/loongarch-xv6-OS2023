#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int main() {

    pid_t pid = fork();

    for (int i = 0; i < 9; i++) {
        
        if (pid > 0) {
            // 注意：这里若是重新定义了pid，那么此时内部pid是一个局部变量
            // 对于子进程其是继承父进程外部的pid，虽然在里面fork重新赋值新定义的pid，此时pid=0
            // 但是下一次循环，局部pid销毁，pid值变为其父进程原来初始pid>0
            // 接下来每个子进程在下一个进程中继续fork
            // 违反初衷：只需要最开始父进程fork10次
            //pid_t pid = fork(); 
            pid = fork();
            printf("pid is %ld\n", pid);
        } else if (pid == 0) {
            printf("child %d\n", i);
            break;
        } else if (pid == -1) {
            perror("fork");
        }
    }
    // 阻塞进程便于观察
    getchar();

    return 0;
}