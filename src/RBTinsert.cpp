#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "RBTnode_add_fix.cpp"

using namespace std;
int RBT_node_add(
  struct RBT_node *in_root,
  struct RBT_node  *new_node,
  struct RBT_node *new_root) {
        new_node->p_node = nullptr;
		new_node->lc_node = nullptr;
		new_node->rc_node = nullptr;
		new_node->color = '1';
        struct RBT_node* x = in_root;
        struct RBT_node* node_null;
        node_null->color = 0;
        node_null->lc_node = nullptr;
        node_null->rc_node = nullptr;

        // cout << "Color root funcion "<<in_root->color << '\n';
        // cout << "Valor root funcion "<<in_root->value << '\n';
        // cout << "Color nuevo nodo funcion "<<new_node->color << '\n';
        // cout << "Valor nuevo nodo funcion "<<new_node->value << '\n';
        if (in_root->value == 0) {
            new_root = new_node;
            new_root->value = new_node->value;
            new_root->color = '0'; //Raiz negra
            new_node->color = '0';
        }  else {
            struct RBT_node* y;
            int z = 1;

        // while (x != TNULL) {
		// 	y = x;
		// 	if (node->data < x->data) {
		// 		x = x->left;
		// 	} else {
		// 		x = x->right;
		// 	}
		// }
            while ( x != nullptr) {
                y = x;
                if (new_node->value < x->value) {
                        // if (x->lc_node != nullptr) {
                        //      cout << "Here 1" << '\n';
                            x = x->lc_node;
                        // } else {
                        //     cout << "Here 2" << '\n';
                            // z = 0;                
                        // }

                } else {
                        // if (x->rc_node != nullptr) {
                        //     cout << "Here 3" << '\n';
                            x = x->rc_node;
                    //     } else {
                    //         cout << "Here 4" << '\n';
                            // z = 0;         
                    //   }

                }
            }
            cout << "Color y "<<y->color << '\n';
            cout << "Valor y "<<y->value << '\n';
            new_node->p_node = y;
            cout << "Color padre new nosw"<<new_node->p_node->color << '\n';
            if (new_node->value < y->value) {
                y->lc_node= new_node;
            } else {
                y->rc_node= new_node;
            }
            new_node->color = '1';
            in_root = new_root;
            int fix_error = RBT_node_add_fix(in_root, new_node);
        }
      return 0;
  };
