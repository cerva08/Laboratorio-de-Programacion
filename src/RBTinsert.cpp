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
    new_node->value = new_node->value;
    new_node->lc_node = nullptr;
    new_node->rc_node = nullptr;
    new_node->color = '1';
    cout << "root value "<<in_root->value << "\n";
    cout << "root color "<<in_root->color << "\n";
    cout << "New node value "<<new_node->value << "\n";
    cout << "New node color "<<new_node->color << "\n";
    struct RBT_node *y = nullptr;
    struct RBT_node x = *in_root;
    struct RBT_node *ip;
    ip = &x;
    cout << "Puntero entrada"<< in_root<< "\n";
    cout << "Puntero ip"<< ip << "\n";
    if (x.value ==0) {
        ip = nullptr;
    }
    while ( ip != nullptr ) {
        if (new_node->value ==3) {
          cout << "Hijo izq de root"<< ip->lc_node << "\n";      
        }
          y = ip;
          if (new_node->value < ip->value) {
            ip = ip->lc_node;
          } else {
           ip = ip->rc_node;

          }
      }
    new_node->p_node = y;
        if (y == nullptr) {
          new_root->value = new_node->value;
          new_root->color = '0';
        } else if (new_node->value < y->value) {
            cout << "Entra if" "\n";
            y->lc_node = new_node;
            cout << "Hijo izq de y"<< y->lc_node->value << "\n"; 
        } else {
            y->rc_node = new_node;
        }
        if (new_node->p_node == nullptr) {
            cout << "Linea 47 "<< "\n";
            new_node->color = '0';
            return 0;
        }
        if (new_node->p_node->p_node == nullptr) {
            cout << "Linea 51 "<< "\n";
            return 0;
        } 
        //necesito que el padre y abuelo no sean nulos para llamar
        int fix_error = RBT_node_add_fix(in_root, new_node);

    return 0;
};
