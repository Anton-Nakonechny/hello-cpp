
all: hello main interqiew interqiew2 interqiew3 interqiew4 unreferenced_param

hello:hello-world.cpp
		g++ -o hello hello-world.cpp
Date.o: Date.cpp Date.h
		g++ -c Date.cpp
main: main.cpp Date.o
		g++ main.cpp Date.o -o main
unreferenced_param: unreferenced_param.c
		gcc $< -o $@
%: %.cpp
		g++ $< -o $@
PHONY : clean
clean:
		rm hello main
