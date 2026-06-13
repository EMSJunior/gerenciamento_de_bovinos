# Makefile do Sistema de Gerenciamento de Bovinos
CXX      = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude

# No Windows o g++ gera o executável com sufixo .exe.
ifeq ($(OS),Windows_NT)
    EXE = .exe
else
    EXE =
endif

TARGET = build/gerenciamento$(EXE)
SRC    = $(wildcard src/*.cpp)
OBJ    = $(patsubst src/%.cpp,build/%.o,$(SRC))

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

build/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: all
	./$(TARGET)

clean:
	rm -f build/*.o $(TARGET)

.PHONY: all run clean
