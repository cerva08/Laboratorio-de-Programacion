#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "RBTrotations.cpp"

int RBT_node_add_fix(struct RBT_node* in_root, struct RBT_node* new_node){
  struct RBT_node* temp = in_root;
  struct RBT_node* u;
  cout << "Entra funcion "<< "\n";
  cout << "color padre "<< new_node->p_node->color <<"\n";
  while (new_node->p_node->color == '1') {
    cout << "Entra al  while";
    if (new_node->p_node == new_node->p_node->p_node->rc_node) {
      u = new_node->p_node->p_node->lc_node; // tio
      if (u->color == '1') {
        // caso 3.1
        u->color = '0';
        new_node->p_node->color = '0';
        new_node->p_node->p_node->color = '1';
        new_node = new_node->p_node->p_node;
        // cout << "HERE00";
      } else {
        if (new_node == new_node->p_node->lc_node) {
          // caso 3.2.2
          new_node = new_node->p_node;
          //rightRotate(new_node);
        //   cout << "HERE11";
          int right_0 = RBT_right_rotate(temp, new_node);

        }
        // caso 3.2.1
        new_node->p_node->color = '0';
        new_node->p_node->p_node->color = '1';
        //leftRotate(new_node->p_node->p_node);
        int left_0 = RBT_left_rotate(temp, new_node);
      }
    } else {
      u = new_node->p_node->p_node->rc_node; // uncle

      if (u->color == '1') {
        // mirror caso 3.1
        u->color = '0';
        new_node->p_node->color = '0';
        new_node->p_node->p_node->color = '1';
        new_node = new_node->p_node->p_node;
        // cout << "HERE22";
      } else {
        if (new_node == new_node->p_node->rc_node) {
          // caso espejo 3.2.2
          new_node = new_node->p_node;
          //leftRotate(new_node);
        //   cout << "HERE33";
          int left_0 = RBT_left_rotate(temp, new_node);

        }
        // caso espejo 3.2.1
        new_node->p_node->color = '0';
        new_node->p_node->p_node->color = '1';
        //rightRotate(new_node->p_node->p_node);
        // cout << "HERE44";
        int right_1 = RBT_right_rotate(temp, new_node);
      }
    }
    if (new_node == in_root) {
    //   cout << "HERE55";
      break;
    }
  }
//   cout << "Hello3";
  temp->color = '0';

return 0;
}