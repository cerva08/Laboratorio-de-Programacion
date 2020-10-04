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
        //Initialized each node 
        new_node.value= 0;
		new_node.p_node = nullptr;
		new_node.lc_node = nullptr;
		new_node.rc_node = nullptr;
		new_node.color = 0;
        for (int j = 0; j < 3; j++) {
            //Mejorar esta parte 
            if (j == 0) {
                in_root.value = 0;
                in_root.lc_node = nullptr;
                in_root.rc_node = nullptr;
                in_root.p_node = nullptr;
                in_root.color = '0';
            }
            new_node.value = in_number_list[j];
            int insert = RBT_node_add(&in_root, &new_node, &new_root);
            in_root = new_root;
            new_node = new_node;
            // cout << "Color root funcion "<<in_root.color << '\n';
            // cout << "Valor root funcion "<<in_root.value << '\n';
            // cout << "Color nuevo nodo funcion "<<new_node.color << '\n';
            // cout << "Valor nuevo nodo funcion "<<new_node.value << '\n';
        }
        return 0;
    };
