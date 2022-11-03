LDFLAGS	= -lm
CFLAGS	= -std=c99 -Wall -pedantic
TESTS	= test-rint-near
OBJS	= utils.o

all: $(TESTS)

test: all
	for t in $(TESTS) ; do ./$$t ; done

test-rint-near: test-rint-near.c test-rint-near.h test.h test.c $(OBJS)
	cp test-rint-near.h which.h
	$(CC) $(CFLAGS) -c test-rint-near.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ test-rint-near.o test.c $(OBJS)
	# This build can be made uniform for all tests

utils.o: utils.c utils.h
	$(CC) $(CFLAGS) -c utils.c

clean:
	rm -rf $(TESTS) *.o which.h core *~
