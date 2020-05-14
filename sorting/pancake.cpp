#include "pancake.hpp"
#include "limits.h"


void flip(vector<int>& inp, int index){
    int i = 0, j = index;
    while(i<j){
        swap(inp[i], inp[j]);
        i++;
        j--;
    } 

}

int arg_max(vector<int>& inp, int end){
    int res=0;
    int max = INT_MIN;
    for(int i=0;i<end;i++){
        if(inp[i]>max){
            res = i;
            max = inp[i];
        }
    }    
    return res;
}

vector<int> pancake_sort(vector<int>& inp){
    int n = inp.size();
    for(int curr_size = n; curr_size>1;curr_size--){
        int mi = arg_max(inp, curr_size);
        flip(inp, mi);
        flip(inp, curr_size);
    }
    return inp;
}