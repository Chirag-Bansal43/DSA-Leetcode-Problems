#include <bits/stdc++.h>
using namespace std;

// queue reverse using Stack
// S.C = O(n) , T.C = O(2n)
void queueReverse(queue<int>& q){
    stack<int> s;
    while(!q.empty()){
        s.push(q.front());
        q.pop();
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
}

void queuePrint(queue<int>& q){
    int size = q.size();
    cout<<"Printing Queue :-"<<endl;
    while(size--){
        cout<<q.front()<<" ";
        q.push(q.front());
        q.pop();
    }
    cout<<"\n";
}

int main(){
    queue<int> q;
    q.push(5);
    q.push(10);
    q.push(15);
    q.push(20);

    queuePrint(q);
    queueReverse(q);
    cout<<"Queue Print after reversing"<<endl;
    queuePrint(q);

    return 0;
}