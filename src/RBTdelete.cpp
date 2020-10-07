#include <stdio.h>
#include <stdlib.h> 
#include <iostream>
#include "../include/RBT.h"

using namespace std;

struct RBT_node* get_min_address(
    struct RBT_node min){
    if (min.p_node != NULL && min.value == min.p_node->lc_node->value){ //left
        return min.p_node->lc_node;
    } else {  // right
        return min.p_node->rc_node;
    }
}

struct RBT_node* RBT_Transplant(
    struct RBT_node* in_root, 
    struct RBT_node* node_to_replace, 
    struct RBT_node* replacing_node){

    struct RBT_node* new_root = in_root;

    if (node_to_replace->p_node == NULL){ // note to replace is root
        new_root = replacing_node;
        new_root->lc_node = node_to_replace->lc_node;
        new_root->rc_node = node_to_replace->rc_node;

    } else if (node_to_replace == node_to_replace->p_node->lc_node) { // node te replace is left child
        node_to_replace->p_node->lc_node = replacing_node;

    } else { // node te replace is right child
        node_to_replace->p_node->rc_node = replacing_node;
    }

    if (replacing_node != NULL){
        replacing_node->p_node = node_to_replace->p_node;
    }

    return new_root;
}

int BST_remove(
    struct RBT_node* in_root, 
    float value_to_remove,
    struct RBT_node* new_root){

    struct RBT_node node_to_delete;
    struct RBT_node *double_black_node;
    struct RBT_node *root = in_root;
    char original_color;

    if (in_root == NULL){
        return -4;
    }

    int search_result = RBT_search(in_root,value_to_remove,&node_to_delete);
    if (search_result = -4){
        return -4;
    }

    original_color = node_to_delete.color;

    if (node_to_delete.lc_node == NULL){
        double_black_node = node_to_delete.rc_node;

        root = RBT_Transplant(root,&node_to_delete,node_to_delete.rc_node);
        
    } else if (node_to_delete.rc_node == NULL){
        double_black_node = node_to_delete.lc_node;

        root = RBT_Transplant(root,&node_to_delete,node_to_delete.lc_node);

    } else {
        struct RBT_node new_to_delete;
        struct RBT_node *new_to_delete_address;
        struct RBT_node *node_to_delete_address = node_to_delete.rc_node->p_node;

        RBT_min_get(node_to_delete.rc_node,&new_to_delete);
        new_to_delete_address = get_min_address(new_to_delete);

        original_color = new_to_delete_address->color;

        if (new_to_delete_address->rc_node == NULL){
            *double_black_node = {NULL,NULL,new_to_delete_address,-1,'B'};
        }else {
            double_black_node = new_to_delete_address->rc_node;
        }

        if (new_to_delete_address->p_node == node_to_delete_address){
            double_black_node->p_node = new_to_delete_address;  
            
        } else {
            root = RBT_Transplant(root,new_to_delete_address,new_to_delete_address->rc_node);
            new_to_delete_address->rc_node = node_to_delete.rc_node;
            new_to_delete_address->rc_node->p_node = new_to_delete_address;
        }

        root = RBT_Transplant(root,node_to_delete_address,new_to_delete_address);
        new_to_delete_address->lc_node = node_to_delete.lc_node;
        new_to_delete_address->lc_node->p_node = new_to_delete_address;
        new_to_delete_address->color = node_to_delete.color;  
        
    }

    if (original_color == 'B'){
        root = RBT_remove_fixup(root,double_black_node);
    }

    new_root->color = root->color;
    new_root->value = root->value; 
    new_root->lc_node = root->lc_node;
    new_root->rc_node = root->rc_node; 
    new_root->p_node = root->p_node;

    return 0;
}


struct RBT_node* RBT_remove_fixup(
    struct RBT_node* in_root, 
    struct RBT_node* node_x){
    
    struct RBT_node* root_pointer = in_root;
    struct RBT_node* sibling;

    while (node_x != root_pointer && node_x->color == 'B'){
        if(node_x == node_x->p_node->lc_node){ // if x_node is left child
            if (node_x->p_node->rc_node == NULL){
                *sibling = {NULL,NULL,node_x->p_node,-1,'B'};
            } else {
                sibling = node_x->p_node->rc_node;
            }

            if (sibling->lc_node == NULL){
                struct RBT_node if_null = {NULL,NULL,sibling,-1,'B'};
                sibling->lc_node = &if_null;
            }
            if (sibling->rc_node == NULL){
                struct RBT_node if_null = {NULL,NULL,sibling,-1,'B'};
                sibling->rc_node = &if_null;
            }
            
            
            if (sibling->color == 'R'){  //case 1
                sibling->color = 'B';
                node_x->p_node->color = 'R';
                root_pointer = RBT_left_rotate(root_pointer,node_x->p_node);
                sibling = node_x->p_node->rc_node;
            }

            if (sibling->lc_node->color == 'B' && sibling->rc_node->color == 'B'){ //case 2
                sibling->color = 'R';
                node_x = node_x->p_node;

            } else { 
                if (sibling->rc_node->color == 'B'){  //case 3
                    sibling->lc_node->color = 'B';
                    sibling->color = 'R';
                    root_pointer = RBT_right_rotate(root_pointer,sibling);
                    sibling = node_x->p_node->rc_node;
                }

                sibling->color = node_x->p_node->color; //case 4
                node_x->p_node->color = 'B';
                sibling->rc_node->color = 'B';
                root_pointer = RBT_left_rotate(root_pointer,node_x->p_node);
                node_x = root_pointer;
            }

        } else { // if x_node is right child
            if (node_x->p_node->lc_node == NULL){ // sibling of x
                *sibling = {NULL,NULL,node_x->p_node,-1,'B'};
            } else {
                sibling = node_x->p_node->lc_node;
            }

            if (sibling->lc_node == NULL){
                struct RBT_node if_null = {NULL,NULL,sibling,-1,'B'};
                sibling->lc_node = &if_null;
            }
            if (sibling->rc_node == NULL){
                struct RBT_node if_null = {NULL,NULL,sibling,-1,'B'};
                sibling->rc_node = &if_null;
            }
            
            if (sibling->color == 'R'){  //case 1
                sibling->color = 'B';
                node_x->p_node->color = 'R';
                root_pointer = RBT_right_rotate(root_pointer,node_x->p_node);
                sibling = node_x->p_node->lc_node;
            }

            if (sibling->rc_node->color == 'B' && sibling->lc_node->color == 'B'){ //case 2
                sibling->color = 'R';
                node_x = node_x->p_node;

            } else { 
                if (sibling->lc_node->color == 'B'){  //case 3
                    sibling->rc_node->color = 'B';
                    sibling->color = 'R';
                    root_pointer = RBT_left_rotate(root_pointer,sibling);
                    sibling = node_x->p_node->lc_node;
                }

                sibling->color = node_x->p_node->color; //case 4
                node_x->p_node->color = 'B';
                sibling->lc_node->color = 'B';
                root_pointer = RBT_right_rotate(root_pointer,node_x->p_node);
                node_x = root_pointer;

            }

        }

    }
    sibling->lc_node = NULL;
    sibling->rc_node = NULL;
    node_x->color = 'B';

    return root_pointer;
}

