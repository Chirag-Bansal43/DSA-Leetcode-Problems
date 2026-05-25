#include <bits/stdc++.h>
using namespace std;

// How many Minimum number of k consecutive bit flips required to make an array of zeros and ones to array containing only ones?

// Optimal : T.C = O(n) , SC ~ O(k)
int MinNoOfKBitFlips(vector<int>& arr,int k){
    queue<int> q;
    int n = arr.size();
    int Flips = 0;
    for(int i=0;i<n;i++){
        if(!q.empty() && i>q.front()){
            q.pop();
        }
        //condition for flipping of bit
        if(q.size()%2 == arr[i]){
            if(i+k-1 >= n)  return -1;
            q.push(i+k-1);
            Flips++;
        }
    }
    return Flips;
}


// Brute force : TC = O(n*k) , SC = O(1)
int MinNoOfKBitFlips01(vector<int>& arr,int k){
    int Flips = 0;
    int n = arr.size();
    for(int i=0;i<n;i++){
        if(arr[i] == 0){
            if(i+k-1 >= n){
                return -1;
            }
            for(int j = i;j<=i+k-1;j++){
                arr[j] = ! arr[j];
            }
            Flips++;
        }
    }
    return Flips;
}

int main(){
    vector<int> arr = {0,0,1,0,0,1,1,0,1,0};
    cout<<MinNoOfKBitFlips(arr,4)<<endl;
    return 0;
}