#include <bits/stdc++.h>
using namespace std;

int firstNegNoInQueue(queue<int> q){
    int k = q.size();
    while(!q.empty()){
        if(q.front() < 0)   return q.front();
        else{
            q.pop();
        }
    }
    return 0;
}

// T.C = O(n*k) , SC=O(k)  : Brute Force
vector<int> firstNegNoOfAllWindow01(vector<int>& arr,int k){
    vector<int> ans;
    queue<int> q;
    for(int i=0;i<k-1;i++){
        q.push(arr[i]);
    }

    for(int i=k-1;i<arr.size();i++){
        q.push(arr[i]);
        ans.push_back(firstNegNoInQueue(q));
        q.pop();
    }
    return ans;
}



// T.C = O(n) , S.C = O(k) : Optimal
vector<int> firstNegNoOfAllWindow(vector<int>& arr,int k){
    vector<int> ans;
    queue<int> q;
    for(int i=0;i<k-1;i++){
        if(arr[i] < 0)
            q.push(i);
    }

    for(int i=k-1;i<arr.size();i++){
        if(arr[i] < 0)  q.push(i);
        if(!q.empty() && q.front() <= i-k){
            q.pop();
        }
        
        if(!q.empty())  ans.push_back(arr[q.front()]);
        else    ans.push_back(0);
    }
    return ans;
}

int main(){
    vector<int> arr = {2,-4,3,-2,-1,7,8,3,-4,3,-2,9};
    vector<int> ans = firstNegNoOfAllWindow01(arr,3);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}