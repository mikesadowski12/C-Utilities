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
	
$(programname): start LinkedList.o
	$(compiler) $(flags) $(files) -o $(output)
	#$(compiler) $(flags) $(files) ./$(programname)/*.o -o $(output)
	mv $(output) $(programname)

LinkedList.o:
	gcc -c -Wall ./2DataStructures/1LinkedList/*.c
	mv *.o ./$(programname)
	
HashTable.o:
	gcc -c -Wall ./2DataStructures/1HashTable/*.c
	mv *.o ./$(programname)

start:
	mkdir $(programname)
	
clean:
	rm -rf ./$(programname)
