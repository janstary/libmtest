LDFLAGS	= -lm
CFLAGS	= -std=c99 -Wall -pedantic
TESTS	= test-rint-near test-rint-down test-rint-up test-rint-zero \
	  test-sin test-sinf
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

test-rint-up: test-rint-up.c test-rint-up.h test.h test.c $(OBJS)
	cp test-rint-up.h which.h
	$(CC) $(CFLAGS) -c test-rint-up.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ test-rint-up.o test.c $(OBJS)

test-rint-zero: test-rint-zero.c test-rint-zero.h test.h test.c $(OBJS)
	cp test-rint-zero.h which.h
	$(CC) $(CFLAGS) -c test-rint-zero.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ test-rint-zero.o test.c $(OBJS)

test-sin: test-sin.c test-sin.h test.h test.c $(OBJS)
	cp test-sin.h which.h
	$(CC) $(CFLAGS) -c test-sin.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ test-sin.o test.c $(OBJS)

test-sinf: test-sinf.c test-sinf.h test.h test.c $(OBJS)
	cp test-sinf.h which.h
	$(CC) $(CFLAGS) -c test-sinf.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ test-sinf.o test.c $(OBJS)

utils.o: utils.c utils.h
	$(CC) $(CFLAGS) -c utils.c

clean:
	rm -rf $(TESTS) *.o which.h *.core *~
