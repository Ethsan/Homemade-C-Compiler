CC = clang
CFLAGS = -Wall -Wextra -g
LDLIBS =

SRC_DIR=src
LIB_DIR=lib

CFLAGS += -I$(SRC_DIR) -I$(LIB_DIR) -I.

OUT = main

SRC = parser.tab.c lex.yy.c $(shell find $(SRC_DIR) -iname "*.c")

OBJ = $(SRC:.c=.o)

$(OUT): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@ $(LDLIBS)

parser.tab.c parser.tab.h: $(SRC_DIR)/parser.y
	bison -d $<

lex.yy.c: $(SRC_DIR)/lexer.l parser.tab.h
	flex $<

%.o: %.c parser.tab.h
	$(CC) $(CFLAGS) -c $< -o $@


compile_commands.json: clean
	bear -- make all

.PHONY: clean format all help

all: $(OUT) 


clean:
	rm -f $(OUT) $(OBJ) parser.tab.c parser.tab.h lex.yy.c

format:
	find $(SRC_DIR) -iname "*.h" -o -iname "*.c" | xargs clang-format --verbose -i

help:
	@echo "Available rules:"
	@echo
	@echo "  all: Build the main program and the test runner."
	@echo "  $(OUT): Build the main program."
	@echo "  compile_commands.json: Generate a compile_commands.json file."
	@echo "  clean: Remove generated files."
	@echo "  format: Format the source code."
	@echo "  test: Run the tests."
	@echo "  help: Show this help message."
	@echo
