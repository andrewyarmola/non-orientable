REFINEOBJS= MomRefine.o BallSearch.o TestCollection.o Box.o ImpossibleRelations.o ACJ.o Params.o SL2C.o SL2CI.o SL2ACJ.o SL2ACJI.o Complex.o roundoff.o CanonicalName.o QuasiRelators.o
TREECATOBJS= treecat.o
CPLUSPLUS= g++
CC= g++

COPTS=-O4

.cpp.o:
	$(CPLUSPLUS) $(COPTS) $(CCFLAGS) -c ${@:o=cpp}

.C.o:
	$(CC) $(COPTS) $(CCFLAGS) -c ${@:o=C}

refine: $(REFINEOBJS)
	$(CPLUSPLUS) $(COPTS) $(REFINEOBJS) $(LIBS) -lm -o ../bin/refine_non_orientable

treecat: $(TREECATOBJS)
	$(CPLUSPLUS) $(COPTS) $(TREECATOBJS) -o ../bin/treecat
