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
	@echo "BUILDING: spectral classifier"
	@$(CC) $(CFLAGS) $(LFLAGS) $(SPECTYPE_FRONTEND_IN) -lexo -o spectype
	@mv spectype $(BDIR)
	@echo "*** DONE: Stored executable 'spectype' in binary directory." 
orbit_cli: libs
	@echo "BUILDING: orbit calculator"
	@$(CC) $(CFLAGS) $(LFLAGS) $(ORBIT_FRONTEND_IN) -lexo -o orbit 
	@mv orbit $(BDIR) 
	@echo "*** DONE: Stored executable 'orbit' in binary directory." 
tc_cli: libs
	@echo "BUILDING: temperature converter"
	@$(CC) $(CFLAGS) $(LFLAGS) $(TC_FRONTEND_IN) -lexo -o tc
	@mv tc $(BDIR)
	@echo "*** DONE: Stored executable 'tc' in binary directory." 
mc_cli: libs
	@echo "BUILDING: mass converter"
	@$(CC) $(CFLAGS) $(LFLAGS) $(MC_FRONTEND_IN) -lexo -o mc
	@mv mc $(BDIR) 
	@echo "*** DONE: Stored executable 'mc' in binary directory." 
bcv_cli: libs
	@echo "BUILDING: bolometric correction calculator"
	@$(CC) $(CFLAGS) $(LFLAGS) $(BCV_FRONTEND_IN) -lexo -o bcv
	@mv bcv $(BDIR) 
	@echo "*** DONE: Stored executable 'bcv' in binary directory." 
libs: dirs $(MATH_OBJ) $(UTIL_OBJ_GENERAL) $(UTIL_OBJ_ASTRO)
	@echo "BUILDING: library"
	@ar -cvq libexo.a *.o 
	@mv *.o $(ODIR)
	@mv libexo.a $(LDIR)
	@echo "*** DONE: Stored library 'libexo.a' in library directory."
dirs:
	@echo "SETUP: directories"
	@mkdir -p $(LDIR)
	@mkdir -p $(ODIR)
	@mkdir -p $(BDIR)
	@echo "*** DONE: Created library, object and binary directories."
rmobj:
	@echo "CLEAN: objects"
	@rm -rf $(ODIR) 
rmbin:
	@echo "CLEAN: binaries"
	@rm -rf $(BDIR) $(LDIR)
rmisc: 
	@echo "CLEAN: miscellaneous"
	@rm -rf *.o a.out core 
clean: rmobj rmbin rmisc
