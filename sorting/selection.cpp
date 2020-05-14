

#include "selection.hpp"
#include "limits.h"

int min_array(vector<int>::iterator start, vector<int>::iterator end){

    int res = INT_MAX;
    for(auto it=start; it != end;++it){
        res = min(res, *it); 
    }
    return res; 
}


vector<int> selection_sort(vector<int>& inp){

    vector<int> res;

    for(int i=0;i<inp.size();i++){

        int min_arr = min_array(inp.begin()+i, inp.end());
        res.push_back(min_arr);    
    }

    return res;
}
