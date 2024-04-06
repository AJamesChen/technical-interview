# Compiler
CXX = g++
# Compiler flags
CXXFLAGS = -std=c++20 -Wall -Wextra

# Source files
SRCS = main.cpp
# Object files
OBJS = $(SRCS:.cpp=.o)
# Executable name
EXEC = main

# Target for building the executable
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(EXEC)

# Target for building object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Target for cleaning up generated files
clean:
	rm -f $(OBJS) $(EXEC)
