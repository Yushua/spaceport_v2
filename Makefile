CXX = g++
CXXFLAGS = -std=c++17 -Wall -I.

SRCS = main.cpp \
       loop/loop.cpp \
       create/makeCrew.cpp \
       create/makeRoom.cpp \
       create/makeWorkstation.cpp \
       create/makeCivilian.cpp \
       create/makeResource.cpp \
       create/makeItem.cpp \
       entities/crew.cpp \

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

re:
	$(MAKE) clean
	$(MAKE) run