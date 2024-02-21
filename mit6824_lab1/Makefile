.PHONY: build test

system_file_name=./thirdparty/Imagine_System
tool_file_name=./thirdparty/Imagine_Tool

all: clean init prepare build

init:
	python3 init.py
prepare:
ifneq (${wildcard ${system_file_name}},)
	@echo "Imagine_System exists"
else
	@echo -e "\033[;31mImagine_System NOT exist, Please exucete make init to init it\033[0m"
	exit 1
endif
ifneq (${wildcard ${tool_file_name}},)
	@echo "Imagine_Tool exists"
else
	@echo -e "\033[;31mImagine_Tool NOT exist, Please exucete make init to init it\033[0m"
	exit 1
endif
	cd ${system_file_name} && make prepare
	cd ${tool_file_name} && make prepare

build:
	cd build && cmake .. && make

clean:
	cd build && make clean

# 目前只支持一个mapper进行工作, 因为目前代码中使用相对路径, 对于运行在不同路径上的mapper, 暂时没有保证如何获取正确路径

test:
	find test | grep -vE "^test$$|testfile.txt$$|testfile.txt.bak&&|test\.sh$$" | xargs rm -rf && ./test/test.sh