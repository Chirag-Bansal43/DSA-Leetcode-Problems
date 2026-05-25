#include <bits/stdc++.h>
using namespace std;

// TC = O(k* logn) since k>>n , SC = O(n)
long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> q;
        for(int i=0;i<gifts.size();i++){ //O(n*logn)
            q.push(gifts[i]);
        }

        while(k--){     // O(k*log(n))
            int Maxgift = q.top();
            q.pop();
            q.push(floor(sqrt(Maxgift)));
        }

        long long sum = 0;
        while(!q.empty()){ // O(n*logn)
            sum += q.top();
            q.pop();
        }
        return sum;
    }

int main(){
    cout<<floor(sqrt(10));
    return 0;
}