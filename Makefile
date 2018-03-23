all: main.cpp
	g++ main.cpp -Wall -Wextra -g -std=c++11

run:
	./a.out $(filter-out $@,$(MAKECMDGOALS))

clean:
	rm -f *.o

mrproper: clean
	rm -f *.out
