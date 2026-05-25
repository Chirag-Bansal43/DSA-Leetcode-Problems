#include <bits/stdc++.h>
using namespace std;

// In case of finding smallest element we use MaxHeap

// M-1 : Optimal Using MaxHeap TC = O(n*logk) , SC = O(k)
//Concept : Phele first k elements ko priority queue mein daal liya phir index k se elements ko check karna chalu kiya ki agar ith element queue ke maximum element se chotta hai ya nahi agar chotta hai to queue ka maximum element ans nahi ho sakta so usko queue is pop kar diya and vo choote element ko queue mein daal diya and last mein saare elements dhekne ke baad queue ka maximum element hi kth smallest element hoga array ka

int kthSmallest(vector<int> &arr, int k) {
        priority_queue<int> q;
        for(int i=0;i<k;i++){ // insert first k elements into priority queue :- O(k*logk)
            q.push(arr[i]);
        }
        
        for(int i=k;i<arr.size();i++){  // O((n-k)*logk)
            if(arr[i] < q.top()){
                q.pop();
                q.push(arr[i]);
            }
        }
        
        return q.top();
    }

// M-2 : by sorting :- TC = O(n*logn) , SC = O(1) {changing input array}
int kthSmallest(vector<int> &arr, int k) {
        sort(arr.begin(),arr.end());
        return arr[k-1];
    }

// M-3 : Using MinHeap :- TC = O(n*logn + k*logn) , SC = O(n)
int kthSmallest(vector<int> &arr, int k) {
        priority_queue<int,vector<int>,greater<int>> q;
        for(int i=0;i<arr.size();i++){ // insert first k elements into priority queue
            q.push(arr[i]);
        }
        
        for(int i=0;i<k-1;i++){
            q.pop();
        }
        
        return q.top();
    }

int main(){
    
    return 0;
}