OBJS=bo_yuan_assn5.o bo_calendar.o
DEBUG=-g
CC=g++
CFLAGS=-Wall -c $(DEBUG)
LFLAGS=-Wall $(DEBUG)
EXE=calendar

$(EXE): $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(EXE)

bo_calendar.o: bo_calendar.h bo_calendar.cpp
		$(CC) $(CFLAGS) bo_calendar.cpp

bo_yuan_assn5.o: bo_calendar.h bo_yuan_assn5.cpp
		$(CC) $(CFLAGS) bo_yuan_assn5.cpp

clean:
	rm *~ *.o $(EXE) -v
