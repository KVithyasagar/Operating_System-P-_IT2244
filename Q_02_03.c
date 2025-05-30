First child sleeps for 2 seconds , exit with status 2
Second child: sleep for 1 second, exits with status 1
parent: waits twice , and prints which child (By PID or exit code)
finished first and second


#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t pid1, pid2;
    int status;

    // Create first child process
    pid1 = fork();
    if (pid1 == 0) {
        // First child: sleep for 2 seconds, then exit with status 2
        sleep(2);
        printf("First child (PID: %d) exiting with status 2\n", getpid());
        exit(2);
    }

    // Create second child process
    pid2 = fork();
    if (pid2 == 0) {
        // Second child: sleep for 1 second, then exit with status 1
        sleep(1);
        printf("Second child (PID: %d) exiting with status 1\n", getpid());
        exit(1);
    }

    // Parent process: waits for both children
    pid_t finished_pid;
    for (int i = 0; i < 2; i++) {
        finished_pid = wait(&status);
        if (WIFEXITED(status)) {
            printf("Parent: Child with PID %d finished with exit status %d\n", finished_pid, WEXITSTATUS(status));
        }
    }

    // Optionally, you could add extra logic here if you wanted to print who finished first.
    return 0;
}



the parent creates a child process
the child creates a grandchild process
the grandchild sleeps 2 seconds and exits with status 2
the child waits for the grandchild , prints its exit status
then exit with status 55