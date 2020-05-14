#include "heap.hpp"
#include "iostream"

void heapify(vector<int> & inp, int size, int index){

    if(size <= 2*index)
        return;
    else if(size == 2*index + 1){
        if(inp[index] < inp[2*index+1]){
            // cout<<"swapped index: "<<inp[index]<<"("<<index<<") and "<<inp[2*index+1]<<"("<<2*index+1<<")"<<endl;
            swap(inp[index], inp[2*index+1]);
        }
        return;
    }    
    else if(size >= 2*index+2){
        int root = inp[index], left = inp[2*index+1], right = inp[2*index+2]; 
        if(root >= left && root >= right);
        else if( left >= root && left >= right){
            // cout<<"swapped index: "<<inp[index]<<"("<<index<<") and "<<inp[2*index+1]<<"("<<2*index+1<<")"<<endl;
            swap(inp[index], inp[2*index +1]);
            heapify(inp, size, 2*index+1);
        }
        else if(right >= root && right >= left){
            // cout<<"swapped index: "<<inp[index]<<"("<<index<<") and "<<inp[2*index+2]<<"("<<2*index+2<<")"<<endl;
            swap(inp[index], inp[2*index+2]);
            heapify(inp,size,2*index+2);
        }
        return;
    }
    else{
        cout<<"Unexpected corner case"<<endl;
    }

}

vector<int> heap_sort(vector<int>& inp){


    int N = inp.size()-1;
    
    for(int i = N/2; i>=0; i--){
        heapify(inp, N, i);
    }

    while(N>1){

        // cout<<"swapped index: "<<inp[0]<<"("<<0<<") and "<<inp[N]<<"("<<N<<")"<<endl;
        swap(inp[0],inp[N]);
        N--;
        heapify(inp, N, 0);
    }
    // cout<<"swapped index: "<<inp[0]<<"("<<0<<") and "<<inp[N]<<"("<<N<<")"<<endl;
    swap(inp[0],inp[N]);
    
    return inp;
}