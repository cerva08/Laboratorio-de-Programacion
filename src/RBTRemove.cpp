#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "../include/RBT.h"

using namespace std;

int RBT_node_remove(
  struct RBT_node  *in_root,
  float  value_to_remove,
  struct RBT_node *new_root){

  struct RBT_node aux = {NULL, NULL, NULL, 0, 'B'};
  struct RBT_node temp = {NULL, NULL, NULL, 0, 'B'};
  struct RBT_node parent_aux = {NULL, NULL, NULL, 0, 'B'};

  RBT_search(in_root,value_to_remove, &aux);

  if (aux.value != value_to_remove){
      cout << "Check1\n"; 
      return -4; //TODO: check return value
      
  }
  else if (aux.lc_node == NULL && aux.rc_node == NULL){ // No children
      
      if ((aux.p_node)->lc_node->value == aux.value){ // Es hoja izquierda
          (aux.p_node)->lc_node = NULL;
          cout << "Check6" << "\n";
          return 1;
      }
      else { // Es hoja derecha
          cout << "Check7" << "\n";
          (aux.p_node)->rc_node = NULL;
          return 1;
      }
      
      cout << "Check5" << "\n";
      return 0;
  }
  else if (aux.lc_node == NULL){ // Only right child
      cout << "only right child" << "\n";

        

      aux.p_node = NULL;
      //aux.rc_node->p_node =  
      //aux = new_root;
      //new_root = aux.rc_node;
      //aux = NULL;

  }
  else if (aux.rc_node == NULL){ // Only left child
      //aux = new_root;
      //new_root = aux.lc_node;
      //aux = NULL;

  }
  else { // Left and right child
      //aux = RBT_min_get(in_root, ,rc_node);
      //new_root.value = aux.value;
      //new_root.rc_node = ;
  }  
      cout << "Check2\n";

      return 0;
  
};
