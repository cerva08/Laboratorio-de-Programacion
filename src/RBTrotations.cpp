#include <stdio.h>
#include <stdlib.h> 
#include <iostream>
#include "include/RBT.h"

using namespace std;

int RBT_right_rotate(
    struct RBT_node*  in_root, 
    struct RBT_node*  rotation_node){

    struct RBT_node* temp = rotation_node->lc_node;
    rotation_node->lc_node = temp->rc_node;
    temp->rc_node->p_node = rotation_node;
    temp->p_node = rotation_node->p_node;

    if (rotation_node->p_node == NULL){
        in_root = temp;
    } else if (rotation_node == rotation_node->p_node->rc_node){
        rotation_node->p_node->rc_node = temp;
    } else {
        rotation_node->p_node->lc_node = temp;
    }

    temp->rc_node = rotation_node;
    rotation_node->p_node = temp;

    return 0;

}


int RBT_left_rotate(
    struct RBT_node*  in_root, 
    struct RBT_node*  rotation_node){

    struct RBT_node* temp = rotation_node->rc_node;
    rotation_node->rc_node = temp->lc_node;
    temp->lc_node->p_node = rotation_node;
    temp->p_node = rotation_node->p_node;

    if (rotation_node->p_node == NULL){
        in_root = temp;
    } else if (rotation_node == rotation_node->p_node->lc_node){
        rotation_node->p_node->lc_node = temp;
    } else {
        rotation_node->p_node->rc_node = temp;
    }

    temp->lc_node = rotation_node;
    rotation_node->p_node = temp;

    return 0;

}