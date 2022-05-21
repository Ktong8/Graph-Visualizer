CXX = g++
CFLAGS = -std=c++14 -g
IFLAGS = -I /opt/homebrew/Cellar/sfml/2.5.1_1/include
LFLAGS = -L /opt/homebrew/Cellar/sfml/2.5.1_1/lib -lsfml-graphics -lsfml-window -lsfml-system
SRCS = main.cpp graph.cpp node.cpp

all:
	$(CXX) $(CFLAGS) -o prog $(SRCS) $(LFLAGS) $(IFLAGS)