#source file
#源文
SOURCE  := $(wildcard *.c) $(wildcard *.cpp)
OBJS    := $(patsubst %.c,%.o,$(patsubst %.cpp,%.o,$(SOURCE)))

#target you can change test to what you want
#目标文件名，输入任意你想要的执行文件名
TARGET  := xpathquery

#compile and lib parameter
#编译参数
CC      := g++
RM 	:=-rm  -fr

#-L/home/path1   -L/home/path2   -L/home/path3 
LIB_PATH:= -L/home/bocai/build/lib  
LIBLINK := -std=c++11
LIBS    :=  $(LIBLINK)  $(LIB_PATH)

#-I/home/include1   -L/home/include2   -L/home/include3 
INCPATH := -I/home/bocai/build/include    
DEFINES :=
CFLAGS  :=  -g  -Wall -O0   $(DEFINES)   $(INCPATH)  
CXXFLAGS:=  $(CFLAGS)    -DHAVE_CONFIG_H 



#i think you should do anything here
#下面的基本上不需要做任何改动了
.PHONY :all  objs clean 

all : $(TARGET)

objs : $(OBJS)

clean :
	$(RM) *~  
	$(RM) *.o
	$(RM) *.so
	$(RM) $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CXXFLAGS) -o $@  $(OBJS)  $(LIBS)  
