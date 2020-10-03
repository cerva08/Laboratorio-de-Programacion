#include <stdio.h>
#include <stdlib.h> 
#include <iostream>
#include "../include/RBT.h"


using namespace std;

int RBT_max_get(
  struct RBT_node  *in_root,
  struct RBT_node *max_node){
  struct RBT_node *find_max = in_root;
    while (find_max->rc_node != NULL){
        find_max = find_max->rc_node;
      }
    max_node->color = find_max->color;
    max_node->value = find_max->value; 
    max_node->lc_node = find_max->lc_node;
    max_node->rc_node = find_max->rc_node; 
    max_node->p_node = find_max->p_node; 
    return 0; 
  }


int RBT_min_get(
  struct RBT_node  *in_root,
  struct RBT_node *min_node){
  struct RBT_node *find = in_root;
    while (find->lc_node != NULL){
        find = find->lc_node;
      }
    min_node->color = find->color;
    min_node->value = find->value; 
    min_node->lc_node = find->lc_node;
    min_node->rc_node = find->rc_node; 
    min_node->p_node = find->p_node; 
    return 0; 
  }


int RBT_search(
  struct RBT_node  *in_root,
  float num,
  struct RBT_node *found_node){
        
        struct RBT_node *temp = in_root;
        
        while (temp != NULL) {
            if(num != temp->value){ 
                if (num > temp->value) 
                    temp = temp->rc_node; 
  
                else if (num < temp->value) 
                    temp = temp->lc_node;
            } 
            else{
                found_node->color = temp->color;
                found_node->value = temp->value; 
                found_node->lc_node = temp->lc_node;
                found_node->rc_node = temp->rc_node; 
                found_node->p_node = temp->p_node; 
                return 0;
            }
    } 
    return -4; 
} 

