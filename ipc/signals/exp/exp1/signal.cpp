#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include  <unistd.h>
//////////////////////////
// #include <signal.h>
//signal()raise() kill SIGFPE
//SIG_DFL,SIG_IGN 分别表示无返回值的函数指针，指针值分别是0和1，这两个指针值逻辑上讲是实际程序中不可能出现的函数地址值。
//SIG_DFL：默认信号处理程序
//SIG_IGN：忽略信号的处理程序
//////////////////////////

#define  SIGUSRME    SIGUSR1
void handle(int signo)
{
    printf("handle[0]\n");
    signal(SIGFPE, SIG_DFL);

}
void handle1(int signo)
{
    printf("handle[1].\n");
}

void handleUsr(int signo)
{
    if(signo == SIGUSR1){
        printf("[1]received SIGUSR1\n");
    }
    else if(signo == SIGUSR2){
        printf("[2]received SIGUSR2\n");
    }
    else printf("received other signal\n");
}


void handleMe(int signo)
{
    printf("handle[Me].\n");
}

int main(int argc, char* argv[])

{
    //signal
    /*SIGFPE 8 C 浮点异常*/
    signal(SIGFPE, handle);
    raise(SIGFPE);
    return 0;
    ///////////////////////////////////////////////////////////
    signal(SIGUSR1, handle1);
    raise(SIGUSR1);

    pid_t  pid=getpid();
    printf("PID=%ld\n",pid);
    kill(pid,SIGUSR1);/*等价于调用raise(SIGUSR1) */
    ///////////////////////////////////////////////////////////
   if(SIG_ERR== signal(SIGUSR1, handleUsr))
   {
       perror("SIGUSR1 error!");
   }
    raise(SIGUSR1);/* 等价于调用kill(pid,SIGUSR1);*/
    if(SIG_ERR== signal(SIGUSR2, handleUsr))
    {
        perror("SIGUSR2 error!");
    }
    raise(SIGUSR2);/*等价于调用 kill(pid,SIGUSR2);*/

    if(SIG_ERR== signal(SIGUSRME, handleMe))
    {
        perror("SIGUSRME error!");
    }
    raise(SIGUSRME);/*等价于调用 kill(pid,SIGUSR1);*/
    kill(pid,SIGUSRME);

    return 0;

}
