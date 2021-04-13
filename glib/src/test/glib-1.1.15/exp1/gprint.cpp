#include <stdio.h>
#include <string.h>
#include "glib.h"
int main (int   argc,char *argv[])
{
    g_print ("[%s:%s:%d] glib config  test info : %s\n", __FILE__,__FUNCTION__,__LINE__, "hello world!");
    return 0;
}
