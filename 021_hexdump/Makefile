CFLAGS:=-W -Wall -pedantic -Werror -std=c2x

.PHONY: all
all: test

test: $(patsubst test/%.expected.xhtml,test/%.actual.xhtml,$(wildcard test/*.expected.xhtml))
	touch test

.DELETE_ON_ERROR:
%.actual.xhtml: %.input %.expected.xhtml hexdump
	./hexdump <$*.input >$*.actual.xhtml
	diff $*.expected.xhtml $*.actual.xhtml

hexdump: hexdump.c

.PHONY: clean
clean::
	$(RM) *.[adios] hexdump test/*.actual.xhtml
