OBJS = main.o inputLoop.o map.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)
FILENAME = maze

$(FILENAME) : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(FILENAME)

main.o : main.cpp inputLoop.h inputLoop.cpp 
	$(CC) $(CFLAGS) main.cpp

inputLoop.o : inputLoop.h inputLoop.cpp map.h map.cpp 
	$(CC) $(CFLAGS) inputLoop.cpp

map.o : map.h map.cpp 
	$(CC) $(CFLAGS) map.cpp

clean:
	del *.o  *~ $(FILENAME).exe
