#include <stdio.h>
#include <stdlib.h>
#include <iostream>
//#include "RBTnode_add_fix.cpp"
#include "../include/RBT.h"

using namespace std;
int RBT_node_add(
  struct RBT_node *in_root,
  struct RBT_node *new_node,
  struct RBT_node **new_root) {
    int status = 0;
    new_node->lc_node = nullptr;
    new_node->rc_node = nullptr;
    new_node->p_node = nullptr;
    new_node->color = 1;
    RBT_node* y = nullptr;
    RBT_node* x = in_root;
    cout << "Root value"<< in_root->value << "\n";
    cout << "Root color" <<in_root->color << "\n";
    cout << "New node value" << new_node->value << "\n";
    cout << "New node color  " << new_node->color << "\n";
		while (x != nullptr) {
			y = x;
			if (new_node->value < x->value) {
				x = x->lc_node;
        cout << "Izquierdo" << "\n";
			} else {
				x = x->rc_node;
        cout << "Derecho" << "\n";
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
		// if new node is a root node, simply return
		if (new_node->p_node == nullptr){
			new_node->color = 0;
			return status;
		}
		// if the grandparent is null, simply return
		if (new_node->p_node->p_node == nullptr) {
      *new_root = in_root;
			return status;
		}
    *new_root = in_root;
    return status;

    // //int fix_error = RBT_node_add_fix(in_root, *new_node);
    // return status;
};

