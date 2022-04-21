.PHONY: all
all: decode encode decode_annotated

#  The -Wformat0 is for a workaround in gcc: It wrongly warns about %b.
decode_annotated: CFLAGS+=-Wformat=0 -std=c2x

.PHONY: clean
clean::
	$(RM) *.[adios] decode decode_annotated
