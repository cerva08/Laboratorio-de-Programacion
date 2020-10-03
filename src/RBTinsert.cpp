#include <stdio.h>
#include <stdlib.h> 
#include <iostream>
using namespace std;
int RBT_node_add(
  struct RBT_node *in_root,
  struct RBT_node  new_node,
  struct RBT_node *new_root) {
      	new_node.p_node = nullptr;
		new_node.lc_node = nullptr;
		new_node.rc_node = nullptr;
		new_node.color = 1; 
		struct RBT_node* temp = {};
        if (in_root->value == 0) {
            new_root->value = new_node.value;
            new_root->color = 0; //Raiz negra
            cout << "HERE0";
        }  else {
            while ( in_root->value != 0) {
                temp =  in_root;
                if (new_node.value < in_root->value) {
                        if (in_root->lc_node != nullptr) {
                            in_root->value = in_root->lc_node->value;
                            cout << "HERE1";
                        } else {
                            in_root->value = 0;
                            cout << "HERE2";
                        }

                } else {
                        if (in_root->rc_node != nullptr) {
                            in_root->value = in_root->lc_node->value;
                            cout << "HERE3";
                        } else {
                            in_root->value = 0;
                            cout << "HERE4";
                        }

                }
            }
            new_node.p_node = temp;
            if (new_node.value < temp->value) {
                temp->lc_node= &new_node;
            } else {
                temp->rc_node= &new_node;
            } 
            new_node.color = 1;
            //RBT_node_add_fix(in_root,new_node);
        }
      return 0;
  };
