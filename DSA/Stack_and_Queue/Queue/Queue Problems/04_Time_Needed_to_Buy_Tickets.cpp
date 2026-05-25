// 2073. Time Needed to Buy Tickets 
//(Good problem to understand how Queues are used in real life)

#include <bits/stdc++.h>
using namespace std;

// Better sol using queue SC = O(n) TC = O(n^2)
int timeRequiredToBuy_01(vector<int>& tickets, int k) {
    queue<int> q;
    int time = 0;
    int size = tickets.size();
    int index = 0;
    while(size--){
        q.push(index++);
    }

    while(tickets[k] != 0){
        tickets[q.front()]--;
        time++;
        if(tickets[q.front()] == 0){
            q.pop();
        }
        else{
            q.push(q.front());
            q.pop();
        }
    }

    return time;
}

// Optimal TC = O(n) , SC = O(1)
int timeRequiredToBuy(vector<int>& tickets, int k) {
        int time = 0;
        for(int i=0;i<=k;i++){
            time+= min(tickets[i],tickets[k]);
        }
        for(int i=k+1;i<tickets.size();i++){
            time+= min(tickets[k]-1,tickets[i]);
        }

        return time;
    }

int main(){
    
    return 0;
}