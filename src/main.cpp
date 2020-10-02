#include "../include/RBT.h"
#include <stdio.h>
#include <stdlib.h>


int RBT_node_add(RBT_node*  in_root, RBT_node*  new_node, RBT_node* new_root){
  // int val = new_node->value;
  if ( new_node->first_node == true ){
    new_root->value = new_node->value;
    new_root->color = 0;
  } else {
    RBT_node y = nullptr;
    RBT_node x = in_root;
    while (x !=a){}
    RBT_node y = x;
    if
  }
  return 0;
};
// RBT_node *lc_node;
//
// /** Puntero al nodo hijo derecho */
// RBT_node *rc_node;
//
// /** Puntero al nodo padre */
// RBT_node *p_node;
//
// /** Número flotante asociado al nodo */
// int value;
//
// /** Letra que indica el color asociado al nodo */
// int color;
int RBT_create(float in_number_list[], RBT_node* new_root_node){
  int size_number_list = 5;
  struct RBT_node new_node = {};
  struct RBT_node new_root = {};
  struct RBT_node in_root = {};
  for (int i = 0; i < size_number_list ; i ++ ){
    new_node.first_node = false;
    if (i == 0 ){
      new_node.color = 0;
      new_node.lc_node = nullptr;
      new_node.rc_node = nullptr;
      new_node.p_node = nullptr;
      new_node.first_node = true;
    };
    new_node.value = in_number_list[i];
    int insert = RBT_node_add(&in_root,&new_node,&new_root);

  }
  return 0;
};
int main(){
  struct RBT_node node;
  // int RBT_create(
  //   float                     *in_number_list,
  //   struct RBT_node *new_root_node);
  float in_number_list[5] = { 1, 2, 3, 4, 5 };
//   RBT_node *lc_node;
//
//  /** Puntero al nodo hijo derecho */
//  RBT_node *rc_node;
//
//  /** Puntero al nodo padre */
// RBT_node *p_node;
//
//  /** Número flotante asociado al nodo */
//  int value;
//
//  /** Letra que indica el color asociado al nodo */
//  int color;
  // int value = 0;
  // int color = 0;
  // *lc_node = nullptr;
  // *rc_node = nullptr;
  // *p_node = nullptr;
  // struct RBT_node new_root_node = {value, color, *lc_node, *rc_node, *p_node};
  struct RBT_node new_root_node = {};
  int papa = RBT_create(in_number_list,  &new_root_node);
  return 0;
};
