CFLAGS:=-W -Wall -pedantic -Werror -std=c17

.PHONY: all
all: run

.PHONY: run
run: types
	./types

.PHONY: clean
clean::
	$(RM) *.[adios] types
