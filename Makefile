CC_x64 := x86_64-w64-mingw32-g++
CXXFLAGS := $(CXXFLAGS) -O0
CXXFLAGS := $(CXXFLAGS) -masm=intel -Wall -Wno-pointer-arith -w

all: clean mkdir
	$(CC_x64) $(CXXFLAGS) -mdll src/DLLMain.cpp -o dist/myDLL.dll
mkdir:
	mkdir -p ./dist
clean:
	rm -f dist/*.o
	rm -f ./*.c

