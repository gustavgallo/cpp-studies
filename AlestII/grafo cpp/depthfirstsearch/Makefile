CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2
SRC = depthfirstsearch.cpp ../graph.cpp appdfs.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = dfs

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJ) $(TARGET)