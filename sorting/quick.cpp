#include "quick.hpp"
#include <iostream>
#include <random>
#include <stack>


int partition(vector<int>& inp, int pivot_ind, int start, int end){

    if(inp[pivot_ind]!=inp[end]) // for stable sorting  
        swap(inp[pivot_ind], inp[end]);
    int pivot = inp[end];
    int i = start;

    for(int j=start;j<end;j++){

        if(inp[j] <= pivot){
            if(inp[i]!= inp[j] || i<j) // for stable sorting
                swap(inp[i], inp[j]);
            i++;
        }
    }
    swap(inp[i], inp[end]);
    return i;
}


vector<int> recur_end_quick_sort(vector<int>& inp, int start, int end){

    if(start < end){

        int pivot_index = end;
        int partition_index = partition(inp, pivot_index, start, end);

        recur_end_quick_sort(inp, start, partition_index-1);
        recur_end_quick_sort(inp, partition_index+1, end);
    }

    return inp;
}

vector<int> recur_random_quick_sort(vector<int>& inp, int start, int end){

    if(start < end){

        int pivot_index = start + rand()%(end+1-start);
        int partition_index = partition(inp, pivot_index, start, end);

        recur_end_quick_sort(inp, start, partition_index-1);
        recur_end_quick_sort(inp, partition_index+1, end);
    }

    return inp;
}

vector<int> iter_random_quick_sort(vector<int>& inp, int start, int end){

    stack<int> S;
    S.push(start);
    S.push(end);
    while(!S.empty()){

        int h = S.top();
        S.pop();
        int l = S.top();
        S.pop();

        // srand(time(NULL));
        int pivot_ind = l + rand()%(h+1-l); 
        int partition_index = partition(inp, pivot_ind,l, h);
        if (l < partition_index - 1){
            S.push(l);
            S.push(partition_index - 1);
        }
        if (partition_index+1 < h){
            S.push(partition_index+1);
            S.push(h);
        }

    }
    return inp;
}