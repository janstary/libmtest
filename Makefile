LDFLAGS	= -lm
CFLAGS	= -std=c99 -Wall -pedantic
TESTS	= test-rintf test-rint
OBJS	= utils.o

all: $(TESTS)

test: all
	for t in $(TESTS) ; do ./$$t ; done

test-rintf: test-rintf.c $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $< $(OBJS)

test-rint: test-rint.c $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $< $(OBJS)

utils.o: utils.c utils.h
	$(CC) $(CFLAGS) -c utils.c

clean:
	rm -rf $(TESTS) utils.o core *~
