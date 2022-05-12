.PHONY: all
all: test

test: export PATH:=.:$(PATH)
test: temp_convert
	! temp_convert >no_args.actual.stdout 2>no_args.actual.stderr
	diff no_args.expected.stdout no_args.actual.stdout
	diff no_args.expected.stderr no_args.actual.stderr
