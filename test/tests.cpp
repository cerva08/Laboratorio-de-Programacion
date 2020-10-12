#include "../include/RBT.h"
#include "gtest/gtest.h"


TEST(RBTinsert, positive){
    struct RBT_node N1;
    struct RBT_node N5;
    int status;
    N1 = {NULL, NULL, NULL, 1, 'B'};  
    N5 = {NULL, NULL, NULL, 5, 'R'}; //root  
    RBT_node* new_root = new RBT_node;
    status = RBT_node_add(&N1,&N5,&new_root);
    EXPECT_EQ(status, 0);

}

TEST(RBTinsert, negative){
    struct RBT_node N1;
    struct RBT_node N5;
    int status;
    N1 = {NULL, NULL, NULL, 1, 'B'};  
    N5 = {NULL, NULL, NULL, -5, 'R'}; //root  
    RBT_node* new_root = new RBT_node;
    status = RBT_node_add(&N1,&N5,&new_root);
    EXPECT_EQ(status, -1);

}

TEST(RBTcreate, positive){
    vector<float> in_number_list;
    in_number_list.push_back(1);
    in_number_list.push_back(2);
    in_number_list.push_back(3);
    int status;
    int size = 3;
    RBT_node* new_root = new RBT_node;
    status = RBT_create(in_number_list,size,&new_root);
    EXPECT_EQ(status, 0);

}
TEST(RBTcreate, negative){
    vector<float> in_number_list;
    int status;
    int size = 0;
    RBT_node* new_root = new RBT_node;
    status = RBT_create(in_number_list,size,&new_root);
    EXPECT_EQ(status, -1);

}

TEST(RBT_print, positive){
    vector<float> in_number_list;
    in_number_list.push_back(4);
    in_number_list.push_back(2);
    in_number_list.push_back(3);
    int status;
    int size = 3;
    RBT_node* new_root = new RBT_node;
    status = RBT_create(in_number_list,size,&new_root);
    RBT_print(new_root, "", true);
}

TEST(RBTmaxget, positive){
    struct RBT_node N13;
    struct RBT_node N8;
    struct RBT_node N17;
    struct RBT_node N1;
    struct RBT_node N11;
    struct RBT_node N15;
    struct RBT_node N25; 
    struct RBT_node N6; 
    struct RBT_node N22;
    struct RBT_node N27;
    struct RBT_node max_node; 
    int  status;
    

   
    N13 = {&N8, &N17, NULL, 13, 'B'}; // root  
    N8 = {&N1, &N11, &N13, 8, 'R'};       
    N17 = {&N15, &N25, &N13, 17, 'R'}; 
    N1 = {NULL, &N6, &N8, 1, 'B'}; 
    N11 = {NULL, NULL, &N8, 11, 'B'}; 
    N15 = {NULL, NULL, &N17, 15, 'B'}; 
    N25 = {&N22, &N27, &N17, 25, 'B'}; 
    N6 = {NULL, NULL, &N1, 6, 'R'}; 
    N22 = {NULL, NULL, &N25, 22, 'R'};
    N27 = {NULL, NULL, &N25, 27, 'R'};
    max_node = {NULL, NULL, NULL, 0, 'R'};
    status = RBT_max_get(&N13,&max_node);

    EXPECT_EQ(status, 0);
}

TEST(RBTminget, positive){
    struct RBT_node N13;
    struct RBT_node N8;
    struct RBT_node N17;
    struct RBT_node N1;
    struct RBT_node N11;
    struct RBT_node N15;
    struct RBT_node N25; 
    struct RBT_node N6; 
    struct RBT_node N22;
    struct RBT_node N27;
    struct RBT_node min_node; 
    int  status;
    

   
    N13 = {&N8, &N17, NULL, 13, 'B'}; // root  
    N8 = {&N1, &N11, &N13, 8, 'R'};       
    N17 = {&N15, &N25, &N13, 17, 'R'}; 
    N1 = {NULL, &N6, &N8, 1, 'B'}; 
    N11 = {NULL, NULL, &N8, 11, 'B'}; 
    N15 = {NULL, NULL, &N17, 15, 'B'}; 
    N25 = {&N22, &N27, &N17, 25, 'B'}; 
    N6 = {NULL, NULL, &N1, 6, 'R'}; 
    N22 = {NULL, NULL, &N25, 22, 'R'};
    N27 = {NULL, NULL, &N25, 27, 'R'};
    min_node = {NULL, NULL, NULL, 0, 'R'};
    status = RBT_min_get(&N13,&min_node);

    EXPECT_EQ(status, 0);
}

