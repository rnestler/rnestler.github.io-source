benchmark0: benchmark.cpp scopeguard.h scopeguardlist.h
	g++ -O0 -std=c++11 benchmark.cpp -o benchmark0

benchmark1: benchmark.cpp scopeguard.h scopeguardlist.h
	g++ -O1 -std=c++11 benchmark.cpp -o benchmark1

benchmark2: benchmark.cpp scopeguard.h scopeguardlist.h
	g++ -O2 -std=c++11 benchmark.cpp -o benchmark2

benchmark3: benchmark.cpp scopeguard.h scopeguardlist.h
	g++ -O3 -std=c++11 benchmark.cpp -o benchmark3

all: benchmark0 benchmark1 benchmark2 benchmark3

run: all
	./benchmark0
	./benchmark1
	./benchmark2
	./benchmark3
