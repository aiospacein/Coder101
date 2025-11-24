CC = gcc
CFLAGS = -Wall -DDEBUG -O0 -gdwarf-5

SRCDIR = src/TCPL
BUILDIR = build
OBJDIR = $(BUILDIR)/obj

SRC= $(wildcard $(SRCDIR)/*.c)
OBJ=$(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)


all: build| $(OBJ)
	$(CC) $(OBJ) -o $(BUILDIR)/all 

build: 
	mkdir -p $(BUILDIR)
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILDIR)
# 	rm -rf all

run: all
	./build/all
# 	gdb ./build/all
