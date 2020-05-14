#include "gnome.hpp"


vector<int> gnome_sort(vector<int>& inp){


    int i=0;
    int n = inp.size();
    while(i!=n-1){
        
        if(inp[i+1]<inp[i]){
            swap(inp[i+1], inp[i]);
            i--;
        }
        else
            i++;
        if(i<0)
            i=0;
    }
    return inp;
}
