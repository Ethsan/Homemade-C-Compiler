#pragma once

#include "tree.h"

tree cmat_build_range(tree left, tree right);

tree cmat_build_array_ref(tree array, tree index);

tree cmat_build_unary_expr(enum tree_code code, tree expr);

tree cmat_build_expr(enum tree_code code, tree left, tree right);

tree cmat_build_print_mat(tree expr);

tree cmat_build_type();
