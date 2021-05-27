#include <stdio.h>
#include <unistd.h>
#include <wait.h>

int value = 5;

int main()
{
    pid_t pid;
    pid = fork();
    if (pid > 0) // parent process
    {
        // wait(NULL);
        printf("Hello, Parent value = %d!, PID = %d\n", value, pid);
    }
    if (pid == 0) // child process
    {
        value += 15;
        printf("Hello, Child value = %d!, PID = %d\n", value, pid);
    }
}