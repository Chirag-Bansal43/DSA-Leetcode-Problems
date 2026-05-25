#include <bits/stdc++.h>
using namespace std;

// Implementing Deque using Array

class Deque
{
    int* arr;
    int size,front,rear;

    public:
    Deque(int size){
        arr = new int[size];
        this->size = size;
        front = rear = -1;
    }

    void push_back(int val){
        // empty
        if(front == -1){
            front = rear = 0;
            arr[rear] = val;
        }
        
        
        else{
            // full
            if((rear+1)%size == front){
                cout<<"Deque Overflow"<<endl;
                return;
            }
            else{
                rear = (rear+1)%size;
                arr[rear] = val;
            }
        }
    }
    void push_front(int val){
        // empty
        if(front == -1){
            front = rear = 0;
            arr[front] = val;
        }
        
        else{
            // full
            if((front-1+size)%size == rear){
                cout<<"Deque Overflow"<<endl;
                return;
            }
            else{
                front = (front-1+size)%size;
                arr[front] = val;
            }
        }
    }
    int pop_back(){
        // empty
        if(front == -1){
            cout<<"Deque Underflow"<<endl;
            return -1;
        }
        else{
            // 1Ele
            if(front == rear){
                int val = arr[rear];
                front = rear = -1;
                return val;
            }
            // Greater than 1 Element 
            else{
                int val = arr[rear];
                rear = (rear-1+size)%size;
                return val;
            }
        }
    }

    int pop_front(){
        // empty
        if(front == -1){
            cout<<"Deque Underflow"<<endl;
            return -1;
        }
        else{
            // 1Ele
            if(front == rear){
                int val = arr[rear];
                front = rear = -1;
                return val;
            }
            // Greater than 1 Element 
            else{
                int val = arr[front];
                front = (front+1)%size;
                return val;
            }
        }
    }

    int start(){
        // empty
        if(front == -1){
            cout<<"Deque is empty"<<endl;
            return -1;
        }
        else    return arr[front];
    }

    int end(){
        // empty
        if(front == -1){
            cout<<"Deque is empty"<<endl;
            return -1;
        }
        else    return arr[rear];
    }

};


int main(){

    Deque dq(6);
    dq.push_front(10);
    dq.push_back(5);
    cout<<"start : "<<dq.start()<<endl;
    cout<<"end : "<<dq.end()<<endl;

    dq.pop_back();
    cout<<"start : "<<dq.start()<<endl;
    cout<<"end : "<<dq.end()<<endl;

    dq.pop_back();
    cout<<"start : "<<dq.start()<<endl;
    cout<<"end : "<<dq.end()<<endl;

    return 0;
}