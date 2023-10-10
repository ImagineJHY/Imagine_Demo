.PHONY: mit6824_lab1

all: mit6824_lab1

mit6824_lab1:
	cd mit6824_lab1 && make clean && make init && make prepare && make build

test_mit6824_lab1:
	cd mit6824_lab1 && make test