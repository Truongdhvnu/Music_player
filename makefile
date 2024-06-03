# COMPILE CONFIGURE
CFLAGS = -Wall -Wextra -std=c++17 $(LINK_DIRS)
LDFLAGS = `pkg-config --libs sdl2 SDL2_mixer taglib` -pthread
CC := g++
EXECUTE_FILE := main

MODULES := Controller Model View
SRCDIR = $(foreach module,$(MODULES),$(module)/src)
INCDIR := View/src $(foreach module,$(MODULES),$(module)/inc)
OBJDIR := Build

LINK_DIRS = $(foreach dir, $(INCDIR), -I$(dir))
SRCS := $(foreach dir, $(SRCDIR), $(wildcard $(dir)/*.cpp))
OBJS := $(OBJDIR)/main.o $(patsubst %.cpp,./$(OBJDIR)/%.o,$(notdir $(SRCS)))

vpath %.cpp $(SRCDIR)

$(OBJDIR)/%.o: %.cpp
	$(CC) $(CFLAGS) -c $< $(LDFLAGS) -o $@

build: clean obj_build

obj_build: $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $(OBJDIR)/$(EXECUTE_FILE)


.PHONY: run
run:
	./$(OBJDIR)/$(EXECUTE_FILE)

.PHONY: clean
clean:
	rm -f $(OBJDIR)/*.o ./$(OBJDIR)/$(EXECUTE_FILE)

print-%:
	@echo $($*)
