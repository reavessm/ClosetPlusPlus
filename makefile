#GCC = g++ -O3 -Wall -std=c++11
CFLAGS = -O3 -pipe -Wall -std=c++11
LIBS = -lncurses -lsqlite3 -ldl -lm -lz -lpthread

SRC = $(wildcard *.cc)
OBJ = $(SRC:.cc=.o)
DEP = $(wildcard *.h)

.PHONY: clean todo debug doc format

Closet++: $(OBJ)
	@g++ $(CFLAGS) -o $@ $^ $(LIBS)

sql: $(OBJ)
	@g++ $(CFLAGS) -DSQL -o $@ $^ $(LIBS)

gui: $A $C $S $P $B $(Sh) $(So)
	$(GCC) -D VULKAN -s -o Closet++ $A $C $S $P $B $(Sh) $(So)

%.o : %.cc $(DEP)
	$(CXX) $(CFLAGS) -c $< -o $@ $(LIBS)

clean:
	$(RM) Closet++ *.o *.gch *~ *Closet.txt *.clo *.log *.i

todo:
	@vim TODO.md

debug: $(OBJ)
	$(GCC) $(LIBS) -g -o Closet++ $(OBJ)
	gdb Closet++

doc: format
	doxygen closetPlusPlussDocs.conf

format: $(SRC) $(DEP)
	clang-format -i -style=Google $^
