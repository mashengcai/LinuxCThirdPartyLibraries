#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int startsWith(const char* c_szParent,const char* c_szChild)
{
   unsigned int  iLen[2]={0};
   iLen[0]=strlen(c_szParent);
   iLen[1]=strlen(c_szChild);
   if((iLen[0] <=0) ||  (iLen[1] <=0) )
   {
      return -1;
   }
   if(0 == strncmp(c_szParent,c_szChild,iLen[1]))
   {
       return 0;
   }
   return -1;
}

int endsWith(const char* c_szParent,const char* c_szChild)
{
   unsigned int  iLen[2]={0};
   iLen[0]=strlen(c_szParent);
   iLen[1]=strlen(c_szChild);
   if((iLen[0] <=0) ||  (iLen[1] <=0) )
   {
      return -1;
   }
   if(0 == strncmp(c_szParent+iLen[0]-iLen[1],c_szChild,iLen[1]))
   {
       return 0;
   }
   return -1;
}

int main(int argc,char *argv[])
{
   const  char* str="Chain INPUT (policy ACCEPT)\
target     prot opt source               destination  ";

printf("%d\n",startsWith(str,"Chain"));
printf("%d\n",startsWith(str,"hain"));
printf("%d\n",endsWith(str,"destination"));
printf("%d\n",endsWith(str,"destination  "));
}
