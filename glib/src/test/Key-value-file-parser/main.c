#include <stdio.h>
#include <stdlib.h>
#include <glib.h>
#include <string.h>
#include <glib/gprintf.h>
/*****************************************
配置文件的格式如下：
[组名]
#注释
Key = value
#注释
Key = value
#注释
Key = value
#注释
Key = value
#注释
Key = value
#注释
Key = value
******************************************/
/*
文档名字
glib-Key-value-file-parser.html
glib-Strings.html
glib-String-Utility-Functions.html
glib-File-Utilities.html
glib-Basic-Types.html
glib-Miscellaneous-Utility-Functions.html

参考链接:https://blog.csdn.net/FlayHigherGT/article/details/84026124

*/
static GKeyFile* configure_open_file(const gchar *filename)
{
        GError *err = NULL;
        GKeyFile *keyfile;
        keyfile = g_key_file_new ();
        g_key_file_set_list_separator (keyfile, ',');
        if (!g_key_file_load_from_file (keyfile, filename, G_KEY_FILE_NONE, &err)){
                g_error_free (err);
                g_key_file_free (keyfile);
                return NULL;
        }

        return keyfile;
}


static void configure_read_string (GKeyFile *keyfile, GString *ret,const gchar *group_name,const gchar *key,const gchar *default_val)
{
        GError *err = NULL;
        gchar* val = g_key_file_get_string (keyfile,group_name, key,&err);
        if (err)
        {
                g_string_assign (ret, default_val);
                g_error_free (err);
                return;
        }

        g_string_assign (ret, val);
        g_free (val);
}


static gint configure_read_int(GKeyFile *keyfile, const gchar *group_name,const gchar *key, gint default_val)
{
        GError *err = NULL;
        int val = g_key_file_get_integer (keyfile, group_name,key,&err);
        if (err){
                g_error(err->message);
                g_error_free(err);
                return default_val;
        }

        return val;
}

// g_printf("[file:%s  function:%s  line:%d] \n  welcome \n\n",__FILE__,__FUNCTION__,__LINE__);
int main(int argc,char *argv[])
{
    GError *error = NULL;
    gchar **keys = NULL;
    gsize  nkeys=0; /*typedef  unsigned long int gsize*/

    GKeyFile *keyfile= configure_open_file("test.conf");

    /*读取配置文件的general类别有几个小字段*/
    keys = g_key_file_get_keys(keyfile, "general", &nkeys, &error);
    g_print("nkeys[%lu]\n", nkeys);

    for (gsize index = 0; index < nkeys; ++index) {
        g_print(" keys[%lu] = %s\n", index,keys[index]);
    }

    /*========================================*
     [module]
     network=www.xijidunmogu.com
     mail=outlook
     ------------------------------------------
     *获取module组下:
     *network键的字符串值:www.xijidunmogu.com
     *mail键的字符串值:outlook
     *========================================*/
    
    gchar *szStr = g_key_file_get_string(keyfile, "module", "network", &error);
    g_print("network[%s]\n", szStr);
    g_free(szStr);
    szStr = g_key_file_get_string(keyfile, "module", "mail", &error);
    g_print("mail[%s]\n", szStr);
    g_free(szStr);
    
    GString *pGStrNetwork = g_string_new ("");
    configure_read_string(keyfile,pGStrNetwork,"module", "network","default");
    g_print("pGStrNetwork->str=[%s]\n", pGStrNetwork->str);
    g_string_free (pGStrNetwork, TRUE);


   
    /*========================================*
     [STARTUP]
     xpoint=300
     ypoint=600
     center=true
     timestamp=1314432584
     random=0.78204092288815774
     ------------------------------------------
     *获取STARTUP组下:
     *xpoint、ypoint键的值:300 、600
     *center键的布尔值:true
     *========================================*/
      gchar* szXPoint= g_key_file_get_value(keyfile,"STARTUP","xpoint", &error);
      gchar* szYPoint= g_key_file_get_value(keyfile,"STARTUP","ypoint", &error);
      g_print("szXPoint[%s] szYPoint[%s]\n",szXPoint,szYPoint);
  
      /**
       #define FALSE (0)
       #define TRUE (!FALSE) 
       */
      gboolean bCenter = g_key_file_get_boolean(keyfile,"STARTUP","center",&error);
      g_print("bCente r[%d]\n",bCenter);
     
      gint iTimestamp = g_key_file_get_integer(keyfile,"STARTUP","timestamp",NULL);/*&error:NULL*/
      g_print("iTimestamp [%d]\n",iTimestamp);

      gint iFlag=configure_read_int(keyfile,"STARTUP","flag",0);
      g_print("iFlag [%d]\n",iFlag);

      gdouble dVandom = g_key_file_get_double(keyfile,"STARTUP","random",NULL);/*&error:NULL*/
      g_print("dVandom [%0.17f]\n",dVandom);

     /*========================================*
      [PATH]
      bin_path=/bin;/sbin;/usr/bin;/usr/local/bin;/home/jcodeer/bin; 
      ------------------------------------------
      *获取PATH组下:
      *bin_path键的列表值:/bin;/sbin;/usr/bin;/usr/local/bin;/home/jcodeer/bin;
      *========================================*/
      gsize length;
      gchar**  ppBinPath = g_key_file_get_string_list(keyfile,"PATH","bin_path",&length,&error);
      g_print("ppBinPath [");
      for(gsize i = 0; i < length;i++){
        g_print("%s",ppBinPath[i]);
      }
      g_print("]\n");

     /*========================================*
      *写配置文件
      *========================================*/
      /*[1]写配置到keyfile中*/
      g_key_file_set_boolean(keyfile, "info", "enable", 1);/*true:1  flase:0*/
      g_key_file_set_string(keyfile, "info", "ip", "255.255.255.255");
      
      /*[2]keyfile写入配置文件*/
      gchar*  szConfContent=NULL;
      
      g_clear_error(&error);

    if ((szConfContent = g_key_file_to_data(keyfile, NULL, &error)) == NULL ||
        (!g_file_set_contents("test.conf", szConfContent, -1, &error))) 
      {
        g_error_free(error);
        error = NULL;
    }


      g_key_file_free (keyfile);


return 0;
}

