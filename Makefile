CC = gcc
CFLAGS = -Wall -Wextra -pedantic
LDLIBS = -lfl

YACC = bison -v -d
LEX = flex

OBJS = main.o parser.tab.o lex.yy.o tree.o

main: $(OBJS)

parser.tab.c parser.tab.h: parser.y
	$(YACC) parser.y

lex.yy.c: lexer.l parser.tab.h
	$(LEX) lexer.l

test_%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -DTEST_%

test_%: test_%.o $(filter-out main.o, $(OBJS))
	$(CC) $(CFLAGS) $^ -o $@ $(LDLIBS)
	./$@

.PHONY: clean
clean:
	rm -f main *.o *.output *.tab.*
