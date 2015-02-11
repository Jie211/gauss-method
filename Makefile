##
##macro
##

SOURCES = main.c\
					function.c\
					gauss.c

#bin file
BIN = Sovler

#object file
OBJS = $(SOURCES)

CC = gcc

#cc flags
CCFLAGS = -O2 -Wall -lm
#debug
DEBUGFLAGS = -g -DEBUG


##
## make rule
## 

#compile
all: $(BIN)

#clean
clear:
	rm $(BIN)

#link
$(BIN): $(OBJS)
	$(CC)  $(OBJS) -o $(BIN) $(CCFLAGS)

debug: CCFLAGS += $(DEBUGFLAGS)
debug: all

