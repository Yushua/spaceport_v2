CXX = g++
CXXFLAGS = -std=c++17 -Wall
SRC = main.cpp loop/loop.cpp crew.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = spaceport

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	del /Q *.o loop\*.o 2>nul || rm -f *.o loop/*.o
	del /Q $(TARGET).exe 2>nul || rm -f $(TARGET)