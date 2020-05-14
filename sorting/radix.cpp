
#include <math.h>
#include "radix.hpp"
#include <iostream>


void count_sort(vector<int>& inp, int digit){

    vector<vector<int>> dict = vector<vector<int>>(10, vector<int>()); 
    
    for(int i=0;i<inp.size();i++){
        int element = inp[i];
        int place = (element%(int )(pow(10, digit+1)))/pow(10,digit);
        dict[place].push_back(element);
        // cout<<element<<" "<<place<<" "<<digit<<endl;
    }
    inp.clear();
    for(int i=0;i<10;i++){
        for(int j=0;j<dict[i].size();j++){
            inp.push_back(dict[i][j]);
        }
    }
}

vector<int> radix_sort(vector<int>& inp){

    vector<vector<int>> dict;
    int max_num_digits = 10; 

    for(int i=0;i<max_num_digits;i++){
        count_sort(inp, i);
    }

    return inp;

}