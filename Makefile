all: main.out

main.out: main.cpp
	g++ $^ -o $@ -Wall -Wextra -g -std=c++11

clean:
	rm -f *.o

mrproper: clean
	rm -f *.out
