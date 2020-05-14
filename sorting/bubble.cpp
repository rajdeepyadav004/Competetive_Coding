

#include "bubble.hpp"
#include <iostream>


vector<int> bubble_sort(vector<int> & inp){

    for(int i=0;i<inp.size()-1;i++){

        for(int j=0; j<inp.size()-1;j++){

            if(inp[j]>inp[j+1])
                swap(inp[j],inp[j+1]);
        }

    }
    return inp;
}

vector<int> bubble_sort_cond(vector<int> & inp){

    bool sorted = false;
    for(int i=0;i<inp.size()-1 && !sorted;i++){
        sorted = true;
        for(int j=0; j<inp.size()-1;j++){

            if(inp[j]>inp[j+1]){
                swap(inp[j],inp[j+1]);
                sorted = false;
            }
        }

    }  
    return inp;
}

vector<int> recur_bubble_sort(vector<int>& inp, int n){

    if(n==1)
        return inp;

    for(int i=0;i<n-1;i++){
        if(inp[i]>inp[i+1]){
            swap(inp[i], inp[i+1]);
        }
    }
    
    return recur_bubble_sort(inp, n-1);
    
} 



vector<int> comb_sort(vector<int>& inp){


    int n = inp.size();
    const double shrink_factor = 1.3; 
    int gap = n;
    bool swapped;
    while(gap>1 || swapped){

        gap = max(1.0,gap/shrink_factor);
        swapped = false;
        for(int i=0;i+gap<n;i++){
            if(inp[i] > inp[i+gap]){
                swap(inp[i],inp[i+gap]);
                swapped = true;
            }
        }
    }


    return inp;
}


vector<int> cocktail_sort(vector<int>& inp){

    int parity=0;
    for(int i=0;i<inp.size()-1;i++){

        if(parity==0){
            for(int j=i/2; j<inp.size()-1 - i/2;j++){
                if(inp[j]>inp[j+1])
                    swap(inp[j],inp[j+1]);
            }
            parity = 1;
        }
        else{
            for(int j=inp.size()-1 - i/2; j>i/2;j--){
                if(inp[j]<inp[j-1])
                    swap(inp[j],inp[j-1]);
            }
            parity = 0;
        }

    }

    return inp;

}
