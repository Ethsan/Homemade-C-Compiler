CC = clang
CFLAGS = -Wall -Wextra
LDLIBS =

SRC_DIR=src
TEST_DIR=test
LIB_DIR=lib

CFLAGS += -I$(SRC_DIR) -I$(LIB_DIR) -I.

OUT = main

SRC = parser.tab.c lex.yy.c $(shell find $(SRC_DIR) -iname "*.c")

OBJ = $(SRC:.c=.o)

TEST_SRC = $(shell find $(TEST_DIR) $(SRC_DIR) -iname "*.c" -not -name $(OUT).c)
TEST_OBJ = $(TEST_SRC:.c=.o)

$(OUT): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@ $(LDLIBS)

parser.tab.c parser.tab.h: $(SRC_DIR)/parser.y
	bison -d $<

lex.yy.c: $(SRC_DIR)/lexer.l parser.tab.h
	flex $<

%.o: %.c parser.tab.h
	$(CC) $(CFLAGS) -c $< -o $@

test_runner: $(TEST_OBJ)
	$(CC) $(CFLAGS) $(TEST_OBJ) -o $@ $(LDLIBS)

compile_commands.json: clean
	bear -- make all

.PHONY: clean format test all 

all: $(OUT) test_runner

test: test_runner
	@./$< && echo "All tests passed" || echo "Some tests failed"

clean:
	rm -f $(OUT) $(OBJ) $(TEST_OBJ) test_runner parser.tab.c parser.tab.h lex.yy.c

format:
	find $(SRC_DIR) $(TEST_DIR) -iname "*.h" -o -iname "*.c" | xargs clang-format --verbose -i
