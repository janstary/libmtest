LDFLAGS	= -lm
CFLAGS	= -std=c99 -Wall -pedantic
TESTS	= test-rintf test-rint
OBJS	= utils.o

all: $(TESTS)

test: all
	for t in $(TESTS) ; do ./$$t ; done

test-rintf: test-rintf.c test-rintf.h test-func.h test-func.c $(OBJS)
	cp test-rintf.h which.h
	$(CC) $(CFLAGS) -c test-rintf.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ test-func.c test-rintf.o $(OBJS)

test-rint: test-rint.c test-rint.h test-func.h test-func.c $(OBJS)
	cp test-rint.h which.h
	$(CC) $(CFLAGS) -c test-rint.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ test-func.c test-rint.o $(OBJS)

utils.o: utils.c utils.h
	$(CC) $(CFLAGS) -c utils.c

clean:
	rm -rf $(TESTS) *.o which.h core *~
