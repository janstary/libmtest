LDFLAGS	= -lm
CFLAGS	= -Wall -pedantic
TESTS	= test-rintf

test: $(TESTS)
	for t in $(TESTS) ; do ./$$t ; done

$(TESTS): utils.o

clean:
	rm -rf $(TESTS) utils.o core *~
