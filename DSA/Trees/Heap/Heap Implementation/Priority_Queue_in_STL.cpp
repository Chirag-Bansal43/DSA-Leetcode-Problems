#include <bits/stdc++.h>
using namespace std;

// PRIORITY QUEUE IS NOTHING BUT MAXHEAP. So, Top of priority queue have element of highest priority. In integers, element having largest value have highest priority.


int main(){

    /*
    priority_queue<int> p; // MaxHeap

    // inserting element in priority queue TC = O(logn)
    p.push(10);
    p.push(35);
    p.push(7);
    p.push(75);

    cout<<p.top()<<endl;

    // Deleting element from priority queue TC = O(logn)
    p.pop();
    cout<<p.top()<<endl;

    // printing priority queue
    // TC = O(n*logn)
    while(!p.empty()){
        cout<<p.top()<<" ";
        p.pop();
    }
        */

    // PRIORITY QUEUE SYNTAX FOR MINHEAP
    priority_queue<int , vector<int> , greater<int>> p;
    p.push(10);
    p.push(35);
    p.push(7);
    p.push(75);
    
    cout<<"Size : "<<p.size()<<endl;
    
    while(!p.empty()){
        cout<<p.top()<<" ";
        p.pop();
    }



    return 0;
}