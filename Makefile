# CXX = g++
# CXXFLAGS = -std=c++11 -Wall -Wextra -g
# SRCS = $(wildcard *.cpp)
# OBJS = $(SRCS:.cpp=.o)
# TARGET = game

# all: $(TARGET)

# $(TARGET): $(OBJS)
# 	$(CXX) $(CXXFLAGS) -o $@ $^

# %.o: %.cpp
# 	$(CXX) $(CXXFLAGS) -c $<

# clean:
# 	rm -f $(OBJS) $(TARGET) 
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)
TARGET = game

# OS-specific cleanup command
ifeq ($(OS),Windows_NT)
    RM = del /Q
    NULLDEV = nul
else
    RM = rm -f
    NULLDEV = /dev/null
endif

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	$(RM) $(OBJS) $(TARGET) > $(NULLDEV) 2>&1 || true