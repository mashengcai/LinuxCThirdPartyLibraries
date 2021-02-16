#include <sys/mman.h> /* for mmap and munmap */
#include <sys/types.h> /* for open */
#include <sys/stat.h> /* for open */
#include <fcntl.h>     /* for open */
#include <unistd.h>    /* for lseek and write */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define  SIZE   1024

int main(int argc, char **argv)
{
	int  iFd=-1;
	char *pchMem=NULL;
	int  iLen=0;
	char *pchMap=NULL;
	int  iRet=-1;

	pchMem=(char*)malloc(SIZE*sizeof(char));
	strcpy(pchMem,"<report><Name>zhang san li si</Name></report>");
	iLen=strlen(pchMem);

	/* 为了保证这里工作正常，参数传递的文件名最好是一个文本文件 */
	iFd = open(argv[1], O_RDWR | O_CREAT | O_TRUNC , S_IRUSR | S_IWUSR);
	lseek(iFd, iLen, SEEK_END);
	/* 在文件最后添加一个空字符，以便下面printf正常工作 */
	write(iFd, "\0", 1);
	lseek(iFd, 0, SEEK_SET);
	/*PROT_READ: 允许读 ; MAP_PRIVATE :不允许其它进程访问此内存区域 */
	pchMap = (char *)mmap(NULL, iLen, PROT_READ|PROT_WRITE,MAP_SHARED,iFd, 0);

	close(iFd);

	memcpy(pchMap,pchMem,iLen);

        /* 使用映射区域. */
	printf("[fun:%s line:%d]pchMap[%s]\n",__FUNCTION__,__LINE__,pchMap);


	/**
	 *int msync ( void * addr , size_t len, int flags) 
	 *通过调用msync()实现磁盘上文件内容与共享内存区的内容一致.
	 */
	iRet=msync(pchMap, iLen, MS_SYNC);
	if (iRet < 0) {
		fprintf(stderr, "msync fail\n");
	}


	munmap(pchMap, iLen);
	return 0;
}
