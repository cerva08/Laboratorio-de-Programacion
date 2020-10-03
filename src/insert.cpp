#include "../include/RBT.h"
#include <stdio.h>
#include <stdlib.h>


/* void infect(const int infectiousness, agent* turtles, const agent* infected_turtle){
    int chance_of_infecting, posx, posy;

    if(infected_turtle -> sick && !infected_turtle -> dead){
        for (int i = 0; i < carrying_capacity; i++){
            chance_of_infecting = rand() % 101;

            if (chance_of_infecting < infectiousness && !turtles[i].dead){
                posx= (fabs((infected_turtle->posX) - (turtles[i].posX)));
                posy= (fabs((infected_turtle->posY) - (turtles[i].posY)));
                
                if (posx < 2 &&  posy < 2){ 
                    if (!turtles[i].sick && turtles[i].remaining_immunity == 0 ){
                        get_sick(&turtles[i]);
                    }
                }
            }

        }
    }
}; */

int RBT_node_add( struct RBT_node  in_root, struct RBT_node  new_node, struct RBT_node *new_root) {
    x =  in_root;
    if (x->p_node == nullptr) {
            printf("Here")
        }
};

/* Insert {node_to_insert, tree} {
    x = tree->root
    #Si la raíz es null, el nuevo elemento sera la raíz. 
    if (x == null) {
        tree->root = node_to_insert
        node_to_insert -> color = black #La raiz debe ser negra
    } else {
        #Si no es null, se moverá el puntero según el valor el nodo a
        # insertar hasta encontrar un elemento vacío. 
        while (x != null) {
            y = x #Se almacena el ultimo valor antes de que sea null,
            #este sera el padre del nodo a insertar
            if (node_to_insert < x) {
                #Si es menor se recorre la rama izquierda
                x = x-> left 
            } else {
                #Si es mayor se recorre la rama derecha
                x = x -> right
            }
        }
        # y es el padre del nodo a insertar
        node_to_insert -> parent = y 
        if (node_to_insert  < y){
            #Como es menor sera el hijo izquierdo 
            y -> left = node_to_insert
        } else {
            #Como es mayor sera el hijo derecho 
            y -> right = node_to_insert
        }
        node_to_insert -> color = red 
        #Se corrigen las violaciones dadas
        Insert_fix_errors(node_to_insert,tree)
    }
}

Insert_fix_errors(node_to_insert,tree) {
    while (node_to_insert->parent->color == red) {
        if (node_to_insert->parent == node_to_insert->grandparent-> left) {
            y = node_to_insert->grandparent -> right
            if {y->color == red } {
                #Al entrar a este if, se presenta el tercer escenario 
                #Tanto el padre como el tío  son rojos. 
                #Cambia color el padre
                node_to_insert->parent->color = black
                #Cambia de color el tio 
                y->color = black 
                #Cambia de color el abuelo 
                node_to_insert->grandparent->color = red
                node_to_insert = node_to_insert->grandparent
            } else if {node_to_insert == node_to_insert->parent->right} {
                node_to_insert = node_to_insert->parent
                LEFT-ROTATE(tree, node_to_insert)
            }
            node_to_insert->parent->color = black 
            node_to_insert->grandparent->color = red 
            RIGHT-ROTATE(tree, node_to_insert->grandparent)
        }
        else {
            # se hace el mismo código pero intercambiando left con right
            # el código es simétrico
        }
    }
} */