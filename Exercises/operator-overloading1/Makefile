# Compiler
CC=g++

# Compiler flags
CFLAGS=-Wall
# -Wall: This enables all the warnings about constructions that
# some users consider questionable, and that are easy to avoid
# (or modify to prevent the warning), even in conjunction with macros.

# Source files
SRCS=$(wildcard *.cpp)

# Object files
OBJS=$(SRCS:.cpp=.o)

# Executable name
EXECUTABLE=a

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXECUTABLE) $(OBJS)
	del -f $(OBJS) #Windows
#	rm -f ${OBJS} #Linux

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	del -f $(OBJS) $(EXECUTABLE).exe *.ii *.s #Windows
#	rm -f ${OBJS} ${EXECUTABLE} *.ii *.s #Linux