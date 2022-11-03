LDFLAGS	= -lm
CFLAGS	= -std=c99 -Wall -pedantic
TESTS	= test-rint-near test-rint-down test-rint-zero
OBJS	= utils.o

all: $(TESTS)

test: all
	for t in $(TESTS) ; do ./$$t ; done

test-rint-near: test-rint-near.c test-rint-near.h test.h test.c $(OBJS)
	cp test-rint-near.h which.h
	$(CC) $(CFLAGS) -c test-rint-near.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ test-rint-near.o test.c $(OBJS)

test-rint-down: test-rint-down.c test-rint-down.h test.h test.c $(OBJS)
	cp test-rint-down.h which.h
	$(CC) $(CFLAGS) -c test-rint-down.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ test-rint-down.o test.c $(OBJS)

test-rint-zero: test-rint-zero.c test-rint-zero.h test.h test.c $(OBJS)
	cp test-rint-zero.h which.h
	$(CC) $(CFLAGS) -c test-rint-zero.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ test-rint-zero.o test.c $(OBJS)

utils.o: utils.c utils.h
	$(CC) $(CFLAGS) -c utils.c

clean:
	rm -rf $(TESTS) *.o which.h core *~
