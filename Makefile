CC_x64 := x86_64-w64-mingw32-g++
LD_x64 := x86_64-w64-mingw32-ld
CXXFLAGS := $(CXXFLAGS) -O0
CXXFLAGS := $(CXXFLAGS) -masm=intel -Wall -Wno-pointer-arith -w

# `$(CC_x64) -mdll` auto links necessary library
all: clean mkdir
	$(CC_x64) $(CXXFLAGS) -c DllMain.cpp -o dist/DllMain.o
	# $(LD_x64) -shared -o dist/DllMain.dll dist/DllMain.o -luser32
	$(CC_x64) $(CXXFLAGS) -mdll -o dist/DllMain.dll dist/DllMain.o
mkdir:
	mkdir -p ./dist
clean:
	rm -f dist/*

