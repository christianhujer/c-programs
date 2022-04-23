CFLAGS:=-W -Wall -pedantic -Werror -std=c2x

.PHONY: all
all: test

test: $(patsubst test/%.expected,test/%.actual,$(wildcard test/*.expected))
	touch test

.DELETE_ON_ERROR:
%.actual: %.input %.expected hexdump
	./hexdump <$*.input >$*.actual
	diff $*.expected $*.actual

hexdump: hexdump.c

.PHONY: clean
clean::
	$(RM) *.[adios] hexdump test/*.actual
