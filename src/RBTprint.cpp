
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "../include/RBT.h"

using namespace std;	
    
    void printHelper(struct RBT_node *new_root_node, string indent, bool last) {
		// print the tree structure on the screen
	   	if (new_root_node != nullptr) {
		   cout<<indent;
		   if (last) {
		      cout<<"R----";
		      indent += "     ";
		   } else {
		      cout<<"L----";
		      indent += "|    ";
		   }  
		   int color;
		   if (new_root_node->color == 'R') {
			   color = 1;
		   } else {
			   color = 0;
		   }
           string sColor = color?"RED":"BLACK";
		   cout<<new_root_node->value<<"("<<sColor<<")"<<endl;
		   printHelper(new_root_node->lc_node, indent, false);
		   printHelper(new_root_node->rc_node, indent, true);
		}
	}
