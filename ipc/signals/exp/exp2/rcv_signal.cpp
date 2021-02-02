#include<signal.h>
#include<stdio.h>
#include <unistd.h>

/************************************************************************************************
siginfo_t.si_int直接与sigval.sival_int关联
siginfo_t.si_ptr直接与sigval.sival_ptr关联
*************************************************************************************************
sigaction函数用来查询和设置信号处理方式，它是用来替换早期的signal函数。sigaction函数原型及说明如下：
函数头文件：#include <signal.h>
函数原型：
int sigaction(int signum,const struct sigaction *act ,struct sigaction *oldact)
函数说明：sigaction()会依参数signum指定的信号编号来设置该信号的处理函数
函数参数：
signum是指定信号的编号，除SIGKILL和SIGSTOP信号以外

act参数如下：

参数结构sigaction定义如下

struct sigaction{
void (*sa_handler) (int);
void  (*sa_sigaction)(int, siginfo_t *, void *);
sigset_t sa_mask;
int sa_flags;
void (*sa_restorer) (void);
}
①    sa_handler：此参数和signal()的参数handler相同，此参数主要用来对信号旧的安装函数signal()处理形式的支持
②    sa_sigaction：新的信号安装机制，处理函数被调用的时候，不但可以得到信号编号，而且可以获悉被调用的原因以及产生问题的上下文的相关信息。
③    sa_mask：用来设置在处理该信号时暂时将sa_mask指定的信号搁置
④    sa_restorer： 此参数没有使用
⑤    sa_flags：用来设置信号处理的其他相关操作，下列的数值可用，可用OR 运算（|）组合：
   A_NOCLDSTOP:如果参数signum为SIGCHLD，则当子进程暂停时并不会通知父进程
   SA_ONESHOT/SA_RESETHAND:当调用新的信号处理函数前，将此信号处理方式改为系统预设的方式
   SA_RESTART:被信号中断的系统调用会自行重启
   SA_NOMASK/SA_NODEFER:在处理此信号未结束前不理会此信号的再次到来
   SA_SIGINFO：信号处理函数是带有三个参数的sa_sigaction
oldact参数：如果参数oldact不是NULL指针，则原来的信号处理方式会由此结构sigaction返回


函数返回值：成功返回0，出错则返回-1，错误原因存于error中
*************************************************************************************************
附加说明

信号处理安装的新旧两种机制：

①     使用旧的处理机制：struct sigaction act;  act.sa_handler=handler_old;

②     使用新的处理机制：struct sigaction act; act.sa_sigaction=handler_new;

并设置sa_flags的SA_SIGINFO位
*************************************************************************************************
错误代码

EINVAL：参数signum不合法，或是企图拦截SIGKILL/SIGSTOP信号

EFAULT：参数act，oldact指针地址无法存取

EINTR：此调用被中断
*************************************************************************************************
union sigval {
     int sival_int;
     void *sival_ptr;
};

typedef struct {
    int si_signo;//signal number的简写，该变量用来存储信号编号并且恒有值；
    int si_code;
    union sigval si_value;//signal value的简写，通过定义可以得知这个变量是一个结构体
    int si_errno;
    pid_t si_pid; //发送该信号的进程id
    uid_t si_uid; //发送该信号的用户id
    void *si_addr;//错误发生的地址
    int si_status;
    int si_band;
 } siginfo_t;

*************************************************************************************************/


void handler(int signum, siginfo_t * info, void * context)
{
    if(signum == SIGUSR1)
      {
        printf("SIGUSR1   signal: %d\n", signum);
      }
    else
      {
        printf("error\n");
      }

    
    if(context)
    {
        printf("sig pid is %d\n", (int)(info->si_pid));
        printf("sig uid is %d\n", (int)(info->si_uid));
        printf("content: %d\n", info->si_int);
        printf("content: %d\n", info->si_value.sival_int);
     }
}

int main(void)
{

    struct sigaction act; 
    act.sa_sigaction = handler;
    act.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &act, NULL);

    while(1)
    {
        sleep(10000);
    }
    return 0;
}
