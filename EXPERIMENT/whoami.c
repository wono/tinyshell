#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int global;

int main()
{
    pid_t child_pid;
    int status;
    int local = 0;
    
    child_pid = fork();
    
    if (child_pid < 0) {
        perror("fork");
        exit(0);
    }
    
    if (0 == child_pid) {
        printf("child process!\n");
        
        local++;
        global++;
        
        printf("child PID = %d, parent pid = %d\n\n", getpid(), getppid());
        printf("child's local = %d, child's global = %d\n", local, global);
        
        char *cmd[] = {"echo", "Hello World\n", (char*)0};
        return execvp("echo", cmd);
    }
    
    else {
        printf("parent process!\n");
        printf("parent PID = %d, child pid = %d\n", getpid(), child_pid);
        wait(&status); // wait for child to exit, and store child's exit status
        printf("Child exit code: %d\n\n", WEXITSTATUS(status));
        
        printf("Parent's local = %d, parent's global = %d\n", local, global);
        
        printf("Parent says bye!\n");
        exit(0);
    }
    
    return(1);
}
