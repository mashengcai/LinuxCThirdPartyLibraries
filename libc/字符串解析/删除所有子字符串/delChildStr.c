#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
char *filter(char *str, char *word)
{
 char *addr[2]={NULL};
 char *src, *dst;
 if (str == NULL || *str == '\0')
 {
     return  NULL;
 }

 if (word == NULL || *word == '\0')
 {
     return  NULL;
 }

 dst = src = str;

 while(*src != '\0')
 {
   addr[0] = src;
   addr[1]  = word;
   while((*addr[0] == *addr[1]) && (*addr[1] != '\0'))
   {
       addr[0]++;
       addr[1]++;
   }

   if (*addr[1] == '\0')
   {
       src = addr[0] ;
   }
   else
   {
       *dst++ = *src++;
   }  
 }

 *dst = '\0';
 return str;

}
 
int main(int argc, char *argv[])
{
   // char str[] = "The food is good!";
    char str[] = "Thefoodi";
    char word[] = "oo";
    printf("%s\n", filter(str, word));
    printf("end symbol:%c\n", *(str+6));
    printf("unit val:%c\n", *(str+7));
    printf("length:%d\n", strlen(str));
    return 0;
}
