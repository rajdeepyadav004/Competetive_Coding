#include "insertion.hpp"
#include "quick.hpp"
#include <iostream>


vector<int> insertion_sort(vector<int> &inp, int start, int end){
    for(int i=start+1; i<end;i++){
        int j = i-1;
        while(inp[j] > inp[j+1] && j!=-1){
            swap(inp[j], inp[j+1]);
            j--;
        }
    }
    return inp;
}

vector<int> insertion_sort(vector<int> & inp){

    for(int i=1; i<inp.size();i++){
        int j = i-1;
        while(inp[j] > inp[j+1] && j!=-1){
            swap(inp[j], inp[j+1]);
            j--;
        }
    }
    return inp;
}

vector<int> recur_insertion_sort(vector<int> & inp, int n){

    if(n==1)
        return inp;
    
    recur_insertion_sort(inp,n-1);

    int j=n-1;
    while(inp[j]>inp[j+1] && j!=-1){
        swap(inp[j],inp[j+1]);
        j--;
    }
    return inp;
}   

vector<int> shell_sort(vector<int> &inp, int start, int end){
   
    int n = end - start + 1;

    for(int gap = n/2; gap>0;gap/=2){

        for(int i=start+gap;i<end;i++){

            int j; 
            int temp = inp[i];

            for(j = i; j >= start+gap && inp[j - gap] > temp;j -= gap){
                inp[j] = inp[j-gap];
            }

            inp[j] = temp;
        }
    }

    return inp;
}

vector<int> shell_sort(vector<int> &inp){
   
    int n = inp.size();

    for(int gap = n/2; gap>0;gap/=2){

        for(int i=gap;i<n;i++){

            int j; 
            int temp = inp[i];

            for(j = i; j >= gap && inp[j - gap] > temp;j -= gap){
                inp[j] = inp[j-gap];
            }

            inp[j] = temp;
        }
    }

    return inp;
}


vector<int> tim_sort(vector<int> &inp){

    const int run = 32; 
    int N = inp.size();
    for(int i=0;i<N;i+=run){
        // iter_random_quick_sort(inp, i, min(N, i+run));
        // shell_sort(inp, i, min(N, i+run));
        insertion_sort(inp, i, min(N, i+run));
    }

    for(int size = run; size < N; size*=2){//code for iterative merge sort

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



int binary_search(vector<int>& inp, int element, int start, int end){
    if(start>=end)
        return (element>inp[start])?start+1:start;
    
    int mid = (start+end)/2;

    if(inp[mid] == element){
        return mid+1;
    }

    else if(inp[mid] > element)
        return binary_search(inp, element, start, mid-1);

    else if(inp[mid] < element)
        return binary_search(inp, element, mid+1, end);
    else {
        cerr<<"unexpected corner case"<<endl;
        exit(1);
    }
}

vector<int> binary_insertion_sort(vector<int> & inp){

    for(int i=1; i<inp.size();i++){
        
        int temp = inp[i];
        int ind = binary_search(inp, temp, 0, i-1);
        int j = i-1;

        while(j>=ind){
            inp[j+1] = inp[j];
            j--;
        }
        inp[j+1] = temp;

    }
    return inp;


}
