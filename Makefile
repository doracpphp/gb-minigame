GBDK_HOME = ./

LCC = $(GBDK_HOME)bin/lcc
PROJECTNAME = HelloWorld

BINS	    = $(PROJECTNAME).gb
CSOURCES := $(wildcard $(GBDK_HOME)src/*.c)
ASMSOURCES := $(wildcard $(GBDK_HOME)src/*.s)

all:	$(BINS)

$(BINS):	$(CSOURCES) $(ASMSOURCES)
	$(LCC) -o $@ $(CSOURCES) $(ASMSOURCES)

clean:
	rm -f *.o *.lst *.map *.gb *.ihx *.sym *.cdb *.adb *.asm