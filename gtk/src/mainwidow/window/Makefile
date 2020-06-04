#环境变量的设置只对当前的终端窗口有效
#export PKG_CONFIG_PATH=/root/glibproject/lib/lib/pkgconfig:$PKG_CONFIG_PATH
#################################################################################
# `pkg-config --libs glib-2.0 gthread-2.0` 
# `pkg-config --cflags glib-2.0 gthread-2.0`
# `pkg-config --libs glib-2.0` 
# `pkg-config --cflags glib-2.0`
#source file
#源文
SOURCE  := $(wildcard *.c) $(wildcard *.cpp)
OBJS    := $(patsubst %.c,%.o,$(patsubst %.cpp,%.o,$(SOURCE)))

#target you can change test to what you want
#目标文件名，输入任意你想要的执行文件名
TARGET  := gtk

#compile and lib parameter
#编译参数
CC      := g++
RM 	:=-rm  -fr
LIBS    := -lpthread    
LDFLAGS :=  -L./lib     `pkg-config --libs gtk+-2.0  glib-2.0 gthread-2.0` 
DEFINES :=
INCLUDE :=  -I./lib/include/glib-2.0
CFLAGS  := -g -Wall -O0 $(DEFINES) $(INCLUDE)   `pkg-config --cflags gtk+-2.0  glib-2.0   gthread-2.0`
CXXFLAGS:= $(CFLAGS) -DHAVE_CONFIG_H

#I think you should do anything here
.PHONY :all  objs clean 

all : $(TARGET)

objs : $(OBJS)
	
clean :
	$(RM) *~  
	$(RM) *.o
	$(RM) *.so
	$(RM) $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CXXFLAGS)   -o $@ $(OBJS) $(LDFLAGS) $(LIBS)

