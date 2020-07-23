CURR_DIR=$(shell pwd)
ROOTDIR=$(abspath $(CURR_DIR)/../)
export PKG_CONFIG_PATH=$(ROOTDIR)/build/lib/pkgconfig

#source file
SOURCE  := $(wildcard *.c) $(wildcard *.cpp)
OBJS    := $(patsubst %.c,%.o,$(patsubst %.cpp,%.o,$(SOURCE)))

#target you can change target to what you want
TARGET  :=libconfig

#compile and lib parameter
CC      := g++  
RM 	  :=-rm  -fr

#-L/home/path1   -L/home/path2   -L/home/path3 
LIB_PATH:= -L$(ROOTDIR)/build/lib      `pkg-config --cflags --libs glib-2.0` 
LIBLINK :=-lpthread    -lconfig
LIBS    :=  $(LIBLINK)  $(LIB_PATH)

#-I/home/include1   -L/home/include2   -L/home/include3 
INCPATH := -I$(ROOTDIR)/build/include/    -I$(ROOTDIR)/build/include/glib-2.0   -I$(ROOTDIR)/build/lib/glib-2.0/include
DEFINES :=
CFLAGS  :=  -g  -Wall -O0   $(DEFINES)   $(INCPATH)  
CXXFLAGS:=  $(CFLAGS)    -DHAVE_CONFIG_H 


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
