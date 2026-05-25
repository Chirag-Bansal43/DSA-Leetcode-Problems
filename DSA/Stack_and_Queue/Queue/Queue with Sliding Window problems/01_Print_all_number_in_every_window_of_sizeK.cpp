#include <bits/stdc++.h>
using namespace std;

void printingQueue(queue<int>& q){
    int k = q.size();
    while(k--){
        cout<< q.front()<<" ";
        q.push(q.front());
        q.pop();
    }
    cout<<endl;
}

// T.C = O(n*k) , where k = size of window
// ye bina queue ke bhi kar sakte ha but question mein queue use karne ko bola hai
void PrintWindOfSizeK(vector<int>& arr,int k){
    int size = arr.size();
    queue<int> q;
    if(k>size)  return;
    
    // inserting k-1 elements in queue
    int index = 0;
    while(index<k-1){
        q.push(arr[index++]);
    }

    // push the next window element and pop the previous window element from queue and print it again
    while(index<size){
        q.push(arr[index++]);
        printingQueue(q);
        q.pop();
    }
}

int main(){
    vector<int> arr = {3,6,2,7,8,11};
    PrintWindOfSizeK(arr,3);
    return 0;
}