ALL:=$(patsubst %/,%,$(wildcard */))

.PHONY: all
all: $(patsubst %,test-%,$(ALL))

.PHONY: test-%
test-%:
	$(MAKE) -C $*

.PHONY: clean
clean: $(patsubst %,clean-%,$(ALL))

.PHONY: clean-%
clean-%:
	$(MAKE) -C $* clean
