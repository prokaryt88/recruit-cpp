CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra
TARGET = stats
OBJECTS = stats.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)

stats.o: stats.cpp
	$(CXX) $(CXXFLAGS) -c stats.cpp

clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all clean