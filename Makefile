all: 
	clang-format -style=google -i ./src/main.cpp
	g++ -o bin/calendar ./src/main.cpp
.PHONY:clean
clean:
	g++ -g -o bin/calendar ./src/main.cpp
