struct location {
	int first_line;
	int first_column;
	int last_line;
	int last_column;

	struct named_location *from_file;
	struct named_location *from_macro;
};

struct named_location {
	char *name;
	struct location loc;
};
