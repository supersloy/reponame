#include <stdio.h> 
#include <stdlib.h>
#include <signal.h> 

void singal_intercept(int sig) 
{ 
    printf("\nSIGINT signal is handled. Program terminating.\n"); 
    exit(0);
} 
  
int main() 
{ 
    signal(SIGINT, singal_intercept);
    while(1) ;
    return 0; 
} 
