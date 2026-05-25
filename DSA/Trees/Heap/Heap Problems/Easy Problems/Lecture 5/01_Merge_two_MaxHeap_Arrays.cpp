#include <bits/stdc++.h>
using namespace std;

void Heapify(vector<int>& arr,int index,int size){
        int current = index;
        while(true){
            int largest = current;
            int left = 2*current+1;
            int right = 2*current+2;
            
            if(left<size && arr[left] > arr[largest]){
                largest = left;
            }
            if(right<size && arr[right] > arr[largest]){
                largest = right;
            }
            
            if(largest != current){
                swap(arr[largest],arr[current]);
                current = largest;
            }
            else
                break;
        }
    }
    
    void BuildMaxHeap(vector<int>& arr,int N){
        for(int i=N/2-1;i>=0;i--){
            Heapify(arr,i,N);
        }
    }

    // M-1 : Optimal :- TC = O(m+n) , SC = O(1)
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // Method-1
        // Inn dono arrays ko ek array mein daalo aur uss array ko step down method se max heap bana denge
        
        vector<int> ans;
        for(int i=0;i<n;i++){ //O(n)
            ans.push_back(a[i]);
        }
        for(int i=0;i<m;i++){ // O(m)
            ans.push_back(b[i]);
        }
        
        // Making ans array into MaxHeap Using step-down (or Heapify)
        BuildMaxHeap(ans,n+m); //O(m+n)
        
        return ans;
        
    }

    // Method-2 : Better Solution Using Sorting
    // TC = O(O((m+n)*log(m+n))) , SC = O(1)
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // Method-2 : Better Solution Using Sorting
        vector<int> ans;
        
        for(int i=0;i<n;i++){ //O(n)
            ans.push_back(a[i]);
        }
        for(int i=0;i<m;i++){ //O(m)
            ans.push_back(b[i]);
        }
        
        // sorting ans array in descending order (descending order mein array ke elements se heap tree banaye to vo MaxHeap hi banta hai)
        sort(ans.begin(),ans.end(),greater<int>()); //O((m+n)*log(m+n))
        
        return ans;
    }

    // Method-3 : Brute Force Solution Using priority_queue
    // TC = O((m+n)*log(m+n)) , SC = O(m+n) {Inn Short Bahut hi ganda solution}
vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // Method-2 : Brute Force Solution Using priority_queue
        // Put All Elements of both array into priority_queue( MaxHeap wali) and ek ek karke usme se elements nikalo to vo elements descending order mein hi nikalenge unse tu MaxHeap bana le
        vector<int> ans;
        priority_queue<int> q;
        //O((m+n)*log(m+n)) => niche ke dono for loop milake te time complexity aayegi
        for(int i=0;i<n;i++){ 
            q.push(a[i]);
        }
        for(int i=0;i<m;i++){ 
            q.push(b[i]);
        }
        
        while(!q.empty()){ //O((m+n)*log(m+n))
            ans.push_back(q.top());
            q.pop();
        }
        
        return ans;
    }

int main(){
    
    return 0;
}