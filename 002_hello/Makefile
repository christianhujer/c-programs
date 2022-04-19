CFLAGS:=-W -Wall -pedantic -Werror -std=c17

SHELL:=/bin/bash
SHELLOPTS:=$(if $(SHELLOPTS),$(SHELLOPTS):)pipefail:errexit:errtrace

.PHONY: all
all: test

.PHONY: test
test: hello
	diff <(echo "Hello, world!") <(./hello)

.PHONY: clean
clean::
	$(RM) *.[adios] hello
