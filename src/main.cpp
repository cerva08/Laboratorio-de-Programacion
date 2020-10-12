#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "../include/RBT.h"
#include <vector>
using namespace std;
void print(std::vector <float> const &a, int size) {
   cout << "Los datos ingresados son " ; 
   for(int i=0; i < size; i++) {
   std::cout << a.at(i) << ' ';
   }
   cout << "\n";
}
int main(){
    int status = 0;
    cout << "Cree su Red Black Tree, para detenerse ingrese 0" << "\n";
    vector<float> in_number_list;
    int dato = 1;
    while (dato) {
	cout << "Ingrese un dato" << "\n";
	cin >> dato;
	if (dato == 0) {
		break;
	} else {
		in_number_list.push_back(dato);
	}
    }
    int size = static_cast<int>(in_number_list.size());
    print(in_number_list, size);
    RBT_node* new_root_node = new RBT_node ;
    status = RBT_create(in_number_list ,size, &new_root_node);
    cout << "Red black tree" <<"\n";
    RBT_print(new_root_node, "", true);
    return status;
}
