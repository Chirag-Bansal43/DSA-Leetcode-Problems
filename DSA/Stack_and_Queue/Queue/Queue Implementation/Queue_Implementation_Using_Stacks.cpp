#include <bits/stdc++.h>
using namespace std;

class Queue
{
    stack<int> s1; // for push operation
    stack<int> s2; // for pop operation
    
    public:
    bool IsEmpty(){
        if(s1.empty() && s2.empty()){
            return true;
        }
        return false;
    }

    void push(int x){
        s1.push(x);
    }

    int pop(){
        if(!s2.empty()){
            int top = s2.top();
            s2.pop();
            return top;
        }
        else if(!s1.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            int top = s2.top();
            s2.pop();
            return top;
        }
        else{
            cout<<"Queue Underflow"<<endl;
            return -1;
        }
    }

    int front(){
        if(!s2.empty()){
            return s2.top();
        }
        else if(!s1.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            return s2.top();
        }
        else{
            cout<<"Stack is empty"<<endl;
            return -1;
        }
    }

};

int main(){
    Queue q;
    q.push(2);
    q.push(4);
    q.push(7);
    cout<<q.pop()<<endl;
    q.push(10);
    cout<<q.pop()<<endl;
    cout<<"Front : "<<q.front()<<endl;
    return 0;
}