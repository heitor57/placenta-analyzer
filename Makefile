MKDIR = mkdir -p
CC = gcc
CFLAGS	= -Wall -g
COFLAGS	= -Wall -c -g
OBJDIR = obj
OBJS = $(addprefix $(OBJDIR)/, main.o matrix.o io.o maxsubsquare.o time.o)
LDFLAGS = -lm
MAIN_TARGET = placenta-analyzer
vpath %.c  src
vpath %.h  src
.PHONY: directories
all: directories $(MAIN_TARGET)
$(MAIN_TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)
$(OBJDIR)/%.o: %.c %.h
	gcc $(COFLAGS) $< -o $@
$(OBJDIR)/%.o: %.c
	gcc $(COFLAGS) $< -o $@
directories: $(OBJDIR)
$(OBJDIR):
	$(MKDIR) $@
clean:
	rm -rf $(OBJDIR) 
	rm -f $(MAIN_TARGET) $(GENERATOR_TARGET) $(PERFECT_TARGET) *~
