CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2
SRC = appgraph.cpp graph.cpp 
OBJ = $(SRC:.cpp=.o)
TARGET = graph

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJ) $(TARGET)