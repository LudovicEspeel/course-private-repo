# The compiler to use
CC=g++

# Compiler flags
CFLAGS=-c -Wall -std=c++17
    # -c: Compile or assemble the source files, but do not link.
    # The linking stage simply is not done.
    # The ultimate output is in the form of an object file for each source file.
    #
    # -Wall: This enables all the warnings about constructions that
    # some users consider questionable, and that are easy to avoid
    # (or modify to prevent the warning), even in conjunction with macros.

# Linker flags
# LDFLAGS=

# Libraries
# LIBS=

# Name of executable output
TARGET=wordblaster
SRCDIR=src
LIBDIR=$(SRCDIR)/lib
BUILDDIR=bin

OBJS := $(SRCDIR)/main.o \
				$(LIBDIR)/word_list.o \
				$(LIBDIR)/word_loader.o \
				$(LIBDIR)/game.o \
				$(LIBDIR)/user_io.o \
				$(LIBDIR)/score.o \
				$(LIBDIR)/player.o \
				$(LIBDIR)/scoreboard.o \
				$(LIBDIR)/player_manager.o \
				$(LIBDIR)/comparators/score_comparator.o \
				$(LIBDIR)/helpers/score_calculator.o \
				$(LIBDIR)/menu/menu.o \
				$(LIBDIR)/helpers/terminal.o \
				$(LIBDIR)/menu/menu_item.o \
				$(LIBDIR)/word_blaster.o \
				$(LIBDIR)/difficulty.o \
				$(LIBDIR)/helpers/string_helper.o

all: makebuildir $(TARGET)

run: all
	./$(BUILDDIR)/$(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(LDFLAGS) -o $(BUILDDIR)/$@ $(OBJS) $(LIBS)

%.o : %.cpp
	$(CC) $(CFLAGS) $< -o $@

clean :
	rm -rf $(BUILDDIR)
	rm -f $(OBJS)

makebuildir:
	mkdir -p $(BUILDDIR)

docs :
	doxygen