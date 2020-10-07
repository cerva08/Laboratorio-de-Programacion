#include <stdio.h>
#include <stdlib.h> 
#include <iostream>
#include "../include/RBT.h"

using namespace std;

struct RBT_node* RBT_right_rotate(
    struct RBT_node*  in_root, 
    struct RBT_node*  rotation_node){

    bool is_root = false;
    if (in_root == rotation_node){
        is_root = true;
    }

    struct RBT_node* temp = rotation_node->lc_node;
    rotation_node->lc_node = temp->rc_node;
    temp->p_node = rotation_node->p_node;

    if (temp->rc_node != NULL){
        temp->rc_node->p_node = rotation_node;
    }

    if (rotation_node->p_node == NULL){
        in_root = temp;
    } else if (rotation_node == rotation_node->p_node->rc_node){
        rotation_node->p_node->rc_node = temp;
    } else {
        rotation_node->p_node->lc_node = temp;
    }

    temp->rc_node = rotation_node;
    rotation_node->p_node = temp;

    if (is_root){
        return temp;
    } else {
        return in_root;
    }

}


struct RBT_node* RBT_left_rotate(
    struct RBT_node*  in_root, 
    struct RBT_node*  rotation_node){

    bool is_root = false;
    if (in_root == rotation_node){
        is_root = true;
    }

    struct RBT_node* temp = rotation_node->rc_node;
    rotation_node->rc_node = temp->lc_node;
    temp->p_node = rotation_node->p_node;

    if (temp->lc_node != NULL){
        temp->lc_node->p_node = rotation_node;
    }

    if (rotation_node->p_node == NULL){
        in_root = temp;
    } else if (rotation_node == rotation_node->p_node->lc_node){
        rotation_node->p_node->lc_node = temp;
    } else {
        rotation_node->p_node->rc_node = temp;
    }

    temp->lc_node = rotation_node;
    rotation_node->p_node = temp;

    if (is_root){
        return temp;
    } else {
        return in_root;
    }

}