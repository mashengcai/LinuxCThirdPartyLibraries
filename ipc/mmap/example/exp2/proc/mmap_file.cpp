#include <stdio.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h> 

int main(int argc, char *argv[])
{
	int fd = -1;
	struct stat sb;
	char *mmaped = NULL;

	fd = open(argv[1], O_RDWR);
	if (fd < 0) {
		fprintf(stderr, "open %s fail\n", argv[1]);
		exit(-1);
	}

	if (stat(argv[1], &sb) < 0) {
		fprintf(stderr, "stat %s fail\n", argv[1]);
		goto err;
	}

	/* 将文件映射至进程的地址空间 */
	mmaped = (char *)mmap(NULL, sb.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	if (mmaped == (char *)-1) {
		fprintf(stderr, "mmap fail\n");
		goto err;
	}

	/* 映射完后, 关闭文件也可以操纵内存 */
	close(fd);

	printf("%s", mmaped);

	mmaped[5] = '$';
        
        /**
         *int msync ( void * addr , size_t len, int flags) 
         *通过调用msync()实现磁盘上文件内容与共享内存区的内容一致.
         */
	if (msync(mmaped, sb.st_size, MS_SYNC) < 0) {
		fprintf(stderr, "msync fail\n");
		goto err;
	}

	return 0;

err:
	if (fd > 0)
	{ 
		close(fd);
	}

	if (mmaped != (char *)-1)
	{
		munmap(mmaped, sb.st_size);
	}

	return -1;
}
