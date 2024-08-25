# Define variables for compiler, flags, and object files
CC=g++
CFLAGS=-c -Wall
OBJECTS=main.o RigidBody.o Vector3.o
SRC=./src/
SRC_CLASSES=./src/classes/
BUILD=./build/
OBJ_FILES:=$(addprefix $(BUILD), $(OBJECTS))

#debug:
#	@echo "OBJ_FILES: $(OBJ_FILES)"

# Define the default target
all: $(OBJ_FILES)
	$(CC) $(CFLAGS) $^ -o project

# Rules for building individual object files
$(BUILD)main.o: $(SRC)main.cpp $(SRC_CLASSES)RigidBody.hpp $(SRC_CLASSES)Vector3.hpp
	$(CC) $(CFLAGS) $< -o $@

$(BUILD)RigidBody.o: $(SRC_CLASSES)RigidBody.cpp $(SRC_CLASSES)RigidBody.hpp
	$(CC) $(CFLAGS) $< -o $@

$(BUILD)Vector3.o: $(SRC_CLASSES)Vector3.cpp $(SRC_CLASSES)Vector3.hpp
	$(CC) $(CFLAGS) $< -o $@

# Clean target to remove object files and executable
clean:
	rm -f $(BUILD)*.o project
