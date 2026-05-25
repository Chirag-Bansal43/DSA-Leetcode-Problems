#include <bits/stdc++.h>
using namespace std;

// TC = O(n*logn) , SC = O(n)
int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q;
        for(int i=0;i<stones.size();i++){
            q.push(stones[i]);
        }

        while(q.size()>1){
            int firstMax = q.top();
            q.pop();
            int secondMax = q.top();
            q.pop();
            q.push(abs(firstMax-secondMax));
        }
        
        if(q.size() == 0)   return 0;
        return q.top();
    }

int main(){
    
    return 0;
}