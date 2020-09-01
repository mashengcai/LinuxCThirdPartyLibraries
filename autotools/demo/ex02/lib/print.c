#include "../include/print.h"
#include <stdio.h>
void print(char *szArg)
{
       printf("[%s %s %d] %s\n",__FILE__,__FUNCTION__,__LINE__,szArg);
}
