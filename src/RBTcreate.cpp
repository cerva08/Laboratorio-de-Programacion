#include <stdio.h>
#include <stdlib.h> 
#include <iostream>
#include "RBTinsert.cpp"
using namespace std;

int RBT_create(
    float  *in_number_list,
    struct RBT_node *new_root_node) 
    {
        struct RBT_node in_root = {};
        struct RBT_node new_node = {};
        struct RBT_node new_root= {};
        for (int j = 0; j < 3; j++) {
            new_node.value = in_number_list[j];
            int insert = RBT_node_add(&in_root, &new_node, &new_root);
            in_root = new_root;
        }
        return 0;
    };
