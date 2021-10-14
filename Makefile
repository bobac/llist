CC=gcc
CFLAGS=-Isrc/ -g -Wall
CFLAGS_TEST=-I$(CURDIR)/src/ -g -Wall

SRC=src
OBJ=obj
SRCS=$(wildcard $(SRC)/*.c) $(wildcard $(SRC)/*/*.c)
OBJS=$(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))

TEST=tests
TESTSRCS=$(filter-out src/main.c, $(SRCS))
TESTS=$(wildcard $(TEST)/*.c) $(wildcard $(TEST)/*/*.c)
TESTOBJS=$(patsubst $(SRC)/%.c, $(TEST)/bin/%.o, $(TESTSRCS))
TESTBINS=$(patsubst $(TEST)/%.c, $(TEST)/bin/%, $(TESTS))

BIN=bin/llist

all:$(BIN)

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TEST)/bin/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TEST)/bin/%: $(TEST)/%.c
	$(CC) $(CFLAGS_TEST) $(TESTOBJS) $< -o $@ -lcriterion

test: $(TESTOBJS) $(TESTBINS)
	echo TESTBINS=$(TESTBINS)
	for test in $(TESTBINS) ; do ./$$test ; done

clean:
	find bin/ -type f -exec rm {} +
	find obj/ -type f -exec rm {} +
	find tests/bin/ -type f -exec rm {} +

