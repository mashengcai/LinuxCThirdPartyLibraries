#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/***************************************
*SIGUSR1 用户自定义信号1
*SIGUSR2 用户自定义信号2
****************************************
sigqueue函数原型：
函数作用：新的发送信号系统调用，主要是针对实时信号提出的支持信号带有参数，与函数sigaction()配合使用
int sigqueue(pid_t pid, int signo, const union sigval value);
分析：
第一个参数：指定接收信号的进程id;
第二个参数：确定即将发送的信号;
第三个参数：是一个联合结构体union sigval，指定了信号传递的参数，即通常所说的4字节值 ;

#include <signal.h>
int sigqueue(pid_t pid, int sig, const union sigval value);
union sigval {
   int   sival_int; //信号相关的数据
   void  *sival_ptr; //信号相关数据指针
 };

****************************************/
int main(int argc, char** argv)
{
    int iRcvPid = atoi(argv[1]);
    int iSndSig =SIGUSR1;/*SIGUSR2*/
    if(iRcvPid > 0 && iSndSig > 0)
    {
        union sigval val;
        val.sival_int = 111;
        sigqueue(iRcvPid, SIGUSR1, val);
    }
    else
    {
        printf("Target_PID or Signal_Number MUST bigger than 0!\n");
    }
    
    return 0;
}
