#include <vector>
using namespace std;


vector<int> bubble_sort(vector<int> & inp);
vector<int> bubble_sort_cond(vector<int> & inp);
vector<int> recur_bubble_sort(vector<int> & inp, int n);
//performance advantage due to checking one element less each time
vector<int> comb_sort(vector<int>& inp);
vector<int> cocktail_sort(vector<int>& inp);