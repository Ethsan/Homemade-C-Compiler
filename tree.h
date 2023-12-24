#pragma once
#include "location.h"

enum tree_node {
	CONSTANT,
	etc,
};

struct tree_common {
	enum tree_node type;
	char *name;

};
