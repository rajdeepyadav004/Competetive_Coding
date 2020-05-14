#include "bitonic.hpp"
#include <math.h>
#include "limits.h"
#include <iostream>

int get_next_power_of_two(int n){
    return pow(2,(int)(log(n)/log(2))+1);

}

void make_increasing(vector<int>& inp, int start, int length){

    if(length==1)
        return;

    for(int i=start;i<start+length/2;i++){
        if(inp[i]>inp[i+length/2]){
            swap(inp[i], inp[i+length/2]);
        }
    }
    make_increasing(inp, start, length/2);
    make_increasing(inp, start+length/2, length/2);

}
void make_decreasing(vector<int>& inp, int start, int length){
    if(length==1)
        return;

    for(int i=start;i<start+length/2;i++){
        if(inp[i]<inp[i+length/2]){
            swap(inp[i], inp[i+length/2]);
        }
    }
    make_decreasing(inp, start, length/2);
    make_decreasing(inp, start+length/2, length/2); 
}

vector<int> bitonic_sort(vector<int>& inp){

    int size = inp.size();
    int n = get_next_power_of_two(size);

    for(int i=0;i<n-size;i++)
        inp.push_back(INT_MAX);

    // initial sequences of length 2
    for(int i=0;i<n;i+=4){
        make_increasing(inp, i, 2);
        make_decreasing(inp, i+2, 2);
    }

    int bitonic_length = 8;

    while(bitonic_length <= n){
        for(int i=0;i+bitonic_length<=n;i+=bitonic_length){
            make_increasing(inp,i,bitonic_length/2);
            make_decreasing(inp,i+bitonic_length/2,bitonic_length/2);
        }
        bitonic_length*=2;
    }

    // arrange rest in increasing order

    make_increasing(inp, 0, n);
    inp.erase(inp.begin()+size,inp.end());

    return inp;
}


// have to write more efficient method