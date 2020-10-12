#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "../include/RBT.h"

using namespace std;
int RBT_node_add(
  struct RBT_node *in_root,
  struct RBT_node *new_node,
  struct RBT_node **new_root) {
	if (new_node->value < 0) {
		cout << "Invalid parameter, num should be positive" << "\n";
		return RBT_INVALID_PARAM;
	}
    int status = 0;
    new_node->lc_node = nullptr;
    new_node->rc_node = nullptr;
    new_node->p_node = nullptr;
    new_node->color = 'R';
    RBT_node* y = nullptr;
    RBT_node* x = in_root;
		while (x != nullptr) {
			y = x;
			if (new_node->value < x->value) {
				x = x->lc_node;
			} else {
				x = x->rc_node;
			}
		}
		new_node->p_node = y;
		if (y == nullptr) {
			*new_root = new_node;
		} else if (new_node->value < y->value) {
			y->lc_node = new_node;
		} else {
			y->rc_node = new_node;
		}
		if (new_node->p_node == nullptr){
			new_node->color = 'B';
			return status;
		}
		if (new_node->p_node->p_node == nullptr) {
      		*new_root = in_root;
			return status;
		}
    in_root = RBT_node_add_fix(in_root, new_node);
    *new_root = in_root;
    return status;
}
