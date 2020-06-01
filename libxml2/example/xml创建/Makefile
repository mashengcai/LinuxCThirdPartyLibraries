VERSION	= CENTOS7
		
SCENARIOS = ./*.c

SOURCE =  $(SCENARIOS)

LIBS := -lxml2

ifeq ($(VERSION), $(filter $(VERSION), CENTOS7))		
INCLUDES =  -I ../libxml2build/include/  
LINKLIBS = -L../libxml2build/lib
endif


all: libxml2_main

libxml2_main: $(SOURCE)
	g++ -Wall -g $(SOURCE) -rdynamic -o xmlmain -fpermissive $(LIBS)  $(LINKLIBS) $(INCLUDES) 

clean:
	rm -rf  xmlmain  *.~ 

