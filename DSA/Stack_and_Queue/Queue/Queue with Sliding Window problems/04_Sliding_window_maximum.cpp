#include <bits/stdc++.h>
using namespace std;

// Problem in which deque DS is used

// Brute Force : TC = O(n*k) , SC = O(1)
vector<int> SlidingWindowMax01(vector<int>& arr,int k){
    vector<int> ans;
    int n = arr.size();
    for(int i=0;i<=n-k;i++){
        int maxEle = INT_MIN;
        for(int j=i;j<=i+k-1;j++){
            maxEle = max(maxEle,arr[j]);
        }
        ans.push_back(maxEle);
    }
    return ans;
}


// Optimal solution using deque :- TC = O(n) approx and SC = O(k)
vector<int> SlidingWindowMax(vector<int>& arr,int k){
    deque<int> dq;
    vector<int> ans;
    // initialization of queue
    for(int i=0;i<k-1;i++){
        if(dq.empty()){
            dq.push_back(i);
        }
        else{
            while(!dq.empty() && arr[dq.back()]<= arr[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
    }

    // window slides one step in one iteration
    for(int i=k-1;i<arr.size();i++){
        while(!dq.empty() && arr[dq.back()]<= arr[i]){
            dq.pop_back();
        }
        dq.push_back(i);

        // if front element of deque goes out of window
        if(dq.front()<=i-k){
            dq.pop_front();
        }

        ans.push_back(arr[dq.front()]);
    }
    return ans;
}

int main(){
    
    vector<int> arr = {5,3,7,9,1,8,3,7,2,11,9};
    vector<int> ans = SlidingWindowMax(arr,4);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}