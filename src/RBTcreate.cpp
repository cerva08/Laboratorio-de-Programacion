#include <stdio.h>
#include <stdlib.h>
#include <iostream>
//#include "RBTinsert.cpp"
#include "../include/RBT.h"
using namespace std;

int RBT_create(
    float  *in_number_list,int size,
    struct RBT_node **new_root_node)
    {
        RBT_node* in_root = new  RBT_node;
        RBT_node* new_root = new RBT_node;
        int status = 0;
        if (size < 1) return RBT_INVALID_PARAM;
        float init_root_value = in_number_list[0];
        //Root inicializado
        in_root->value = init_root_value;
        in_root->color = 0;
        // cout << " create funcion: " <<'\n';
        // cout << " in_root value: " << in_root->value <<'\n';
        for (int j = 1; j < size; j++) {
            cout << " HERE" <<'\n';
            RBT_node* new_node = new RBT_node;
            new_node->value = in_number_list[j];
            //primer inroot nodo valido
            cout << " new_node value: " << new_node->value <<'\n';
            status = RBT_node_add(in_root, new_node, &new_root);
            if (status < 0) return status;
            in_root = new_root;

        }
        //Parametro de salida
        *new_root_node = in_root;
        return status;
    };
