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

# Add the SDL2 library path
LDLIBS := -L$(LIB_DIR) -lSDL2main -lSDL2

# Build executable
$(BUILD_DIR):
	mkdir $(BUILD_DIR)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) $^ -o $@ $(LDLIBS)

# Compile source files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

run: $(EXECUTABLE)
	./$(EXECUTABLE)

# Clean
clean:
	rm -f $(BUILD_DIR)/*.o $(EXECUTABLE)