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
		struct RBT_node temp = {};
        if (in_root->value == 0) {
            cout << new_node.value;
            cout << new_root->value;
            new_root->value = new_node.value;
            cout << new_root->value;
            new_root->color = 0; //Raiz negra
        }  else {
            cout << in_root->lc_node;
            while ( in_root->value != 0) {
                temp.value =  in_root->value ;
                // if (new_node.value < in_root->value) {
                //     in_root = in_root->lc_node;
                //     //cout << in_root.lc_node->value;
                //     //in_root.value = in_root.lc_node->value;
                // } //else {
                // //     struct RBT_node*  in_root = in_root->rc_node;
                // }
            }
        // //     new_node.p_node = temp;
        //     if (new_node.value < temp->value) {
        //         temp->lc_node->value = new_node.value;
        //     } else {
        //         temp->rc_node->value = new_node.value;
        //     }
        //     new_node.color = 1;
        //     //RBT_node_add_fix(in_root,new_node);
        }
      return 0;
  };
