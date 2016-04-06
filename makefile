#NAME: Mike Sadowski
#DATE:
#STUDENT ID: 0864810
#ASSIGNEMNT:

programname = program
output = main
files = main.c

compiler = gcc
flags = -Wall

all: clean $(programname)
	
$(programname): start Utilities.o
	$(compiler) $(flags) $(files) ./$(programname)/*.o -o $(output)
	mv $(output) $(programname)

Utilities.o:
	gcc -c -Wall ./Utilities/*.c
	mv *.o ./$(programname)

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
