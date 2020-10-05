#include <stdio.h>
#include <stdlib.h> 
#include <iostream>
#include "../include/RBT.h"

using namespace std;

int RBT_right_rotate(
    struct RBT_node*  in_root, 
    struct RBT_node*  rotation_node,
    struct RBT_node* new_root){

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
        new_root_setter(temp,new_root);
    }

    return 0;

}


int RBT_left_rotate(
    struct RBT_node*  in_root, 
    struct RBT_node*  rotation_node,
    struct RBT_node* new_root){

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
        new_root_setter(temp,new_root);
    }

    return 0;

}

int new_root_setter (
    struct RBT_node* new_root_setter_values,
    struct RBT_node* new_root){

    new_root->color = new_root_setter_values->color;
    new_root->value = new_root_setter_values->value; 
    new_root->lc_node = new_root_setter_values->lc_node;
    new_root->rc_node = new_root_setter_values->rc_node; 
    new_root->p_node = new_root_setter_values->p_node;

    return 0;

}