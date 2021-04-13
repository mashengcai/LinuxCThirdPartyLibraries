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
	char *pchMap=NULL;

	pchMem=(char*)malloc(SIZE*sizeof(char));
	/* 为了保证这里工作正常，参数传递的文件名最好是一个文本文件 */
	iFd = open(argv[1], O_RDONLY, S_IRUSR | S_IWUSR);
	lseek(iFd, 0, SEEK_SET);
	/**
	 *建立内存映射 PROT_READ: 允许读 ; 
         *MAP_PRIVATE :不允许其它进程访问此内存区域 
         */
	pchMap = (char *)mmap(NULL, sizeof(pchMem), PROT_READ,MAP_SHARED,iFd, 0);

	close(iFd);

	memcpy(pchMem,pchMap,strlen(pchMap));

        /* 使用映射区域. */
	printf("[file:%s fun:%s line:%d]pchMem[%s]\n",__FILE__,__FUNCTION__,__LINE__,pchMem);

	munmap(pchMap, sizeof(pchMem));
	return 0;
}
