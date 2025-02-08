# Set compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -I./include -DSFML_STATIC

# Set paths for SFML libraries
SFML_DIR = ./lib
SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network

# Set output directories
BUILD_DIR = ./build
BIN_DIR = ./bin
SRC_DIR = ./src
OBJ_DIR = $(BUILD_DIR)/obj

# Specify the SFML library directory for the linker
LDFLAGS = -L$(SFML_DIR)

# Collect source files
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
PROJECT_NAME = SVRPG
EXEC = $(BIN_DIR)/${PROJECT_NAME}

# Default target
all: $(EXEC)

# Link the object files into the final executable
$(EXEC): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(EXEC) $(LDFLAGS) $(SFML_LIBS)
	${BIN_DIR}/${PROJECT_NAME}

# Compile source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ 

# Clean object files and executable
clean:
	rm -rf $(OBJ_DIR)/*.o $(EXEC)

# Rebuild the project
rebuild: clean all
