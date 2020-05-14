
#include "merge.hpp"
#include <iostream>

using namespace std;

vector<int> merge(vector<int> first, vector<int> second){

    vector<int> res;
    int i=0;int j=0;

    while(i+j<first.size()+second.size()){

        if(i==first.size()){
            res.push_back(second[j]);
            j++;
        }

        else if(j==second.size()){
            res.push_back(first[i]);
            i++;
        }

        else if(first[i]<=second[j]){
            res.push_back(first[i]);
            i++;
        }
        else if(first[i]>second[j]){
            res.push_back(second[j]);
            j++;
        }
    }

    return res;

} 

vector<int> merge_sort(vector<int>& inp){

    int N = inp.size();
    if(N==1)
        return inp;

    vector<int> first;
    for(int i=0;i<N/2;i++){
        first.push_back(inp[i]);
    }

    vector<int> second;
    for(int i=N/2;i<N;i++){
        second.push_back(inp[i]);
    }

    first = merge_sort(first);
    second = merge_sort(second);

    vector<int> res = merge(first, second);

    return res;

}

vector<int> iter_merge_sort(vector<int>& inp){

    int N = inp.size();
    
    for(int size = 1; size < N; size*=2){

        for(int l=0; l < N; l+=2*size){

            int m = min(l+size, N), r = min(l + 2*size, N);

            vector<int> tmp;
            
            int i=l, j=m;
            while(i-l+j-m<2*size){

                if(i == m){
                    tmp.push_back(inp[j]);
                    j++;
                }
                else if(j==r){
                    tmp.push_back(inp[i]);
                    i++;
                }
                else if(inp[i]<=inp[j]){
                    tmp.push_back(inp[i]);
                    i++;
                }
                else if(inp[i]>inp[j]){
                    tmp.push_back(inp[j]);
                    j++;
                }
                else{
                    cout<<"Unexpected boundary case"<<endl;
                }
            }

            for(int k=0; k<2*size;k++){
                inp[k+l] = tmp[k];
            }
            
        }

    }

    return inp;
}
