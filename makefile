hepsi: program calistir

Node.o:
	g++ -I "./include" -c ./src/Node.cpp -o ./lib/Node.o
DoublyLinkedList.o:
	g++ -I "./include" -c ./src/DoublyLinkedList.cpp -o ./lib/DoublyLinkedList.o
main.o:
	g++ -I "./include" -c ./src/main.cpp -o ./lib/main.o
program: Node.o DoublyLinkedList.o main.o
	g++ ./lib/Node.o ./lib/DoublyLinkedList.o ./lib/main.o -o ./bin/cikti -std=c++0x
calistir:
	./bin/cikti.exe