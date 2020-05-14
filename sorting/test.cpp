#include <iostream>
#include <chrono>
#include <vector>

#include "selection.hpp"
#include "bubble.hpp"
#include "insertion.hpp"
#include "merge.hpp"
#include "quick.hpp"
#include "heap.hpp"
#include "count.hpp"
#include "radix.hpp"
#include "bitonic.hpp"
#include "pancake.hpp"
#include "bogo.hpp"
#include "gnome.hpp"
#include "stooge.hpp"
using namespace std;    
using namespace chrono;

const int N = 1e3;

int main(){

    vector<int> arr;

    srand(time(NULL));
    for(int i=0;i<N;i++){
        arr.push_back(rand());
    }
    // arr = { 3, 5,3,4};
    auto start = high_resolution_clock::now();

    // vector<int> result = bubble_sort(arr); 
    vector<int> result = stooge_sort(arr, 0, arr.size()-1); 
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds> (stop - start);
    cout<<duration.count()<<endl; 

    bool correct = true; 
    for(int i=0;i<result.size()-1;i++){
        if(result[i]>result[i+1]){
            correct = false;
            break;
        }
    }
    cout << (correct?"Correct":"Incorrect")<<endl;
    return 0;

}