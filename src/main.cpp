#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "../include/RBT.h"
//#include "RBTcreate.cpp"


int main(){
    int status = 0;
    float in_number_list[9] = {1,2,3,4,5,6,7,8,9};
    RBT_node* new_root_node = new RBT_node ;
    // RBT_node* aux_node = new RBT_node ;
    status = RBT_create(in_number_list , 9, &new_root_node);
    int root = 1;
  	// if (root) {
    // 		printHelper(new_root_node, "", true);
	// }
    return status;
};
