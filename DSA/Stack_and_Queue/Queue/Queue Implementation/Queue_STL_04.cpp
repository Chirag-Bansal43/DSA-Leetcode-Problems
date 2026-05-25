#include <bits/stdc++.h>
using namespace std;

int main(){
    queue<int> q;
    // Methods => push,pop,size : returns size of queue,front : returns front element of queue,back : returns back element of queue,empty : returns 1 if queue is empty o/w 0;

    q.push(5);
    q.push(10);
    q.push(15);
    q.push(20);
    q.pop();
    cout<<"front : "<<q.front()<<endl;
    cout<<"back : "<<q.back()<<endl;
    cout<<"size : "<<q.size()<<endl;
    cout<<"empty : "<<q.empty()<<endl;

    return 0;
}