#include <stdio.h>
#include <stdlib.h> 
#include <iostream>
#include "../include/RBT.h"
#include "RBTcreate.cpp"
int main(){
    float in_number_list[5] = {4 , 2, 3};
    struct RBT_node new_root_node = {};
    int create = RBT_create(in_number_list , &new_root_node);
    return 0;
}