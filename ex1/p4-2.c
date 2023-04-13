#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/wait.h>
#include <malloc.h>

void thread(void) {
    sleep(10);
}
int
main(int argc, char*argv[]) {
    pthread_t id[100];
    int i, ret;
    for (i = 0; i < 100; i++) {
        // 创建子线程
        ret = pthread_create(&id[i], NULL, (void *)thread, NULL);
        if (ret != 0) {
            printf("Create pthread error!\n");
            exit(1);
        }
    }
    for (i = 0; i < 100; i++) {
        pthread_join(id[i], NULL);
    }
    return 0;
}
