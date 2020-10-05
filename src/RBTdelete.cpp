#include <stdio.h>
#include <stdlib.h> 
#include <iostream>
#include "../include/RBT.h"

using namespace std;

int BST_remove(
    struct RBT_node* in_root, 
    float value_to_remove,
    struct RBT_node *new_root){

    bool left_child = false;
    bool right_child = false;
    struct RBT_node node_to_delete;
    struct RBT_node *double_black_node;
    char original_color;

    if (in_root == NULL){
        return -4;
    }

    RBT_search(in_root,value_to_remove,&node_to_delete);
    original_color = node_to_delete.color;

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

    } else if (node_to_delete.lc_node == NULL){
        double_black_node = node_to_delete.rc_node;

        if (left_child) {
            node_to_delete.p_node->lc_node = node_to_delete.rc_node;
        } else {
            node_to_delete.p_node->rc_node = node_to_delete.rc_node;
        }
        

    } else if (node_to_delete.rc_node == NULL){
        double_black_node = node_to_delete.lc_node;

        if (left_child) {
            node_to_delete.p_node->lc_node = node_to_delete.lc_node;
        } else {
            node_to_delete.p_node->rc_node = node_to_delete.lc_node;
        }

    } else {
        struct RBT_node new_to_delete;
        struct RBT_node *new_to_delete_address = &new_to_delete;
        struct RBT_node *node_to_delete_address = node_to_delete.rc_node->p_node;

        RBT_min_get(node_to_delete.rc_node,&new_to_delete);

        original_color = new_to_delete.color;
        double_black_node = new_to_delete.rc_node;

        if (new_to_delete.p_node == node_to_delete_address && double_black_node != NULL){
            double_black_node->p_node = new_to_delete_address;  //revisar
            //cout << double_black_node->p_node << endl;
        }
        
        node_to_delete_address->value = new_to_delete.value;
        BST_remove(node_to_delete.rc_node, new_to_delete.value, in_root);
    }

    if (original_color == 'B'){
        RBT_remove_fixup(in_root,double_black_node);
    }

    return 0;
}

// int RBT_remove_fixup(
//     struct RBT_node* in_root, 
//     struct RBT_node* node_x){

//     struct RBT_node* root = in_root;
//     struct RBT_node* sibling;

//     while (node_x != in_root && node_x->color == 'B'){
//         if(node_x == node_x->p_node->lc_node){ // if x_node is left child
//             sibling = node_x->p_node->rc_node; // sibling of x
            
//             if (sibling->color == 'R'){  //case 1
//                 sibling->color = 'B';
//                 node_x->p_node->color = 'R';
//                 RBT_left_rotate(root,)
//             }
//         }

//     }

//     return 0;
// }