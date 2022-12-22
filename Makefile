all:
	g++ -std=c++17 main.cpp -o main

test:
	chmod +x main

clean:
	$(RM) main
