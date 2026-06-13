#include <bits/stdc++.h>
using namespace std;

// @ isme priority queue ki jarurat padegi
// solved on gfg
double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        double total_value = 0; // total value in the bag
        int remaining_wt = capacity; // remaining weight in the bag
        
        priority_queue<pair<double,int>> p; //valu/wt and index
        
        int n = wt.size();
        for(int i=0;i<n;i++){
            p.push(make_pair((double) val[i]/ (double) wt[i] , i));
        }
        
        while(!p.empty() && remaining_wt != 0){
            // index of max val/wt pair => p.top.second => isko val[] and wt[] se sath use kar sakte hai to get value and weight of maximum val/wt pair
            if(wt[p.top().second] <= remaining_wt){
                remaining_wt -= wt[p.top().second];
                total_value += val[p.top().second];
                p.pop();
            }
            else{
                // item's wt becomes greater than bag's remaining weight so yaha item ka fraction bag mein daalna padega
                double fraction = (double) remaining_wt / (double) wt[p.top().second];
                remaining_wt = 0;
                total_value += fraction * val[p.top().second];
            }
        }
        
        return total_value;
        
    }


int main(){
    
    return 0;
}