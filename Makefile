LDFLAGS	= -lm
CFLAGS	= -Wall -pedantic
TESTS	= test-rintf

test: $(TESTS)
	for t in $(TESTS) ; do ./$$t ; done

clean:
	rm -rf $(TESTS) core *~
