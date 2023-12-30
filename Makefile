# Compiler
CC = g++

# Compiler flags
CFLAGS = -std=c++20 -Wall -g

# Linker flags for ncurses
LDFLAGS = -lncurses

# Source files
SRCS = Engine.cc Display.cc Character.cc SingleCharacter.cc RectangleCharacter.cc BitMapCharacter.cc StraightLine.cc UserInputMovement.cc HideMovement.cc UnhideMovement.cc Relationship.cc PassThrough.cc BounceOff.cc Battle.cc main.cc

# Object files
OBJS = $(SRCS:.cc=.o)

# Header files
HDRS = $(wildcard *.h)

# Executable
TARGET = myprogram

# Compilation rule
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LDFLAGS)

# Rule for .cc to .o
%.o: %.cc $(HDRS)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -f $(OBJS) $(TARGET)
