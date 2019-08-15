LDFLAGS	= -lm
CFLAGS	= -std=c99 -Wall -pedantic
TESTS	= test-rintf test-rint test-rintl test-lrintf test-lrint
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

test-rintl: test-rintl.c test-rintl.h test-func.h test-func.c $(OBJS)
	cp test-rintl.h which.h
	$(CC) $(CFLAGS) -c test-rintl.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ test-func.c test-rintl.o $(OBJS)

test-lrintf: test-lrintf.c test-lrintf.h test-func.h test-func.c $(OBJS)
	cp test-lrintf.h which.h
	$(CC) $(CFLAGS) -c test-lrintf.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ test-func.c test-lrintf.o $(OBJS)

test-lrint: test-lrint.c test-lrint.h test-func.h test-func.c $(OBJS)
	cp test-lrint.h which.h
	$(CC) $(CFLAGS) -c test-lrint.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ test-func.c test-lrint.o $(OBJS)

utils.o: utils.c utils.h
	$(CC) $(CFLAGS) -c utils.c

clean:
	rm -rf $(TESTS) *.o which.h core *~
