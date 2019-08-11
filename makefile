### LIBEXO MAKEFILE -------------------------------------------------------- ###
CC=cc -Aa
OFLAGS=+O2
LFLAGS=-lm
# ---------------------------------------------------------------------------- #
SDIR=./src
IDIR=./include
LDIR=./lib
ODIR=./obj
BDIR=./bin
# ---------------------------------------------------------------------------- #
DFLAGS=-I$(IDIR) -L$(LDIR)
CFLAGS=$(OFLAGS) $(LFLAGS) $(DFLAGS)
# ---------------------------------------------------------------------------- #
FRONTEND=./frontend
FRONTEND_CLI=$(FRONTEND)/cli
# ---------------------------------------------------------------------------- #
MATH=$(SDIR)/math
UTIL=$(SDIR)/util
UTIL_GEN=$(UTIL)/general
UTIL_AST=$(UTIL)/astro
# ---------------------------------------------------------------------------- #
MATH_OBJ=$(MATH)/orbits.o $(MATH)/gravity.o $(MATH)/stars.o
UTIL_OBJ_GENERAL=$(UTIL_GEN)/units.o
UTIL_OBJ_ASTRO=$(UTIL_AST)/star_utils.o
# ---------------------------------------------------------------------------- #
ORBIT_FRONTEND_IN=$(FRONTEND_CLI)/orbit.c
SPECTYPE_FRONTEND_IN=$(FRONTEND_CLI)/spectype.c
TC_FRONTEND_IN=$(FRONTEND_CLI)/tc.c
MC_FRONTEND_IN=$(FRONTEND_CLI)/mc.c
BCV_FRONTEND_IN=$(FRONTEND_CLI)/bcv.c
# ---------------------------------------------------------------------------- #
all: libs cli
cli: spectype_cli orbit_cli tc_cli mc_cli bcv_cli
spectype_cli: libs
	$(CC) $(CFLAGS) $(LFLAGS) $(SPECTYPE_FRONTEND_IN) -lexo -o spectype
	mv spectype $(BDIR) 
orbit_cli: libs
	$(CC) $(CFLAGS) $(LFLAGS) $(ORBIT_FRONTEND_IN) -lexo -o orbit 
	mv orbit $(BDIR) 
tc_cli: libs
	$(CC) $(CFLAGS) $(LFLAGS) $(TC_FRONTEND_IN) -lexo -o tc
	mv tc $(BDIR) 
mc_cli: libs
	$(CC) $(CFLAGS) $(LFLAGS) $(MC_FRONTEND_IN) -lexo -o mc
	mv mc $(BDIR) 
bcv_cli: libs
	$(CC) $(CFLAGS) $(LFLAGS) $(BCV_FRONTEND_IN) -lexo -o bcv
	mv bcv $(BDIR) 
libs: dirs $(MATH_OBJ) $(UTIL_OBJ_GENERAL) $(UTIL_OBJ_ASTRO)
	ar -cvq libexo.a *.o 
	mv *.o $(ODIR)
	mv libexo.a $(LDIR)
dirs:
	mkdir -p $(LDIR)
	mkdir -p $(ODIR)
	mkdir -p $(BDIR)
rmobj:
	rm -rf $(ODIR) 
rmbin:
	rm -rf $(BDIR) $(LDIR)
rmisc: 
	rm -rf *.o a.out core 
clean: rmobj rmbin rmisc
