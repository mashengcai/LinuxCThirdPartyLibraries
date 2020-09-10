#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>



/**
标准的空白字符包括：
' '     (0x20)    space (SPC) 空格符
'\t'    (0x09)    horizontal tab (TAB) 水平制表符
'\n'    (0x0a)    newline (LF) 换行符
'\v'    (0x0b)    vertical tab (VT) 垂直制表符
'\f'    (0x0c)    feed (FF) 换页符
'\r'    (0x0d)    carriage return (CR) 回车符
windows: \r\n
linux: \n
mac: \r
**/
/*去除尾空格*/
char *trim_tail_space(char *str)
{
	if (str == NULL || *str == '\0')
	{
		return str;
	}

	int len = strlen(str);
	char *p = str + len - 1;
	while (p >= str  && isspace(*p))
	{
		*p = '\0';
		--p;
	}

	return str;
}


/*去除首部空格*/
char *trim_head_space(char *str)
{
	if (str == NULL || *str == '\0')
	{
		return str;
	}

	int len = 0;
	char *p = str;
	while (*p != '\0' && isspace(*p))
	{
		++p;
		++len;
	}

	memmove(str, p, strlen(str) - len + 1);

	return str;
}

/*去除首尾空格*/
char *trim(char *str)
{
	str = trim_head_space(str);
	str = trim_tail_space(str);

	return str;
}

void demo()
{

	char stra[] = "\t  \n  \v  \f  \r  \r\naa   bb  ";
	printf("before string:[%s]\n", stra);
	char *reta = trim_head_space(stra);
	printf("after string:[%s]\n", reta);

	char strb[] = " aa   bb\t  \n  \v  \f  \r  \r\n    ";
	printf("before string:[%s]\n", strb);
	char *retb = trim_tail_space(strb);
	printf("after string:[%s]\n", retb);


	char str[] = "\t  \n  \v  \f  \r  \r\n  ab  cd  \t  \n  \v  \f  \r  \r\n  ";
	printf("before trim:[%s]\n", str);
	char *ret = trim(str);
	printf("after trim:[%s]\n", ret);

}


int  main(int  argc,char*  argv[]) {
	demo();
	return  0;
}