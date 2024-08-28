# Define variables for compiler, flags, and object files
CC=g++
CFLAGS=-c -Wall
BUILD_FLAGS=-Wall
LIB=-lSDL2main -lSDL2 -lGL
OBJECTS=main.o RigidBody.o Matrix3f.o Vector3f.o
SRC=./src/
SRC_CLASSES=./src/classes/
BUILD=./build/
OBJ_FILES:=$(addprefix $(BUILD), $(OBJECTS))

#debug:
#	@echo "OBJ_FILES: $(OBJ_FILES)"

# Define the default target
all: $(OBJ_FILES)
	$(CC) $(BUILD_FLAGS) $(LIB) $^ -o bin/runner

# Rules for building individual object files
$(BUILD)main.o: $(SRC)main.cpp $(SRC_CLASSES)RigidBody.hpp $(SRC_CLASSES)Matrix3f.hpp $(SRC_CLASSES)Vector3f.hpp
	$(CC) $(CFLAGS) $< -o $@

$(BUILD)RigidBody.o: $(SRC_CLASSES)RigidBody.cpp $(SRC_CLASSES)RigidBody.hpp $(SRC_CLASSES)Matrix3f.hpp $(SRC_CLASSES)Vector3f.hpp
	$(CC) $(CFLAGS) $< -o $@

$(BUILD)Matrix3f.o: $(SRC_CLASSES)Matrix3f.cpp $(SRC_CLASSES)Matrix3f.hpp $(SRC_CLASSES)Vector3f.hpp
	$(CC) $(CFLAGS) $< -o $@

$(BUILD)Vector3f.o: $(SRC_CLASSES)Vector3f.cpp $(SRC_CLASSES)Vector3f.hpp
	$(CC) $(CFLAGS) $< -o $@

# Clean target to remove object files and executable
clean:
	rm -f $(BUILD)*.o project
