#include <bits/stdc++.h>
using namespace std;

// Optimal Solution : TC = O(n*logk) worst case time complexity , SC = O(k)
 vector<int> kthLargest(vector<int>& arr, int k) {
        vector<int> ans;
        // for finding largest element we make MinHeap
        priority_queue<int,vector<int>,greater<int>> q;
        for(int i=0;i<k-1;i++){
            q.push(arr[i]);
            ans.push_back(-1);
        }
        
        q.push(arr[k-1]);
        ans.push_back(q.top());
        
        for(int i=k;i<arr.size();i++){
            if(arr[i] > q.top()){
                q.pop();
                q.push(arr[i]);
                ans.push_back(q.top());
            }
            else
                ans.push_back(q.top());
        }
        
        return ans;
        
    }

int main(){
    
    return 0;
}