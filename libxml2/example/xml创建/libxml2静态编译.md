<h1 align="center">libxml2静态编译</h1>
<pre>
(1)静态编译到指定目录下
 [root@localhost libxml2-2.9.10]# ./configure  --prefix=/root/libxml2build/	--silent	--enable-static	--enable-shared=no	LIBS=-L/root/libxml2build/lib 	CPPFLAGS=-I/root/libxml2build/include

 [root@localhost libxml2-2.9.10]# make   -j4
 [root@localhost libxml2-2.9.10]# make  install

(2)常见问题：缺少Python.h头文件
libxml2-2.9.10.tar.gz 源代码编译
libxml.c:14:20: 致命错误：Python.h：没有那个文件或目录
#include &lt;Python.h&gt;
[root@localhost libxml2-2.9.10]# yum install python-devel   -y
</pre>
