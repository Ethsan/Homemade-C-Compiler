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
	fprintf(stdout, "Usage: ./main [OPTION]... [FILE]...\n");
	fprintf(stdout, "Options:\n");
	/*liste des options
	-o : output
	-h : help

	*/
}

void init_args(args_t *args)
{
	args->input_file = NULL;
	args->output_file = NULL;
}
int parse_args(int argc, char *argv[], args_t *args)
{
	int c;
	int err = 0;
	(void)err;

	while ((c = getopt(argc, argv, "hi:o:")) != -1) {
		switch (c) {
		case 'i':
			args->input_file = optarg;
			break;
		case 'o':
			args->output_file = optarg;
			break;
		case 'h':
			help();
			exit(0);
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
	for (int i = optind; i < argc; i++)
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
