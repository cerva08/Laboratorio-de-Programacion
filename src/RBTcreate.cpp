#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "../include/RBT.h"
#include <vector>
using namespace std;

int RBT_create(
    std::vector <float> const &in_number_list, int size,
    struct RBT_node **new_root_node)
    {
        RBT_node* in_root = new  RBT_node;
        RBT_node* new_root = new RBT_node;
        int status = 0;
        if (size < 1) {
            cout << "List of numbers is empty, please insert a value" << "\n";
            return RBT_INVALID_PARAM;
        }
        float init_root_value = in_number_list[0];
        in_root->value = init_root_value;
        cout << "INSERT VALUE: " << in_number_list[0] <<"\n";
        RBT_print(in_root, "", true);
        in_root->color = 'B';
        for (int j = 1; j < size; j++) {
            RBT_node* new_node = new RBT_node;
            new_node->value = in_number_list[j];
            status = RBT_node_add(in_root, new_node, &new_root);
            cout << "INSERT VALUE: " << in_number_list[j]  <<"\n";
            RBT_print(new_root, "", true);
            if (status < 0) return status;
            in_root = new_root;

        }
        *new_root_node = in_root;
        return status;
    }
