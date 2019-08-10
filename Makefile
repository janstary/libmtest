LDFLAGS	= -lm
CFLAGS	= -Wall -pedantic
FUNC	= rint

test: $(TESTS)
	for f in $(FUNC) ; do ./test-$$f | diff -Nup - test-$$f.out ; done

clean:
	rm -rf $(TESTS) core *~
