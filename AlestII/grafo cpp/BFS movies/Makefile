CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2
SRC = breadthfirstsearch.cpp ../graph.cpp appbfs.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = bfs

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJ) $(TARGET)