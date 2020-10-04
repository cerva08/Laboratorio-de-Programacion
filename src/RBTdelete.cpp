#include <stdio.h>
#include <stdlib.h> 
#include <iostream>
#include "../include/RBT.h"

using namespace std;

int BST_remove(
    struct RBT_node* in_root, 
    float value_to_remove){

    bool left_child = false;
    bool right_child = false;
    struct RBT_node node_to_delete;

    if (in_root == NULL){
        return -4;
    }

    RBT_search(in_root,value_to_remove,&node_to_delete);

    if (node_to_delete.p_node != NULL && node_to_delete.value == node_to_delete.p_node->lc_node->value){
        left_child = true;
    } else { 
        right_child = true;
    }

    if (node_to_delete.lc_node == NULL && node_to_delete.rc_node == NULL){
        if (left_child){
            node_to_delete.p_node->lc_node = NULL;
        } else {
            node_to_delete.p_node->rc_node = NULL;
        }
    }

    else if (node_to_delete.lc_node == NULL){
        if (left_child) {
            node_to_delete.p_node->lc_node = node_to_delete.rc_node;
        } else {
            node_to_delete.p_node->rc_node = node_to_delete.rc_node;
        }

    } else if (node_to_delete.rc_node == NULL)
        if (left_child) {
            node_to_delete.p_node->lc_node = node_to_delete.lc_node;
        } else {
            node_to_delete.p_node->rc_node = node_to_delete.lc_node;
        }

    else {
        struct RBT_node new_to_delete;
        struct RBT_node *node_to_delete_address = node_to_delete.rc_node->p_node;
        RBT_min_get(node_to_delete.rc_node,&new_to_delete);
        
        node_to_delete_address->value = new_to_delete.value;
        BST_remove(node_to_delete.rc_node, new_to_delete.value);
    }


    return 0;
}

