#include <bits/stdc++.h>
using namespace std;

// Best Sol TC = O(n) , SC = O(1)
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

    return 0;
}