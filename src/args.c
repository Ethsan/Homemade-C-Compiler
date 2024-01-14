#include "args.h"
#include <stdio.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>

void help(void)
{
	fprintf(stdout, "Usage: ./main [OPTION]... [FILE IN]\n");
	fprintf(stdout, "Options:\n");
	fprintf(stdout, "\t-o [OUT FILE]\t\tOutput file\n");
	fprintf(stdout, "\t-a\t\t\tPrint AST\n");
	fprintf(stdout, "\t-version\t\tVersion\n");
	fprintf(stdout, "\t-tos\t\t\tSymbol table\n");
	fprintf(stdout, "\t-c\t\t\tPrint cimple code\n");
	fprintf(stdout, "\t-h\t\t\tHelp\n");
	/*liste des options
	-o : output
	-h : help
	-a : print AST
	-version : version
	-tos : symbol table
	-c : print cimple code
	*/
}

void version(void)
{
	fprintf(stdout, "Version 0.0.7\n");
	fprintf(stdout, "Authors:\n");
	fprintf(stdout, "\t- MILON Ethan\n");
	fprintf(stdout, "\t- LE BERRE Clément\n");
}

void init_args(args_t *args)
{
	args->input_file = NULL;
	args->output_file = NULL;
	args->print_ast = 0;
	args->print_symbol_table = 0;
	args->print_cimple = 0;
}
int parse_args(int argc, char *argv[], args_t *args)
{
	int c;
	int err = 0;
	(void)err;

	while ((c = getopt(argc, argv, "o:ahct:v:")) != -1) {
		switch (c) {
		case 'o':
			args->output_file = optarg;
			break;
		case 'h':
			help();
			exit(0);
		case 'a':
			args->print_ast = 1;
			break;
		case 'c':
			args->print_cimple = 1;
			break;
		case 't':
			// check if -tos or -t
			if (strcmp(optarg, "os") == 0)
				args->print_symbol_table = 1;
			else {
				fprintf(stderr, "Unknown option -t%s\n", optarg);
				err = 1;
			}
			break;
		case 'v':
			if (strcmp(optarg, "ersion") == 0) {
				version();
				exit(0);
			} else
				fprintf(stderr, "Unknown option -v%s\n", optarg);

		case '?':

			if (optopt == 'o' || optopt == 'i') {
				fprintf(stderr, "Option -%c requires an argument.\n", optopt);
			} else {
				if (isprint(optopt)) {
					fprintf(stderr, "Unknown option `-%c'.\n", optopt);
				} else {
					fprintf(stderr, "Unknown option character `\\x%x'.\n", optopt);
				}
			}
			err = 1;
			break;
		default:
			abort();
		}
		if (err) {
			help();
			exit(1);
		}
	}

	// input file
	if (optind < argc) {
		args->input_file = argv[optind];
	} else {
		fprintf(stderr, "No input file\n");
		err = 1;
	}

	for (int i = optind + 1; i < argc; i++)
		printf("Non-option argument %s\n", argv[i]);

	check_args(args);
	return 0;
}

int check_args(args_t *args)
{
	int err = 0;
	(void)err;

	if (args->input_file == NULL) {
		fprintf(stderr, "No input file\n");
		err = 1;
	}
	if (args->output_file == NULL) {
		args->output_file = malloc(sizeof(char) * 6);
		strcpy(args->output_file, "out.s");
		if (args->output_file == NULL) {
			fprintf(stderr, "Error malloc\n");
			exit(1);
		}
	}
	if (err) {
		help();
		exit(1);
	}
	return 0;
}
