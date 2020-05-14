#include "stooge.hpp"


vector<int> stooge_sort(vector<int>& inp,int start, int end){

    int n=inp.size();
    if(start>=end)
        return inp;
    
    if(inp[start]>inp[end])
        swap(inp[start], inp[end]);
    
    if(end - start + 1 > 2){
        int t = (end - start + 1)/3;
        stooge_sort(inp, start, end - t);
        stooge_sort(inp, start+t, end);
        stooge_sort(inp, start, end - t);
    }
    return inp;
}