TEST(RBTsearch, positive){
    struct RBT_node N13;
    struct RBT_node N8;
    struct RBT_node N17;
    struct RBT_node N1;
    struct RBT_node N11;
    struct RBT_node N15;
    struct RBT_node N25; 
    struct RBT_node N6; 
    struct RBT_node N22;
    struct RBT_node N27;
    struct RBT_node found_node; 
    int  status;
    

   
    N13 = {&N8, &N17, NULL, 13, 'B'}; // root  
    N8 = {&N1, &N11, &N13, 8, 'R'};       
    N17 = {&N15, &N25, &N13, 17, 'R'}; 
    N1 = {NULL, &N6, &N8, 1, 'B'}; 
    N11 = {NULL, NULL, &N8, 11, 'B'}; 
    N15 = {NULL, NULL, &N17, 15, 'B'}; 
    N25 = {&N22, &N27, &N17, 25, 'B'}; 
    N6 = {NULL, NULL, &N1, 6, 'R'}; 
    N22 = {NULL, NULL, &N25, 22, 'R'};
    N27 = {NULL, NULL, &N25, 27, 'R'};
    found_node = {NULL, NULL, NULL, 0, 'R'};
    status = RBT_search(&N13,22,&found_node);

    EXPECT_EQ(status, 0);
}

TEST(RBTsearch, negative){
    struct RBT_node N13;
    struct RBT_node N8;
    struct RBT_node N17;
    struct RBT_node N1;
    struct RBT_node N11;
    struct RBT_node N15;
    struct RBT_node N25; 
    struct RBT_node N6; 
    struct RBT_node N22;
    struct RBT_node N27;
    struct RBT_node found_node; 
    int  status1, status2;
    

   
    N13 = {&N8, &N17, NULL, 13, 'B'}; // root  
    N8 = {&N1, &N11, &N13, 8, 'R'};       
    N17 = {&N15, &N25, &N13, 17, 'R'}; 
    N1 = {NULL, &N6, &N8, 1, 'B'}; 
    N11 = {NULL, NULL, &N8, 11, 'B'}; 
    N15 = {NULL, NULL, &N17, 15, 'B'}; 
    N25 = {&N22, &N27, &N17, 25, 'B'}; 
    N6 = {NULL, NULL, &N1, 6, 'R'}; 
    N22 = {NULL, NULL, &N25, 22, 'R'};
    N27 = {NULL, NULL, &N25, 27, 'R'};
    found_node = {NULL, NULL, NULL, 0, 'R'};
    status1 = RBT_search(&N13,3,&found_node);


    EXPECT_EQ(status1, -4);

    status2 = RBT_search(&N13,-27,&found_node);

    EXPECT_EQ(status2, -1);
}

TEST(RBTremove, positive){
    struct RBT_node N13;
    struct RBT_node N8;
    struct RBT_node N17;
    struct RBT_node N1;
    struct RBT_node N11;
    struct RBT_node N15;
    struct RBT_node N25; 
    struct RBT_node N6; 
    struct RBT_node N22;
    struct RBT_node N27;
    struct RBT_node min_node, max_node, found_node; 
    int  status;
    

   
    N13 = {&N8, &N17, NULL, 13, 'B'}; // root  
    N8 = {&N1, &N11, &N13, 8, 'R'};       
    N17 = {&N15, &N25, &N13, 17, 'R'}; 
    N1 = {NULL, &N6, &N8, 1, 'B'}; 
    N11 = {NULL, NULL, &N8, 11, 'B'}; 
    N15 = {NULL, NULL, &N17, 15, 'B'}; 
    N25 = {&N22, &N27, &N17, 25, 'B'}; 
    N6 = {NULL, NULL, &N1, 6, 'R'}; 
    N22 = {NULL, NULL, &N25, 22, 'R'};
    N27 = {NULL, NULL, &N25, 27, 'R'};
    found_node = {NULL, NULL, NULL, 0, 'R'};
    min_node = {NULL, NULL, NULL, 0, 'R'};
    max_node = {NULL, NULL, NULL, 0, 'R'};
    status = RBT_node_remove(&N13,15,&N13);

    EXPECT_EQ(status, 0);

}


TEST(RBTremove, negative){
    struct RBT_node N13;
    struct RBT_node N8;
    struct RBT_node N17;
    struct RBT_node N1;
    struct RBT_node N11;
    struct RBT_node N15;
    struct RBT_node N25; 
    struct RBT_node N6; 
    struct RBT_node N22;
    struct RBT_node N27;
    struct RBT_node min_node, max_node, found_node; 
    int  status1, status2;
   
    N13 = {&N8, &N17, NULL, 13, 'B'}; // root  
    N8 = {&N1, &N11, &N13, 8, 'R'};       
    N17 = {&N15, &N25, &N13, 17, 'R'}; 
    N1 = {NULL, &N6, &N8, 1, 'B'}; 
    N11 = {NULL, NULL, &N8, 11, 'B'}; 
    N15 = {NULL, NULL, &N17, 15, 'B'}; 
    N25 = {&N22, &N27, &N17, 25, 'B'}; 
    N6 = {NULL, NULL, &N1, 6, 'R'}; 
    N22 = {NULL, NULL, &N25, 22, 'R'};
    N27 = {NULL, NULL, &N25, 27, 'R'};
    found_node = {NULL, NULL, NULL, 0, 'R'};
    min_node = {NULL, NULL, NULL, 0, 'R'};
    max_node = {NULL, NULL, NULL, 0, 'R'};
    status1 = RBT_node_remove(&N13,30,&N13);
    EXPECT_EQ(status1, -4);
    status2 = RBT_node_remove(&N13,-3,&N13);
    EXPECT_EQ(status2, -1);

}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
