#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include  <unistd.h>

void handle1(int signo)
{
    pid_t  pid=getpid();
    printf("PID=%d  signo=%d\n",pid,signo);
   
    if(signo == SIGUSR1){
        printf("[1]received SIGUSR1\n");
    }
    else if(signo == SIGUSR2){
        printf("[2]received SIGUSR2\n");
    }
    else printf("received other signal\n");

    
}


int main(int argc, char* argv[])

{
    signal(SIGUSR1, handle1);
     while(1)
    {
       sleep(100);
    }
    return 0;

}
