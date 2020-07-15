#include <stdlib.h>
#include <glib.h>
#include <string.h>
#include <glib/gprintf.h>
typedef struct{
char  name[1024];
int   age;
}Msg;

void print_key_value(gpointer key, gpointer value, gpointer user_data)
{
    g_printf("[file:%s  function:%s  line:%d]  %s ---> %s\n",__FILE__,__FUNCTION__,__LINE__,(char*)key, (char*)value);
}

void free_key(gpointer data){  
    g_printf("[file:%s  function:%s  line:%d] We free value: %s \n",__FILE__,__FUNCTION__,__LINE__,(char*)data);   
    free(data);
}

void free_value(gpointer data)
{   
    g_printf("[file:%s  function:%s  line:%d] We free value: %s \n",__FILE__,__FUNCTION__,__LINE__,(char*)data);    
    free(data);
}


void print_struct_key_value(gpointer key, gpointer value, gpointer user_data)
{
    Msg pStMsg=*((Msg*)value);/*Msg *pStMsg=(Msg*)value;*/
    g_printf("[file:%s  function:%s  line:%d]  %s ---> [%s] [%d]\n",__FILE__,__FUNCTION__,__LINE__,(char*)key, pStMsg.name,pStMsg.age);
}

int main(int argc,char *argv[])
{ 

    g_printf("[file:%s  function:%s  line:%d]====[welcone  to use g_hash_table]====  \n",__FILE__,__FUNCTION__,__LINE__);
    GHashTable *table = NULL;   
    table = g_hash_table_new(g_str_hash, g_str_equal);  
    g_hash_table_insert(table, (void*)"1", (void*)"one"); /*typedef void* gpointer;*/
    g_hash_table_insert(table, (void*)"2", (void*)"two"); 
    g_hash_table_insert(table, (void*)"3", (void*)"three");  
    g_hash_table_insert(table, (void*)"4", (void*)"four");  
    g_hash_table_insert(table, (void*)"5", (void*)"five");
    g_hash_table_insert(table, (gpointer)"6", (gpointer)"six");	

    g_hash_table_foreach(table, print_key_value, NULL);

    g_printf("Size of hash table: %d \n", g_hash_table_size(table));
    printf("key:3 --->value:%s \n", (char*)g_hash_table_lookup(table, (gconstpointer)"3"));/*typedef const void *gconstpointer;*/

    g_hash_table_replace(table, (gpointer)"2", (gpointer)"TWO");
    g_printf("After replace key:2 --->value:%s \n", (char*)g_hash_table_lookup(table,(gconstpointer)"2"));

    g_hash_table_remove(table, (gpointer)"4");
    g_printf("Size of hash table: %d \n", g_hash_table_size(table));
    g_hash_table_foreach(table, print_key_value, NULL);
    g_hash_table_destroy(table);

    g_printf("[file:%s  function:%s  line:%d]==========================  \n",__FILE__,__FUNCTION__,__LINE__);
    table = g_hash_table_new_full(g_str_hash, g_str_equal, free_key, free_value);   
    g_hash_table_insert(table, strdup("one"), strdup("first"));    
    g_hash_table_insert(table, strdup("two"), strdup("second"));  
    g_hash_table_insert(table, strdup("three"), strdup("third"));
    g_hash_table_foreach(table, print_key_value, NULL);
    g_hash_table_remove(table, (void*)"two");
    g_hash_table_foreach(table, print_key_value, NULL);
    g_hash_table_destroy(table);
   
    Msg  stMsg={"zhang san",30};
    table = g_hash_table_new(g_str_hash, g_str_equal);  
    g_hash_table_insert(table, (gpointer)"zs", (gpointer)&stMsg); /*typedef void* gpointer;*/
    g_hash_table_foreach(table, print_struct_key_value, NULL);
    g_hash_table_destroy(table);

    return 0;
}

