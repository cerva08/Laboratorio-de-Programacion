#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "../include/RBT.h"
#include <vector>
using namespace std;
void print(std::vector <float> const &a, int size) {
   //cout << " VALUES TO ARE: " ; 
   for(int i=0; i < size; i++) {
   std::cout << a.at(i) << ' ';
   }
   cout << "\n";
}
int main(){
    int status = 0;
    cout << "RED BLACK TREES" << "\n";
    cout << "EXAMPLE 1" << "\n";
    vector<float> in_number_list;
    int dato = 1;
    // while (dato) {
	// cout << "Ingrese un dato" << "\n";
	// cin >> dato;
	// if (dato == 0) {
	// 	break;
	// } else {
	// 	in_number_list.push_back(dato);
	// }
    // }
    in_number_list.push_back(13);
    in_number_list.push_back(8);
    in_number_list.push_back(17);
    in_number_list.push_back(1);
    in_number_list.push_back(11);
    in_number_list.push_back(6);
    in_number_list.push_back(15);
    in_number_list.push_back(25);
    in_number_list.push_back(22);
    in_number_list.push_back(27);
    int size = static_cast<int>(in_number_list.size());
    // print(in_number_list, size);
    RBT_node* new_root_node = new RBT_node ;
    status = RBT_create(in_number_list ,size, &new_root_node);
    cout << "RED BLACK TREE AFTER INSERTIONS" <<"\n";
    RBT_print(new_root_node, "", true);
    cout << "DELETE 11" <<"\n";
    RBT_node_remove(new_root_node, 11, new_root_node);
    RBT_print(new_root_node, "", true);
    cout << "SEARCH 20" << "\n";
    struct RBT_node *found_node;
    RBT_search(new_root_node, 20, found_node);
    cout << "SEARCH 11" << "\n";
    int search = RBT_search(new_root_node, 11, found_node);
    cout << "SEARCH MIN" << "\n";
    struct RBT_node *min_node;
    int min = RBT_min_get(new_root_node, min_node);
    cout << "MIN VALUE ARE: " << min_node->value <<"\n";
    cout << "SEARCH MAX" << "\n";
    struct RBT_node *max_node;
    int max = RBT_max_get(new_root_node, max_node);
    cout << "MAX VALUE ARE: " << min_node->value <<"\n";
    return status;
}
