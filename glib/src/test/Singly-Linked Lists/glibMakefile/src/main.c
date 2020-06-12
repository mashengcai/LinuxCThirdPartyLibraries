#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <glib.h>
#include <glib/gprintf.h>
/*https://blog.csdn.net/wangwenwen/article/details/7479790*/
/*GLib Reference Manual :  https://tool.oschina.net/apidocs/apidoc?api=glib*/
/*
 * g_slist_append
 * g_slist_prepend
 * g_slist_reverse
 */

static void test_slist_1(void)
{
	GSList *slist = NULL;
	GSList *st;
	gint nums[10] = {0,1,2,3,4,5,6,7,8,9};
	gint i;
       
        /*增加*/
	for (i = 0; i < 10; i++)
	{
		/**
             *GSList* g_slist_append(GSList *list, gpointer data);
             *Adds a new element on to the end of the list. 
                 */
		slist = g_slist_append(slist, &nums[i]);
	}

	g_printf("The result should be: 0,1,2,3,4,5,6,7,8,9,\n");
	        
        /*遍历*/
	for (i = 0; i < 10; i++) 
	{
            /**
          *GSList* g_slist_nthGSList *list,guint n);
          *Gets the element at the given position in a GSList. 
             */
		st = g_slist_nth(slist, i);
		g_printf("%d,", *(gint*)st->data);
	}

	g_printf("\n=========================[1]==========================\n\n");


	// GSList* g_slist_reverse(GSList *list);

	slist = g_slist_reverse(slist);

	g_printf("The result should be: 9,8,7,6,5,4,3,2,1,0,\n");

        /*遍历*/
	for (i = 0; i < 10; i++) 
	{
		st = g_slist_nth(slist, i);
		g_printf("%d,", *(gint*)st->data);
	}

	g_printf("\n=========================[2]==========================\n\n");

        /*增加*/
	for (i = 0; i < 10; i++)
	{

		/**
             *GSList* g_slist_prepend(GSList *list, gpointer data);
             *Adds a new element on to the start of the list. 
                 */
		slist = g_slist_prepend(slist, &nums[i]);
	}

	g_printf("The result should be: 9,8,7,6,5,4,3,2,1,0,9,8,7,6,5,4,3,2,1,0,\n");

        /*遍历*/
	for (i = 0; i < 20; i++) {
             st = g_slist_nth(slist, i);
		g_printf("%d,", *(gint*)st->data);
	}

	g_printf("\n=========================[3]==========================\n\n");

      g_printf("The result should be: 9,8,7,6,5,4,3,2,1,9,8,7,6,5,4,3,2,1,\n");
        
        /**
       *GSList*   g_slist_remove_all(GSList *list,gconstpointer data);
       *Removes all list nodes with data equal to data. Returns the new head of the list. 
       *Contrast with g_slist_remove() which removes only the first node matching the given data. 
         *
       *tmp=0;
       *g_slist_remove_all(slist, &tmp); 移除失败
         */
      slist = g_slist_remove_all(slist, &nums[0]);/*nums[0]=0*/

        /*遍历*/
	for (i = 0; i < (gint)g_slist_length(slist); i++) {
             st = g_slist_nth(slist, i);
		g_printf("%d,", *(gint*)st->data);
	}
      
	g_printf("\n=========================[4]==========================\n\n");

        g_printf("The result should be: 9,8,7,6,5,4,3,2,1,\n");
      
        for (i = 0; i < (gint)g_slist_length(slist); i++)
          {
            /**
          *GSList* g_slist_remove(GSList *list, gconstpointer data);
          *Removes an element from a GSList. If two elements contain the same data, only the first is removed. 
          *If none of the elements contain the data, the GSList is unchanged. 
             */
          slist = g_slist_remove(slist, &nums[i]);
          }
       
        /*遍历*/
	for (i = 0; i < (gint)g_slist_length(slist); i++) {
             st = g_slist_nth(slist, i);
		g_printf("%d,", *(gint*)st->data);
	}
       /**
      *guint               g_slist_length                      (GSList *list);
      *Gets the number of elements in a GSList. 
        **/
     g_printf("\nThe length should be 10.\t Result:%d\n", g_slist_length(slist));
     g_printf("\n=========================[5]==========================\n\n");

     g_slist_free(slist);

}

/*
 * g_slist_insert_before
 * g_slist_insert
 * g_slist_nth
 * g_slist_copy
 */

 static void   test_slist_2(void)
{
    GSList *slist = NULL;
    GSList *st;
    GSList *st2;
    gint nums[10] = {0,1,2,3,4,5,6,7,8,9};
    gint i;

// GSList* g_slist_insert_before(GSList *slist, GSList *sibling, gpointer data);

    slist = g_slist_insert_before(NULL, NULL, &nums[1]);
// GSList* g_slist_insert(GSList *list, gpointer data, gint position);

    slist = g_slist_insert(slist, &nums[3], 1);
    slist = g_slist_insert(slist, &nums[4], -1);
    slist = g_slist_insert(slist, &nums[0], 0);
    slist = g_slist_insert(slist, &nums[5], 100);
    slist = g_slist_insert_before(slist, NULL, &nums[6]);
    slist = g_slist_insert_before(slist, slist->next->next, &nums[2]);
    slist = g_slist_insert(slist, &nums[9], 7);
    slist = g_slist_insert(slist, &nums[8], 7);
    slist = g_slist_insert(slist, &nums[7], 7);

    g_printf("The result should be: 0,1,2,3,4,5,6,7,8,9\n");

    g_printf("Begin:\n");

    for (i = 0; i < 10; i++) {
// GSList* g_slist_nth(GSList *list, guint n);
        st = g_slist_nth(slist, i);
        g_printf("%d,", *(gint*)st->data);

    }

    g_printf("\nDone\n");


// GSList* g_slist_copy(GSList *list);
    st = g_slist_copy(slist);
    g_printf("The result should be: 0,1,2,3,4,5,6,7,8,9\n");
    g_printf("Begin:\n");
    for (i = 0; i < 10; i++) {
        st2 = g_slist_nth(st, i);
        g_printf("%d,", *(gint*)st2->data);
    }
    g_printf("\nDone\n");
    g_slist_free(st);
    g_slist_free(slist);
}

 

int main(void)
{
#if  0
	printf("\n------------------------------------------------------------\ntest_slist_1:\n");
	test_slist_1();
	printf("\n-----------------------------------------------------------\nDONE\n");
#endif

#if  1
	printf("\n------------------------------------------------------------\ntest_slist_2:\n");
	test_slist_2();
	printf("\n-----------------------------------------------------------\nDONE\n");
#endif

	return 0;

}
