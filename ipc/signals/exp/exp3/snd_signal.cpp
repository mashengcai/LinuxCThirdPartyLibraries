#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include  <unistd.h>

int main(int argc, char* argv[])
{
     int iPid=atoi(argv[1]);
     kill(iPid,SIGUSR1);

}
