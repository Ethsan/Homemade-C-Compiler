#include <stdio.h>
#include "args.h"
extern int yyparse(void);




int main(int argc, char *argv[])
{
	args_t args;
	init_args(&args);
	parse_args(argc, argv, &args);

	return yyparse();
}
