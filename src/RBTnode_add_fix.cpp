#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "../include/RBT.h"
using namespace std;
struct RBT_node* RBT_node_add_fix(struct RBT_node* in_root, struct RBT_node* new_node){
  struct RBT_node* u;;
  while (new_node->p_node->color == 'R') {
    if (new_node->p_node == new_node->p_node->p_node->rc_node) {
      u = new_node->p_node->p_node->lc_node;
      if (u != 0) {
          if (u->color == 'R') {
            u->color = 'B';
            new_node->p_node->color = 'B';
            new_node->p_node->p_node->color = 'R';
            new_node = new_node->p_node->p_node;
          }
      } else {
        if (new_node == new_node->p_node->lc_node) {
          new_node = new_node->p_node;
          in_root = RBT_right_rotate(in_root, new_node);
        }
        new_node->p_node->color = 'B';
        new_node->p_node->p_node->color = 'R';
        in_root = RBT_left_rotate(in_root,new_node->p_node->p_node);
      }
    }
    else {
      u   = new_node->p_node->p_node->rc_node; // uncle
      if (u != 0) {
        if (u->color == 'R') {
          u->color = 'B';
          new_node->p_node->color = 'B';
          new_node->p_node->p_node->color = 'R';
          new_node = new_node->p_node->p_node;
        }
      }
     else {
        if (new_node == new_node->p_node->rc_node) {
          new_node = new_node->p_node;
          in_root = RBT_left_rotate(in_root,new_node);
        }
        new_node->p_node->color = 'B';
        new_node->p_node->p_node->color = 'R';
        in_root = RBT_right_rotate(in_root,new_node->p_node->p_node);
      }
    }
    if (new_node == in_root) {
      break;
    }
  }
  in_root->color = 'B';
return in_root;
}
