#include<sys/msg.h>
#include<sys/ipc.h>
#include<stdio.h>
#include<string.h>
struct mymesg{
	long int mtype;
	char mtext[512];
};
int main()
{
	int id = 0;
	struct mymesg ckxmsg;
	key_t key = ftok("/tmp",0x42);
	id = msgget(key,0666|IPC_CREAT);
	if(id == -1)
	{
		printf("open msg error \n");
		return 0;
	}

	while(1)
	{
		if(msgrcv(id,(void *)&ckxmsg,512,1,0) < 0)
		{
			printf("receive msg error \n");
			return 0;
		}

		printf("data:%s\n",ckxmsg.mtext);
		
		if(strncmp(ckxmsg.mtext,"quit",4) ==0)
		{
			break;
		}
	}

	return 0;
}
