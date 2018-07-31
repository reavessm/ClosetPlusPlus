GCC = g++ -O3 -Wall -std=c++11
CLFAGS = -O3 -Wall -std=c++11
LIBS = -lncurses

SRC = $(wildcard *.cc)
OBJ = $(SRC:.cc=.o)
DEP = $(wildcard *.h)

.PHONY: clean todo debug doc format

Closet++: $(OBJ)
	$(GCC) $(LIBS) -o $@ $^

gui: $A $C $S $P $B $(Sh) $(So)
	$(GCC) -D VULKAN -s -o Closet++ $A $C $S $P $B $(Sh) $(So)

%.o : %.cc $(DEP)
	$(GCC) -c $< -o $@

clean:
	$(RM) Closet++ *.o *.gch *~ *Closet.txt *.clo *.log *.i

todo:
	@vim TODO

debug: $(OBJ)
	$(GCC) $(LIBS) -g -o Closet++ $(OBJ)
	gdb Closet++

doc: format
	doxygen closetPlusPlussDocs.conf

format: $(SRC) $(DEP)
	clang-format -i -style=Google $^
