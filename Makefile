all:
	g++ -std=c++17 algo.cpp -o algo

test:
	chmod +x algo

clean:
	$(RM) algo
