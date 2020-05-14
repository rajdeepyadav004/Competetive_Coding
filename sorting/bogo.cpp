#include "bogo.hpp"
#include <random>

bool isSorted(vector<int>& inp){
    for(int i=0;i<inp.size()-1;i++){
        if(inp[i]>inp[i+1])
            return false;
    }
    return true;
}

vector<int> bogo_sort(vector<int>& inp){
    int n = inp.size();

    while(!isSorted(inp)){
        for(int i=0;i<n;i++){
            srand(time(NULL));
            int j = random()%n;
            srand(100);
            int k = random()%n;
            swap(inp[k],inp[j]);
        }
    }

    return inp;    

}
