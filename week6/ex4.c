#include <stdio.h> 
#include <stdlib.h>
#include <signal.h> 

void SIGKILL_handler(int sig) 
{ 
    printf("\nSIGKILL signal is handled. Program terminating.\n"); 
    exit(0);
} 
void SIGSTOP_handler(int sig) 
{ 
    printf("\nSIGSTOP signal is handled. Program terminating.\n"); 
    exit(0);
} 
void SIGUSR1_handler(int sig) 
{ 
    printf("\nSIGUSR1 signal is handled. Program terminating.\n"); 
    exit(0);
} 
  
int main() 
{ 
    signal(SIGKILL, SIGKILL_handler);
    signal(SIGSTOP,	SIGSTOP_handler);
    signal(SIGUSR1, SIGUSR1_handler);
    while(1) ;
    return 0; 
} 
