#GCC = g++ -O3 -Wall -std=c++11
CFLAGS = -O3 -pipe -Wall -std=c++11
FRONTEND =
BACKEND =
LIBS = 

ifeq ($(BACKEND), SQL)
LIBS += -lsqlite3 -ldl -lm -lz -lpthread
CFLAGS += -DUSE_SQL
else
		
endif

ifeq ($(FRONTEND), VULKAN)
		
else
LIBS += -lncurses
endif

SRC = $(wildcard *.cc)
OBJ = $(SRC:.cc=.o)
DEP = $(wildcard *.h)

.PHONY: clean todo debug doc format

Closet++: $(OBJ)
	$(CXX) $(CFLAGS) -o $@ $^ $(LIBS)

%.o : %.cc #$(DEP)
	$(CXX) $(CFLAGS) -c $< -o $@ $(LIBS)

clean:
	$(RM) Closet++{,-*} *.o *.gch *~ *Closet.txt *.clo *.log *.i *.db

todo:
	@vim TODO.md

debug: $(OBJ)
	$(GCC) $(LIBS) -g -o Closet++ $(OBJ)
	gdb Closet++

doc: format
	doxygen closetPlusPlussDocs.conf

format: $(SRC) $(DEP)
	clang-format -i -style=Google $^
