all: build run

build:
	g++ -I ./include/ -o ./lib/tree_node.o -c ./src/tree_node.cpp
	g++ -I ./include/ -o ./lib/tree.o -c ./src/tree.cpp
	g++ -I ./include/ -o ./lib/list_node.o -c ./src/list_node.cpp
	g++ -I ./include/ -o ./lib/linked_list.o -c ./src/linked_list.cpp
	g++ -I ./include/ -o ./bin/main ./lib/tree_node.o ./lib/tree.o ./lib/list_node.o ./lib/linked_list.o ./src/main.cpp

run:
	./bin/main