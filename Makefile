all: int_firstup.out int_dicho.out double_firstup.out double_dicho.out psnr.out analyse.out

int_firstup.out: int_firstup.cpp
	g++ $^ -o $@ -Wall -Wextra -g -std=c++11

int_dicho.out: int_dicho.cpp
	g++ $^ -o $@ -Wall -Wextra -g -std=c++11

double_firstup.out: double_firstup.cpp
	g++ $^ -o $@ -Wall -Wextra -g -std=c++11

double_dicho.out: double_dicho.cpp
	g++ $^ -o $@ -Wall -Wextra -g -std=c++11

psnr.out: psnr.cpp
	g++ $^ -o $@ -Wall -Wextra -g -std=c++11

analyse.out: analyse.cpp
	g++ $^ -o $@ -Wall -Wextra -g -std=c++11

clean:
	rm -f *.o

mrproper: clean
	rm -f *.out
