#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

#define NUM_CHILDREN 10

int main() {
    srand(time(NULL));

    pid_t child_pids[NUM_CHILDREN];
    int i;

    for (i = 0; i < NUM_CHILDREN; i++) {
        pid_t pid = fork();

        if (pid < 0) {
            perror("Fork error");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            // Child process
            char *args[] = {"./ej2_child", NULL};
            execve(args[0], args, NULL);
        } else {
            // Parent process
            child_pids[i] = pid;
        }
    }

    // Wait for all child processes to finish
    for (i = 0; i < NUM_CHILDREN; i++) {
        waitpid(child_pids[i], NULL, 0);
    }

    printf("Parent process with PID %d: All child processes have finished\n", getpid());

    return 0;
}