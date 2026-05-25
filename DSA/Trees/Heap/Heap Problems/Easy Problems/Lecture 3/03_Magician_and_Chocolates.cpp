#include <bits/stdc++.h>
using namespace std;

// TC = O(A*logn + n* logn) since A>>n , Therefore TC = O(A*logn) , SC = O(n)
int MaxChocolate(int A,vector<int>& B){
    long long ans = 0;
    priority_queue<int> q;
    for(int i=0;i<B.size();i++){ //O(n* logn)
        q.push(B[i]);
    }
    while(A--){ // O(A* logn)
        int top = q.top();
        ans += top;
        q.pop();
        q.push(top/2);
    }
    return ans % 1000000007;
}

int main(){
    
    return 0;
}