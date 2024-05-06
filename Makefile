# Compiler & Flags
CXX := g++
CXXFLAGS := -Wall

# Directories
INCLUDE_DIR := include
LIB_DIR := lib
SRC_DIR := src
BUILD_DIR := build
EXECUTABLE := traffic

# Files
SOURCES := $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SOURCES))

# Add the Windows SDL2 library path
# LDLIBS := -L$(LIB_DIR) -lmingw32 -lSDL2main -lSDL2

# Add the Linux SDL2 library path 
# NOTE: pkg-config and SDL2 must be installed on your system. You can use the command "pkg-config --cflags --libs sdl2" in the terminal to check if SDL2 is installed.
LDLIBS := $(shell pkg-config --cflags --libs sdl2)

# Build executable
$(BUILD_DIR):
	mkdir $(BUILD_DIR)

$(BUILD_DIR)/$(EXECUTABLE): $(OBJECTS) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) $^ -o $@ $(LDLIBS)

# Compile source files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Run
run: $(BUILD_DIR)/$(EXECUTABLE)
	./$<