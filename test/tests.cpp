#include "../include/RBT.h"
#include "gtest/gtest.h"
#include <chrono>
#include <fstream>
#include <time.h> 
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
void print(std::vector <float> const &a, int size) {
   //cout << " VALUES TO ARE: " ; 
   for(int i=0; i < size; i++) {
   std::cout << a.at(i) << ' ';
   }
   cout << "\n";
}
TEST(RBTtime, positive){
    vector<float> list_random_numbers;
    /*Intervals*/
    int lower = 100;
    int upper =   500;
    int status = 0;
    srand((unsigned) time(0));
    /*Aleatory size for vector*/
    int size = (rand() %(upper - lower + 1)) + lower;
    /*File vector with random numbers*/
    for (int i = 1; i <= size; i++)
        list_random_numbers.push_back((rand() %(upper - 1 + 1)) + 1);
    /*Remove repetitive elements*/
    sort(list_random_numbers.begin(), list_random_numbers.end());
    list_random_numbers.erase( unique( list_random_numbers.begin(), list_random_numbers.end() ), list_random_numbers.end() );
    vector<float> n_last_elements(list_random_numbers.end() - 100, list_random_numbers.end());
    int size_list = static_cast<int>(list_random_numbers.size());
    cout << " Size of elements to insert : "<< size_list << "\n";
    /*Create the tree for random list less its last 100 elements*/
    RBT_node* new_root_node = new RBT_node ;
    RBT_node* in_root = new  RBT_node;
    RBT_node* new_root = new RBT_node;
    float init_root_value = list_random_numbers[0];
    in_root->value = init_root_value;
    in_root->color = 'B';
    for (int j = 1; j < size_list-100; j++) {
        RBT_node* new_node = new RBT_node;
        new_node->value = list_random_numbers[j];
        status = RBT_node_add(in_root, new_node, &new_root);
        in_root = new_root;
    }
    /*Insert its last 100 elements*/
    clock_t start, end;
    ofstream file;
    file.open("./samples_time.txt");
    cout << "Output file:  samples_time.txt " << "\n";
    for (int j = size_list-100; j < size_list; j++) {
        RBT_node* new_node = new RBT_node;
        new_node->value = list_random_numbers[j];
        // auto t1 = std::chrono::high_resolution_clock::now();
        start = clock();
        status = RBT_node_add(in_root, new_node, &new_root);
        end = clock();
        double duration_sec = double(end-start)/CLOCKS_PER_SEC;
        // auto t2 = std::chrono::high_resolution_clock::now();
        // auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2-t1 ).count();
        file << j <<"," << duration_sec << "\n";
        in_root = new_root;
    }
    file.close();

}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}


