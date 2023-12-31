#include <stdio.h>
extern int yyparse(void);




int main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	return yyparse();
}
