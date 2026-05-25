#include <bits/stdc++.h>
using namespace std;

/* Implement the circular array means ending elements will go to the starting of array if space in the array is available
This is called circular queue.

Here rear and front is increased like this => rear = (rear+1)%size; and front = (front+1)%size;
and if (rear+1)%size == front , then this means queue is full
*/

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
        return (rear+1)%size == front;
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
            rear = (rear+1)%size;
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
            front = (front+1)%size;
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

    cout<<q.start()<<endl;
    q.push(400);
    
    return 0;
}