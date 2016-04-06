#NAME: Mike Sadowski
#DATE:
#STUDENT ID: 0864810
#ASSIGNEMNT:

programname = program
output = main
files = main.c
includes = ./header.h

compiler = gcc
flags = -Wall

all: clean $(programname)
	
$(programname): start
	$(compiler) $(flags) $(files) -o $(output)
	#$(compiler) $(flags) $(files) ./$(programname)/*.o -o $(output)
	mv $(output) $(programname)

LinkedList.o:
	gcc -c -Wall ./DataStructures/LinkedList/*.c
	mv *.o ./$(programname)
	
HashTable.o:
	gcc -c -Wall ./DataStructures/HashTable/*.c
	mv *.o ./$(programname)

start:
	mkdir $(programname)
	
clean:
	rm -rf ./$(programname)
