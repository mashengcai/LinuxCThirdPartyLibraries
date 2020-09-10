#include <stdio.h>
#include <string.h>
int main(int argc,char *argv[] )
{
    char szStr[] = "abc edf ghi,jkl * mno/pqr";
    const char *delim=" ,*/";
    char *pStr=NULL;
    pStr=strtok(szStr,delim);
    while(pStr != NULL)
    {
        printf("[%s %d] %s\n",__FUNCTION__,__LINE__,pStr);
        pStr=strtok(NULL,delim);
    }

    return 0;
}
