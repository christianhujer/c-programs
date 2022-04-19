CFLAGS:=-W -Wall -pedantic -Werror -std=c17

SHELL:=/bin/bash
SHELLOPTS:=$(if $(SHELLOPTS),$(SHELLOPTS):)pipefail:errexit:errtrace

.PHONY: all
all: test

.PHONY: test
test: echo
	diff <(echo) <(./echo)
	diff <(echo foo) <(./echo foo)
	diff <(echo foo bar) <(./echo foo bar)

.PHONY: clean
clean::
	$(RM) *.[adios] echo
