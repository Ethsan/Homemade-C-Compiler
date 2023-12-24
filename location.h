#pragma once

struct location {
	int first_line;
	int first_column;
	int last_line;
	int last_column;

	char *source_file;
	struct file *file;
	struct macro *macro;
};
