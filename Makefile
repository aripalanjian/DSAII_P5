CFLAGS = -g -Wall
CC = g++

objects = main.o geneseqsim.o lcs.o matrix.o

main: $(objects)
	$(CC) -o main $(objects)

main.o: main.cpp geneseqsim.cpp lcs.cpp matrix.cpp

.PHONY : clean
clean:
	rm -f main $(objects)
	rm -f *.exe
	rm -f errReport.txt
	rm -f out.txt