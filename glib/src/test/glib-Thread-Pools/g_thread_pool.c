#include <glib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <glib/gprintf.h>

#define MAX_THREAD_NUM 5

/*全局锁*/
static GStaticMutex g_lock;



void handle(gpointer arg, gpointer data)

{

   g_static_mutex_lock(&g_lock);
   g_printf("[file:%s  function:%s  line:%d] arg[%s] data[%s]\n",__FILE__,__FUNCTION__,__LINE__,(char*)arg,(char*)data);
   g_static_mutex_unlock(&g_lock);

   g_printf("thread[%lu] is running...\n\n\n",pthread_self());
   sleep(5);



}

int main(int argc,char *argv[])
{ 
    const char *szArg = "thread example";
    const char *szData = "thread_pool example";
    GError *error=NULL;
    GThreadPool *thread_pool;

    g_static_mutex_init(&g_lock);

    /**
    *[1]
    * If you use GLib from more than one thread,
    * you must initialize the thread system by calling g_thread_init().
    * Most of the time you will only have to call g_thread_init (NULL).
    *
    *[2]To use g_thread_init() in your program, you have to link with the libraries that the command pkg-config --libs gthread-2.0 outputs.
    *This is not the case for all the other thread related functions of GLib.
    * Those can be used without having to link with the thread libraries.
    */

    g_thread_init(NULL);
    thread_pool = g_thread_pool_new(handle, (gpointer)szData,MAX_THREAD_NUM,TRUE,&error);
    if (NULL == thread_pool)
    {
        printf("g_thread_pool_new failed:%s!\n",error->message);
        return -1;

    }

    for (int idx=0; idx < 10; idx++)
    {
        g_thread_pool_push(thread_pool, (gpointer)szArg, &error);
    }

     if(NULL != error)
     {
        printf("[file:%s  function:%s  line:%d] failed:%s!\n",__FILE__,__FUNCTION__,__LINE__,error->message);
     }

    gint   g_thread_num =  g_thread_pool_get_max_threads(thread_pool);



    printf("Max number in the pthread pool: %d\n", g_thread_num);

    g_thread_pool_free(thread_pool, FALSE, TRUE);
    g_static_mutex_free(&g_lock);


    return 0;
}

