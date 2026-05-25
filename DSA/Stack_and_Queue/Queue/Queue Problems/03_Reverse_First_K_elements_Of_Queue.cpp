#include <bits/stdc++.h>
using namespace std;

queue<int> reverseFirstK(queue<int> q, int k) {
        int size = q.size();
        int remEle = size-k;
        if(k>size)  return q;
        stack<int> s;
        while(k--){
            s.push(q.front());
            q.pop();
        }
        while(!s.empty()){
            q.push(s.top());
            s.pop();
        }
        while(remEle--){
            q.push(q.front());
            q.pop();
        }
        return q;
    }

int main(){
    
    return 0;
}