.PHONY: build test

all: clean init prepare build

init:
	cd build && make init

prepare:
	cd build && cmake .. && make prepare

build:
	cd build && cmake .. && make build

clean:
	cd build && make clean

# 目前只支持一个mapper进行工作, 因为目前代码中使用相对路径, 对于运行在不同路径上的mapper, 暂时没有保证如何获取正确路径

test:
	find test | grep -vE "^test$$|testfile.txt$$|test\.sh$$" | xargs rm -rf && ./test/test.sh

init_bak:
	cd build && make init_bak

prepare_bak:
	cd build && cmake .. && make prepare_bak