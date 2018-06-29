GCC = g++ -O3 -Wall -std=c++11 -lncurses

A = main.o
C = myCloset.o
S = shirt.o
P = pants.o
B = belt.o
Sh = shoes.o
So = socks.o

.PHONY: clean todo

Closet++: $A $C $S $P $B $(Sh) $(So)
	$(GCC) -s -o Closet++ $A $C $S $P $B $(Sh) $(So)

main.o: main.h main.cc
	$(GCC) -c main.cc

myCloset.o: myCloset.h myCloset.cc
	$(GCC) -c myCloset.cc

shirt.o: shirt.h shirt.cc
	$(GCC) -c shirt.cc

pants.o: pants.h pants.cc
	$(GCC) -c pants.cc

belt.o: belt.h belt.cc
	$(GCC) -c belt.cc

shoes.o: shoes.h shoes.cc
	$(GCC) -c shoes.cc

socks.o: socks.h socks.cc
	$(GCC) -c socks.cc

clean:
	$(RM) Closet++ *.o *.gch *~ *Closet.txt *.clo *.log

todo:
	@vim TODO
