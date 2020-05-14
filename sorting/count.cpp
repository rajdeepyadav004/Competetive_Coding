
#include "count.hpp"

vector<int> count_sort(vector<int> inp){

    vector<int> dict(1e5);

    for(auto it = inp.begin();it!=inp.end();it++){
        dict[*it]++;
    }

    vector<int> res;
    for(int i=0;i<1e5;i++){
        for(int j=0;j<dict[i];j++){
            res.push_back(i);
        }
    }

    return res;
}
