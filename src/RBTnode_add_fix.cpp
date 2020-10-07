#include <stdio.h>
#include <stdlib.h>
#include <iostream>
//#include "RBTrotations.cpp"
#include "../include/RBT.h"
using namespace std;
int RBT_node_add_fix(struct RBT_node* in_root, struct RBT_node* new_node){
  int status = 0;
  struct RBT_node* u;;
  while (new_node->p_node->color == 1) {
    cout << "Entra al while" << "\n";
    if (new_node->p_node == new_node->p_node->p_node->rc_node) {
      cout << "Entra al if" << "\n";
      u = new_node->p_node->p_node->lc_node; // tio
      if (u->color == 1) {
        u->color = 0;
        new_node->p_node->color = 0;
        new_node->p_node->p_node->color = 1;
        new_node = new_node->p_node->p_node;
      } else {
        if (new_node == new_node->p_node->lc_node) {
          new_node = new_node->p_node;
          in_root = RBT_right_rotate(in_root, new_node);
        }
        new_node->p_node->color = 0;
        new_node->p_node->p_node->color = 1;
        in_root = RBT_left_rotate(in_root,new_node->p_node->p_node);
      }
    }
    else {
      cout << "Entra al else" << "\n";
      u   = new_node->p_node->p_node->rc_node; // uncle
      if (u != 0) {
      if (u->color == 1) {
        cout << "mirror case 3.1" <<"\n";
        u->color = 0;
        new_node->p_node->color = 0;
        new_node->p_node->p_node->color = 1;
        new_node = new_node->p_node->p_node;
      }
      }
     else {
        if (new_node == new_node->p_node->rc_node) {
          cout << "mirror case 3.2.2" <<"\n";
           cout << "Tree before left rotate" <<"\n";
          printHelper(in_root, "", true);
          new_node = new_node->p_node;
          in_root = RBT_left_rotate(in_root,new_node);
          cout << "Tree after left rotate" <<"\n";
          printHelper(in_root, "", true);
        }
        cout << "Mirror case 3.2.1" <<"\n";
        cout << "Tree before right rotate" <<"\n";
          printHelper(in_root, "", true);
        new_node->p_node->color = 0;
        new_node->p_node->p_node->color = 1;
        in_root = RBT_right_rotate(in_root,new_node->p_node->p_node);
        cout << "Tree after right rotate" <<"\n";
        printHelper(in_root, "", true);
      }
    }
    if (new_node == in_root) {
      break;
    }
  }
  in_root->color = 0;
return status;
}
