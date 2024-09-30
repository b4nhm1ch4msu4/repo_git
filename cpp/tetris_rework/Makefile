CC = g++
CFLAGS = -Iinclude
LDFLAGS =-lraylib
SRC = $(wildcard src/*.cpp)
OBJ = $(patsubst src/%.cpp, build/%.o, $(SRC))
MAIN_OBJ = build/main.o
TARGET = tetrisGame

all: $(TARGET)

$(TARGET): $(MAIN_OBJ) $(OBJ)
	$(CC) $(MAIN_OBJ) $(OBJ) -o $@ $(LDFLAGS)

# Compile main.cpp into the build/ folder
$(MAIN_OBJ): main.cpp | build
	$(CC) -c $< -o $@ $(CFLAGS)

# Compile source files from src/ into build/
build/%.o: src/%.cpp | build
	$(CC) -c $< -o $@ $(CFLAGS)

# Create build directory if it doesn't exist
build:
	mkdir -p build

clean:
	rm -rf build $(TARGET)
