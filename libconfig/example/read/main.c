#include <stdio.h>
#include <string.h>
#include <libconfig.h>
#include <stdlib.h>
/**
https://blog.csdn.net/Rong_Toa/article/details/88138603
libconfig-1.7.2\tests
*/

#define  CFG_FILE_NAME  "testdata/network.conf"

static void cfgReadString(const char* c_szCfgFile,const char* c_szKey,char* c_szValue)
{
    config_t *pCfg =NULL;
    const char*  c_szStr=NULL;
    int iRet=-1;
    if(NULL == c_szCfgFile || 0 == strlen(c_szCfgFile))
    {
        printf("[fun:%s  line:%d ] file name error!",__FUNCTION__,__LINE__);
        return ;
    }
    if(NULL == c_szKey || 0 == strlen(c_szKey))
    {
        printf("[fun:%s  line:%d ] file key error!",__FUNCTION__,__LINE__);
        return ;
    }
    if(NULL == c_szValue)
    {
        printf("[fun:%s  line:%d ] file value error!",__FUNCTION__,__LINE__);
        return ;
    }
    pCfg= (config_t*)calloc(1,sizeof(config_t));
    config_init(pCfg);
    iRet=config_read_file(pCfg, c_szCfgFile);
    if(!iRet )
    {
        fprintf(stderr, "[%s:%d] - %s\n",config_error_file(pCfg),config_error_line(pCfg),config_error_text(pCfg));
        return ;
    }

    iRet=config_lookup_string(pCfg, c_szKey, &c_szStr);

    if(CONFIG_FALSE == iRet)
    {
        printf("[fun:%s  line:%d ] string parse error!",__FUNCTION__,__LINE__);
        config_destroy(pCfg);
        return ;
    }


    strcpy(c_szValue,c_szStr);
    config_destroy(pCfg);
}

int main(int argc,char *argv[])
{
    /*==========================[1]====================================*/
#if 0
    char  szValue[1024]={0}; 
    cfgReadString(CFG_FILE_NAME,"MAC",szValue);
    printf("[fun:%s  line:%d ] file value = %s\n",__FUNCTION__,__LINE__,szValue);
#endif
    /*==========================[2]======================================*/
#if 1
    config_t cfg;
    config_init(&cfg);
    int iRet=-1;
    int iEnable;
    int iLength;
    double dRandom;
    const char *c_szMask = NULL;
    const config_setting_t *pCfgSetFlags=NULL;/*the setting of config*/
    int iCount=-1;
    const config_setting_t *upload=NULL;


    config_set_include_dir(&cfg, "./testdata");

    iRet = config_read_file(&cfg, "./testdata/network.conf");
    if(!iRet)
    {
        printf("error: [%s:%d] - %s\n",config_error_file(&cfg),config_error_line(&cfg),config_error_text(&cfg));
    }

    iRet = config_lookup_bool(&cfg, "enabled", &iEnable);
    if(CONFIG_FALSE == iRet)/*CONFIG_TRUE:1 CONFIG_FALSE:0*/
    {
        printf("[fun:%s  line:%d ] bool parse error!\n",__FUNCTION__,__LINE__);
        return -1;
    }

    printf("[fun:%s  line:%d ] enable = %d\n",__FUNCTION__,__LINE__,iEnable);

    iRet = config_lookup_int(&cfg, "length", &iLength);
    if(CONFIG_FALSE == iRet)
    {
        printf("[fun:%s  line:%d ] int parse error!\n",__FUNCTION__,__LINE__);
        return -1;
    }

    printf("[fun:%s  line:%d ] length = %d\n",__FUNCTION__,__LINE__,iLength);

    iRet = config_lookup_float(&cfg, "random", &dRandom);
    if(CONFIG_FALSE == iRet)
    {
        printf("[fun:%s  line:%d ] float parse error!\n",__FUNCTION__,__LINE__);
        return -1;
    }

    printf("[fun:%s  line:%d ] random = %.5lf\n",__FUNCTION__,__LINE__,dRandom);


    iRet =  config_lookup_string(&cfg, "IPv6.MASK", &c_szMask);
    if(CONFIG_FALSE == iRet)
    {
        printf("[fun:%s  line:%d ] string parse error!\n",__FUNCTION__,__LINE__);
        return -1;
    }

    printf("[fun:%s  line:%d ] MASK = %s\n",__FUNCTION__,__LINE__,c_szMask);

    pCfgSetFlags= config_lookup(&cfg, "IPv6.FLAGS"); /*read a array*/
    iCount = config_setting_length(pCfgSetFlags);
    for (int idx = 0; idx < iCount; idx++) {

        printf("FLAGS[%d] = [%d]\n", idx + 1,config_setting_get_int_elem(pCfgSetFlags,idx));

    }


    /* check UPLOAD */
    upload = config_lookup(&cfg, "gateway.upload");
    if ( NULL == upload  )
    {
        fprintf(stderr, "Error: Incomplete configuration: you have to specify both #upload .\n");
         return -1;
    }

    iCount = config_setting_length(upload);
    for (int i = 0; i < iCount; i++)
    {
        config_setting_t *server = config_setting_get_elem(upload, i);
        const char *name=NULL, *addr=NULL, *type=NULL;
        int  port=-1;
        (void)config_setting_lookup_string(server, "name", &name);
        (void)config_setting_lookup_string(server, "addr", &addr);
        (void)config_setting_lookup_string(server, "type", &type);
        (void)config_setting_lookup_int(server, "port", &port);
         printf("[%d] name[%s] addr[%s] type[%s] port[%d]\n", i + 1,name,addr,type,port);

    }


    config_destroy(&cfg);
#endif

    return 0;
}

