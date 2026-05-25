#include <bits/stdc++.h>
using namespace std;

int Profit(vector<int>& A,int B){
    int ans = 0;
    priority_queue<int> q;
    for(int i=0;i<A.size();i++){
        q.push(A[i]);
    }
    while(B--){
        int top = q.top();
        ans += top;
        q.pop();
        q.push(top-1);
    }
    return ans;
}

int main(){
    
    return 0;
}