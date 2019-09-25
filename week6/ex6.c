#include <stdio.h> 
#include <unistd.h>
#include <stdlib.h>
#include <signal.h> 
#include <sys/wait.h>

int main() 
{ 
    int p[2]; 
    int pid[2];
    int status;
    if(pipe(p)<0) //труба расшатана
        return -1;

    printf("New process(1) forked.\n");
    pid[0] = fork();
    
    if(pid[0]!=0)
    {
        printf("New process(2) forked.\n");
        pid[1] = fork();
        if(pid[1] != 0)
        {
            //Parent
            printf("Pid of second child process is being send from parent.\n");
            write(p[1], &pid[1], sizeof(pid[1]));
            waitpid(pid[1], &status, WUNTRACED);
            printf("Exit status of second child is: %d\n",status);
        }
        else
        {
            //Child 2
            printf("PID of child 2 is: %d\n", getpid());
            while(1)
            {
                printf("Child 2 is working.\n");
                sleep(1);
            }
        }
    }
    else
    {
        //Child 1
        read(p[0], &pid[1], 4);
        printf("Pid of second child process is get in first child process.PID is %d\n", pid[1]);   
        sleep(4);
        printf("Child 2 is being killed.\n");
        kill(pid[1],SIGSTOP);
    }
    return 0; 
} 
