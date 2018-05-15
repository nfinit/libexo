### PWB MAKEFILE ###
# Use this makefile or the 'makepwb' script in the root directory
# to build the workbench tools
CC=cc
IDIR=../include
LDIR=../lib
BDIR=../bin
LIBS=-lm
CFLAGS=-I$(IDIR)

SPECTYPE=tools/spectype.o utils/stars.o utils/units.o
TC=tools/tc.o utils/units.o

all: spectype tc rmobj
spectype: $(SPECTYPE)
		$(CC) -o spectype $(SPECTYPE:.o=.c) $(CFLAGS) $(LIBS)
		mkdir -p $(BDIR)
		mv spectype $(BDIR)
tc: $(TC)
		$(CC) -o tc $(TC:.o=.c) $(CFLAGS) $(LIBS)
		mkdir -p $(BDIR)
		mv tc $(BDIR)
rmobj:
	rm -f *.o
	rm -f tools/*.o
rmbin:
	rm -rf $(BDIR)
clean: rmobj rmbin
