<h1>消息队列</h1>
<b>一、进程间通信（IPC）</b>：进程间通信的本质就是通过让不同的进程看到一份公共的资源来实现通信。
<br><br><b>二、消息队列：</b>消息队列提供了一种从一个进程向另一个进程发送一个数据块的方法，每个数据块都认为是有一个类型，接受者进程接收的数据块可以有不同的类型值。我们可以通过发送消息来避免命名管道的同步和阻塞问题。
<br>特点：
<br>(1)消息队列可认为是全局的一个链表，由消息队列标识符进行标识。 
<br>(2)消息队列允许一个或多个进程写入或读取消息。
<br>(3)消息队列的声明周期随内核。
<br>(4)消息队列可以实现双向通信。
<br><br><b>三、消息队列相关的函数：</b>
<pre>
//创建和获取 ipc 内核对象
int msgget(key_t key, int flags);
// 将消息发送到消息队列
int msgsnd(int msqid, const void *msgp, size_t msgsz, int msgflg);
// 从消息队列获取消息
ssize_t msgrcv(int msqid, void *msgp, size_t msgsz, long msgtyp, int msgflg);
// 查看、设置、删除 ipc 内核对象（用法和 shmctl 一样）
int msgctl(int msqid, int cmd, struct msqid_ds *buf);

发送消息：msgsnd() 、接收消息：magrcv()，这两个函数实现进程间的双向通信。 
</pre>
<br><b>四、消息队列查看：</b>
<pre>
ipcs  -q  查看消息队列。 
ipcrm  -q  msgid 删除此消息队列。 
</pre>

 
