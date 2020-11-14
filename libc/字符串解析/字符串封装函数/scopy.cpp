#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void *xmalloc (size_t size)
{
  register void *value = malloc (size);
  if (value == 0) {
    fprintf(stderr,"tree: virtual memory exhausted.\n");
    exit(1);
  }
  return value;
}

#define scopy(x)	strcpy((char*)xmalloc(strlen(x)+1),(x))

int main(int argc,char* argv[])
{
     const   char* sz_str="1111111111111111";
     char  szBuf[1024]={0};
     strcpy(szBuf,"2222222222222");
     char*  sz_ret=scopy(sz_str);
     printf("[1][%s]\n",sz_ret);
     free(sz_ret);
     sz_ret=scopy(szBuf);
     printf("[2][%s]\n",sz_ret);
     free(sz_ret);
     return 0;
}
