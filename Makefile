CXX = g++
CXXFLAGS = -std=c++17 -Wall

SRCS = main.cpp loop/loop.cpp crew.cpp makeCrew.cpp makeRoom.cpp makeWorkstation.cpp makeCivilian.cpp
OBJS = $(SRCS:.cpp=.o)

spaceport: $(OBJS)
	$(CXX) $(CXXFLAGS) -o spaceport $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	del /Q *.o 2>nul || rm -f *.o
	del /Q spaceport.exe 2>nul || rm -f spaceport
	del /Q info\crew\*.txt 2>nul || rm -f info/crew/*.txt
	del /Q info\crew\crewMembers\*.txt 2>nul || rm -f info/crew/crewMembers/*.txt

run: spaceport
	./spaceport