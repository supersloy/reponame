#include <stdio.h> 
#include <unistd.h>
#include <stdlib.h>
#include <signal.h> 

int main() 
{ 
    int pid = fork();
    if(pid!=0)
    {
        sleep(10);
        printf("OMAE WA MO SHINDEIRU!\n");
        kill(pid, SIGTERM);
    }
    else
    {
        while(1)
        {
            sleep(1);
            printf("Я оливье\n");
        }
    }
    return 0; 
} 
