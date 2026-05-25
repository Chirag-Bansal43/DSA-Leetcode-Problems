#include <bits/stdc++.h>
using namespace std;

class Queue
{
private:
    int* arr;
    int front,rear,size;
public:
    Queue(int n){
        arr = new int[n];
        front = rear = -1;
        size = n;
    };

    bool IsEmpty(){
        return front == -1;
    }

    bool IsFull(){
        return rear == size-1;
    }

    void push(int x){
        if(IsEmpty()){
            front = rear = 0;
            arr[rear] = x;
            cout<<"Pushed "<<x<<" into the Queue"<<endl;
        }
        else if(IsFull()){
            cout<<"Queue Overflow"<<endl;
            cout<<"Pushed of "<<x<<" failed into the queue"<<endl;
        }
        else{
            rear += 1;
            arr[rear] = x;
            cout<<"Pushed "<<x<<" into the Queue"<<endl;
        }
    }

    void pop(){
        if(IsEmpty()){
            cout<<"Queue Underflow"<<endl;
        }
        else if(front == rear){
            cout<<"Poped "<<arr[front]<<" from the Queue"<<endl;
            front = rear = -1;
        }
        else{
            cout<<"Poped "<<arr[front]<<" from the Queue"<<endl;
            front += 1;
        }
    }

    int start(){
        if(IsEmpty()){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        else
        return arr[front];
    }

    ~Queue(){
        delete [] arr;
    };
};



int main(){
    
    Queue q(5);
    q.push(5);
    q.push(10);
    q.push(15);
    q.pop();
    q.push(100);
    q.push(151);
    q.push(200);

    return 0;
}