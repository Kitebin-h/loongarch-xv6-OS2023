// my-Shell

#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <error.h>
#include <pwd.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PATH_LENGTH 1024    // Maximum length of file path

void print_prompt()
{
    char host_name[MAX_PATH_LENGTH];  // user's hostname
    char path_name[MAX_PATH_LENGTH];  // current working path
    // C++中结构体不用加struct 但是C语言中没加下面的struct会报错：未定义标识符
    struct passwd* pwd = getpwuid(getuid());  // user's information
    getcwd(path_name, MAX_PATH_LENGTH);

    // get user's hostname
    if (gethostname(host_name, MAX_PATH_LENGTH))
        strcpy(host_name, "unknown");

    // if current directory is not user's home, print it directory
    if (strlen ( path_name ) < strlen ( pwd->pw_dir ) || strncmp(path_name , pwd->pw_dir , strlen ( pwd->pw_dir)) != 0)
        printf("\033[;32m%s@%s\033[0m:\033[;34m%s\033[0m", pwd->pw_name, host_name, path_name);
    else // else use '~' instead of user's home
        printf("\033[;32m%s@%s\033[0m:\033[;34m~%s\033[0m", pwd->pw_name, host_name, path_name + strlen(pwd->pw_dir));

    // if the current user is root
    if (getuid() == 0)
        printf("# "); // is root
    else
        printf("$ "); // isn't root
}

bool str_equal(char* str1, char* str2) {
    return strcmp(str1, str2) == 0;
}

int
main(int argc, void* argv[]) {
    char cmd[1024];
    printf("Welcome to my Shell!!!\n");
    while (1) {
        print_prompt();
        scanf("%s", cmd);
        if (str_equal(cmd, "exit")) {
            printf("Bye~\n");
            exit(EXIT_SUCCESS);
        }
        else if (str_equal(cmd, "help")) {
            printf("----------------\nThe Friendly Mannual：\n");
            printf("help  : print the helpful information about how to use the Shell\n");
            printf("exit  : Exit the Shell Program\n----------------\nThe outer command format: \n");
            printf("exec + command\n----------------\n");
        }
        else if (str_equal(cmd, "exec")) {
            scanf("%s", cmd);
            //memset(cmd, '\0', 1024);
            //fgets(cmd, 1024, stdin);
            pid_t pid = fork();
            if(pid > 0) {
                wait(NULL);
            }
            else if (pid == 0) {
                int retVal = execlp(cmd, cmd, NULL);
                if(retVal == -1) printf("fail to exec %s\n", cmd);
                exit(EXIT_FAILURE);
            }
        }
        else {
            printf("Invalid command!\n");
        }
    }

    return 0;
}