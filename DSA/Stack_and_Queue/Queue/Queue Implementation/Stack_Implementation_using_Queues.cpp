#include <bits/stdc++.h>
using namespace std;

/* Jis queue mein elements ha waha push karunga 
and pop ke liye sare elements ko empty queue mein push kar dunga except the last element and usko phir pop kar denge
*/

class Stack
{
    queue<int> q1;
    queue<int> q2;

    public:

    bool IsEmpty(){
        return q1.empty() && q2.empty();
    }

    void push(int x){
        if(!q1.empty()){
            q1.push(x);
        }
        else{
            q2.push(x);
        }
    }

    int pop(){
        if(IsEmpty())   return -1;
        else if(!q1.empty()){
            while(q1.size() > 1){
                q2.push(q1.front());
                q1.pop();
            }
            int top = q1.front();
            q1.pop();
            return top;
        }
        else{
            while(q2.size() > 1){
                q1.push(q2.front());
                q2.pop();
            }
            int top = q2.front();
            q2.pop();
            return top;
        }
    }

    int peek(){
        if(IsEmpty())   return -1;
        else if(!q1.empty()){
            return q1.back();
        }
        return q2.back();
    }
};

int main(){
    
    return 0;
}