all: ai_rr.out ai_rd.out ad_rr.out ad_rd.out psnr.out

ai_rr.out: ai_rr.cpp
	g++ $^ -o $@ -Wall -Wextra -g -std=c++11

ai_rd.out: ai_rd.cpp
	g++ $^ -o $@ -Wall -Wextra -g -std=c++11

ad_rr.out: ad_rr.cpp
	g++ $^ -o $@ -Wall -Wextra -g -std=c++11

ad_rd.out: ad_rd.cpp
	g++ $^ -o $@ -Wall -Wextra -g -std=c++11

psnr.out: psnr.cpp
	g++ $^ -o $@ -Wall -Wextra -g -std=c++11

clean:
	rm -f *.o

mrproper: clean
	rm -f *.out
