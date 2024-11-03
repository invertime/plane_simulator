# Define variables for compiler, flags, and object files
CC=g++
CFLAGS=-c -Wall -Wextra
BUILD_FLAGS=-Wall -Wextra
LIB=-lSDL2main -lSDL2 -lGL -lm
OBJECTS=main.o plane.o Airfoil.o Wing.o RigidBody.o Matrix3f.o Vector3f.o Quaternion.o
SRC=./src/
SRC_CLASSES=./src/classes/
BUILD=./build/
OBJ_FILES:=$(addprefix $(BUILD), $(OBJECTS))

#debug:
#	@echo "OBJ_FILES: $(OBJ_FILES)"

# Create build directories
$(shell mkdir -p $(BUILD) bin)

# Define the default target
all: $(OBJ_FILES)
	$(CC) $^ $(BUILD_FLAGS) $(LIB) -o bin/runner

# Rules for building individual object files
$(BUILD)main.o: $(SRC)main.cpp $(SRC_CLASSES)RigidBody.hpp $(SRC_CLASSES)Matrix3f.hpp $(SRC_CLASSES)Vector3f.hpp $(SRC_CLASSES)Quaternion.hpp
	$(CC) $(CFLAGS) $< -o $@

$(BUILD)plane.o: $(SRC_CLASSES)plane.cpp
	$(CC) $(CFLAGS) $< -o $@

$(BUILD)Airfoil.o: $(SRC_CLASSES)Airfoil.cpp
	$(CC) $(CFLAGS) $< -o $@

$(BUILD)Wing.o: $(SRC_CLASSES)Wing.cpp
	$(CC) $(CFLAGS) $< -o $@

$(BUILD)RigidBody.o: $(SRC_CLASSES)RigidBody.cpp
	$(CC) $(CFLAGS) $< -o $@

$(BUILD)Matrix3f.o: $(SRC_CLASSES)Matrix3f.cpp
	$(CC) $(CFLAGS) $< -o $@

$(BUILD)Quaternion.o: $(SRC_CLASSES)Quaternion.cpp
	$(CC) $(CFLAGS) $< -o $@

$(BUILD)Vector3f.o: $(SRC_CLASSES)Vector3f.cpp
	$(CC) $(CFLAGS) $< -o $@

# Clean target to remove object files and executable
clean:
	rm -f $(BUILD)*.o bin/runner

.PHONY: all clean
