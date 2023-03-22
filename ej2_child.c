#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <time.h>
#include <stdlib.h>

int main(void) {
    srand(time(NULL));
    int runtime = rand() % 10 + 1;
    printf("Child process with PID %d: Sleeping for %d seconds\n", getpid(), runtime);
    sleep(runtime);
    exit(EXIT_SUCCESS);
}
