CC = gcc
CFLAGS = -Wall -Wextra -pedantic
LDLIBS = -lfl

YACC = bison -v -d
LEX = flex

OBJS = cmat.o parser.o lexer.o

cmat: $(OBJS)

parser.c parser.h: parser.y
	$(YACC) parser.y

lexer.c: lexer.l parser.h
	$(LEX) -o lexer.c lexer.l

.PHONY: clean
clean:
	rm -f cmat *.o *.output *.tab.*
