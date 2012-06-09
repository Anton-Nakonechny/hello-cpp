
all: hello main interqiew

interqiew:interqiew.cpp
		g++ -o interqiew interqiew.cpp
hello:hello-world.cpp
		g++ -o hello hello-world.cpp
main: main.cpp Date.o
		g++ -o main main.cpp Date.o
Date.o: Date.cpp Date.h
		g++ -c Date.cpp
PHONY : clean
clean:
		rm hello main
