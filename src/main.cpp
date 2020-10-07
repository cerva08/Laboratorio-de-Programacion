#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "../include/RBT.h"
//#include "RBTcreate.cpp"


int main(){
    int status = 0;
    float in_number_list[3] = {4, 2, 3};
    RBT_node* new_root_node = new RBT_node ;
    // RBT_node* aux_node = new RBT_node ;
    status = RBT_create(in_number_list , 3, &new_root_node);
    int root = 1;
  	if (root) {
    		printHelper(new_root_node, "", true);
	  }
    // aux_node = new_root_node;
    // std::cout << "Imprimiendo arbol completo" << '\n';
    // for (int i = 0; i < 3; i++) {
    //   std::cout << " Value :" << aux_node->value <<'\n';
    //   aux_node = aux_node->lc_node;
    // }
    return status;
};
