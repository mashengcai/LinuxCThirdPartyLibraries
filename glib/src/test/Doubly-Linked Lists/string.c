#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <glib.h>
#include <string.h>
#include <glib/gprintf.h>
#include <iostream>
using namespace std;

void display_list(GList *list){

GList *item = NULL;       

printf("Total:%u\n", g_list_length(list));

for(item = list; item != NULL; item = g_list_next(item)) {
   char*   pStuPolicyNode=(char*)(item->data);
   gint    index=g_list_index(list,(gconstpointer)pStuPolicyNode); 
   printf("[%d] [%s]\n", index,pStuPolicyNode);   
 }  
}



int main(void)
{
    GList *list=NULL;
    std::string aData="aaaaaaaaaaaaa";

    int iLen=strlen(aData.c_str());

    char*  szA=(char*)calloc(1,iLen*sizeof(char)+1);
     memcpy(szA,aData.c_str(),iLen);
    list = g_list_append(list, szA);

    std::string bData="bbbbbbbbbbbbbb";
    iLen=strlen(bData.c_str());
    char*  szB=(char*)calloc(1,iLen*sizeof(char)+1);
    memcpy(szB,bData.c_str(),iLen);
    list = g_list_append(list, szB);
    display_list(list);
    g_list_free(list); 

    return 0;

}
