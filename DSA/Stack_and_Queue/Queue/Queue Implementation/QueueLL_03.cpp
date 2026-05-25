#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = nullptr;
    }

    ~Node(){
        cout<<"Node with data "<<data<<" is destroyed"<<endl;
    }
};

class Queue
{
    private:
    Node* front,*rear;

    public:
    Queue(){
        front = rear = nullptr;
    }

    bool IsEmpty(){
        return front == nullptr;
    }

    void push(int x){
        if(IsEmpty()){
            front = rear = new Node(x);
            cout<<"Pushed "<<x<<" into the Queue"<<endl;
        }
        else{
            rear->next = new Node(x);
            rear = rear->next;
            cout<<"Pushed "<<x<<" into the Queue"<<endl;
        }
    }

    void pop(){
        if(IsEmpty()){
            cout<<"Queue Underflow"<<endl;
        }
        else{
            Node* temp = front;
            if(front == rear)   rear = nullptr;
            front = front->next;
            delete temp;
        }
    }

    int start(){
        if(IsEmpty()){
            cout<<"Queue is Empty"<<endl;
            return -1;
        }
        else{
            return front->data;
        }
    }

    ~Queue(){
        while(front != nullptr){
            pop();
        }
    }

};

int main(){
    
    Queue q;
    q.push(5);
    q.push(10);
    q.push(15);
    q.pop();
    q.push(20);
    q.push(25);
    q.pop();
    q.pop();
    int st = q.start();
    if(!q.IsEmpty())
        cout<<st<<endl;
    return 0;
}