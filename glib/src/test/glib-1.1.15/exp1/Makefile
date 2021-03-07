############################################################################################
# Description	:Makefile for building: glib
# Author	:xxx
# Date  	:2021-3-6
# Version	:glib-1.1.15
# Cmd		:./configure --prefix=$(INSTALL_DIR) --enable-static=yes --enable-shared=no  			
############################################################################################


PWD=$(shell pwd)
ROOTDIR=$(abspath $(PWD)/../)

############################################################################################
#Version greater than 2.0
#export PKG_CONFIG_PATH=$(ROOTDIR)/build/lib/pkgconfig
############################################################################################

####################Compiler, tools and options#############################################
#target you can change target to what you want
TARGET  := gprint

#source file
SOURCE  := $(wildcard *.c) $(wildcard *.cpp)
OBJS    := $(patsubst %.c,%.o,$(patsubst %.cpp,%.o,$(SOURCE)))

#compile and lib parameter
CC      := g++
RM 		:=-rm  -fr

#-L/home/path1   -L/home/path2   -L/home/path3 
############################################################################################
#Version greater than 2.0
#LIB_PATH:= -L$(ROOTDIR)/build/lib   `pkg-config --cflags --libs glib-2.0` 
############################################################################################
LIB_PATH:= -L$(ROOTDIR)/build/lib/  
LIBLINK := -lglib
LIBS    :=  $(LIB_PATH)  $(LIBLINK) 
INCPATH := -I$(ROOTDIR)/build/include/   -I$(ROOTDIR)/build/lib/glib/include  
DEFINES :=
CFLAGS  := -g  -Wall -O0   $(DEFINES)   $(INCPATH)  
CXXFLAGS:= $(CFLAGS)    -DHAVE_CONFIG_H 


.PHONY 	:all  objs clean 

all 	: $(TARGET)

objs 	: $(OBJS)

clean	:
	$(RM) *~  
	$(RM) *.o
	$(RM) *.so
	$(RM) $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CXXFLAGS) -o $@  $(OBJS)  $(LIBS)  
