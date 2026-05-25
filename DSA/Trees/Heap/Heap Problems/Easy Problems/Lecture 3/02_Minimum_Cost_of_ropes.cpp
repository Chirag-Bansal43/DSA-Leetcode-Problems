#include <bits/stdc++.h>
using namespace std;

// TC = O(n* logn) , SC = O(n)
int minCost(vector<int>& arr) {
        // code here
        int ans = 0;
        priority_queue<int,vector<int>,greater<int>> p;
        for(int i=0;i<arr.size();i++){ //O(n*logn)
            p.push(arr[i]);
        }
        while(p.size() > 1){ // O((n-1)*logn) = O(n*logn)
            int firstMin = p.top();
            p.pop();
            int secondMin = p.top();
            p.pop();
            
            ans += firstMin+secondMin;
            p.push(firstMin+secondMin);
        }
        return ans;
        
    }

int main(){
    
    return 0;
}