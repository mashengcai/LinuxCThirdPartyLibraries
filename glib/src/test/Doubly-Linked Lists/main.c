#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <glib.h>
#include <string.h>
#include <glib/gprintf.h>
/**
[1] https://blog.csdn.net/plusboy/article/details/1489328
[2] https://blog.csdn.net/pdw2009/article/details/43340815
[3] https://blog.csdn.net/plusboy/article/details/1489328?utm_source=blogxgwz8
*/
typedef struct {
    char szType[1024];
    char szValue[1024];
} TD_USB_NODE;

GList *list = NULL;

void display_list(GList *list){    

GList *item = NULL;    /* 遍历链表 */  
for(item = list; item != NULL; item = g_list_next(item)) {
   TD_USB_NODE*   pStuPolicyNode=(TD_USB_NODE*)(item->data);
   printf("%s    %s\n", pStuPolicyNode->szType,pStuPolicyNode->szValue);   
 }    

}

int main(void)
{
   
for(int i=0;i<3;i++){
    TD_USB_NODE   *policy=(TD_USB_NODE   *)calloc(1,sizeof(TD_USB_NODE));;
    snprintf(policy->szType,sizeof(policy->szType),"%s%d","aaaa",i);
    snprintf(policy->szValue,sizeof(policy->szValue),"%s%d","AAAA",i);
    /*
     * 向链表尾部追加节点
     */
    list = g_list_append(list, policy);
}
    display_list(list);
    g_list_free(list);
   
    return 0;

}
