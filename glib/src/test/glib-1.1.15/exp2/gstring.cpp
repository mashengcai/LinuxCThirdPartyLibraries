#include <stdio.h>
#include <string.h>
#include "glib.h"

#define	GDBUG(m,gboolvalue)	G_STMT_START {\
	if (gboolvalue) \
	{ if (!m) \
		g_print ("\n(%s:%s:%d): %s\n", __FILE__,__FUNCTION__,__LINE__, ( # gboolvalue )); \
		else \
		g_print ("\n(%s:%s:%d): %s: (%s)\n", __FILE__,__FUNCTION__,__LINE__, ( # gboolvalue ), (gchar*)m); \
	} \
	else \
	g_print (".\n"); fflush (stdout); \
} G_STMT_END



int main (int   argc,char *argv[])
{
	/*GString:指针只声明,不用初始化*/
	GString *ptGStr1,*ptGStr2;

	/*GString:内存开辟*/
	ptGStr1 = g_string_new ("welcome  g_string_new!");
	ptGStr2 = g_string_new ("");


	g_print ("(%s:%s:%d) str: %s\tlen:%d\n", __FILE__, __FUNCTION__,__LINE__,ptGStr1->str,ptGStr1->len);
	GDBUG(ptGStr1->str, TRUE);
	GDBUG(ptGStr2->str, TRUE);


	g_assert (ptGStr1 != NULL);
	g_assert (ptGStr2 != NULL);
	g_assert (strlen (ptGStr1->str) == (guint)(ptGStr1->len));
	g_assert (strlen (ptGStr2->str) == (guint)(ptGStr2->len));
	g_assert (ptGStr2->len == 0);
	g_assert (strcmp ("welcome  g_string_new!", ptGStr1->str) == 0);
	g_assert (strcmp ("", ptGStr2->str) == 0);

	/*GString:字符追加*/
	(void*)g_string_append_c(ptGStr2,'h');
	ptGStr2=g_string_append_c(ptGStr2,'e');

	/*GString:字符串追加*/
	(void*)g_string_append(ptGStr2,g_string_new ("llo")->str);
	ptGStr2=g_string_append(ptGStr2,g_string_new (" world!")->str);

	GDBUG(ptGStr2->str, TRUE);

	/*%100.12f  :整数占位：100 ,小数点后占位12 */
	g_string_sprintf (ptGStr1, "%s|%010d|%s|%s|%0*d|%*.*f|%100.12f",
			"this pete guy sure is a wuss, like he's the number ",
			1,
			" wuss.  everyone agrees.\n",
			ptGStr1->str,
			10, 666, 15, 15, 666.666666666, 666.666666666);

	GDBUG(ptGStr1->str, TRUE);

	/*GString:哈希数值(哈希值是一段数据唯一且极其紧凑的数值表示形式)*/
	guint  ghash=g_str_hash(ptGStr1->str);
	g_print ("(%s:%s:%d) hash:%32u\n", __FILE__, __FUNCTION__,__LINE__,ghash);


	/*GString:删除*/
	GDBUG(ptGStr2->str, TRUE);
	g_string_erase(ptGStr2,5,ptGStr2->len -5);
	GDBUG(ptGStr2->str, TRUE);
	g_string_erase(ptGStr2,0,ptGStr2->len );
	GDBUG(ptGStr2->str, TRUE);



	/*GString:内存释放*/
	g_string_free(ptGStr1,TRUE);
	g_string_free(ptGStr2,TRUE); 

	return 0;
}
