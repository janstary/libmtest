LDFLAGS	= -lm
CFLAGS	= -Wall -pedantic
TESTS	= test-rint

test: $(TESTS)
	for t in $(TESTS) ; do ./$$t | diff -Nup - $$t.out ; done

clean:
	rm -rf $(TESTS) core *~
