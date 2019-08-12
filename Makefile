LDFLAGS	= -lm
CFLAGS	= -std=c99 -Wall -pedantic
TESTS	= test-rintf
OBJS	= utils.o

test: $(TESTS)
	for t in $(TESTS) ; do ./$$t ; done

test-rintf: test-rintf.c $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ test-rintf.c $(OBJS)

clean:
	rm -rf $(TESTS) utils.o core *~
