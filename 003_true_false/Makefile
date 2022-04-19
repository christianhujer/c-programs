CFLAGS:=-W -Wall -pedantic -Werror -std=c17

SHELL:=/bin/bash
SHELLOPTS:=$(if $(SHELLOPTS),$(SHELLOPTS):)pipefail:errexit:errtrace

.PHONY: all
all: test

.PHONY: test
test: test(true) test(false)

.PHONY: test(true)
test(true): true
	./true

.PHONY: test(false)
test(false): false
	! ./false

.PHONY: clean
clean::
	$(RM) *.[adios] false true
