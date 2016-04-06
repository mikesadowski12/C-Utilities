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
	
$(programname):
	mkdir $(programname)
	$(compiler) $(flags) $(files) -o $(output)
	mv $(output) $(programname)
	
clean:
	rm -rf ./$(programname)
	
#---Create object files---
#  -c
#  mv *.o ./$(programname)
