#include <bits/stdc++.h>
using namespace std;

// Deque Implementation Using LL

class Node
{
    public:
    int data;
    Node *next, *prev;

    Node(int x){
        data = x;
        next = prev = nullptr;
    }
};

class Deque
{
    Node *front, *rear;
    int siz;

    public:
    Deque(){
        front = rear = nullptr;
        siz = 0;
    }

    void push_back(int x){
        // empty
        if(front == nullptr){
            front = rear = new Node(x);
        }
        // non empty
        else{
            Node* temp = new Node(x);
            rear->next = temp;
            temp->prev = rear;
            rear = temp;
        }
        siz++;
    }
    void push_front(int x){
        // empty
        if(front == nullptr){
            Node* temp = new Node(x);
            front = rear = temp;
        }
        // non empty
        else{
            Node* temp = new Node(x);
            front->prev = temp;
            temp->next = front;
            front = temp;
        }
        siz++;
    }

    int pop_back(){
        if(front == nullptr){
            cout<<"Deque Underflow"<<endl;
            return -1;
        }
        else{
            Node* temp = rear;
            int val = rear->data;
            rear = rear->prev;
            delete temp;
            // Greater than 1node
            if(rear)   rear->next = nullptr;
            // 1 node
            else    front = nullptr;
            siz--;
            return val;
        }
    }

    int pop_front(){
        if(front == nullptr){
            cout<<"Deque Underflow"<<endl;
            return -1;
        }
        else{
            Node* temp = front;
            int val = front->data;
            front = front->next;
            delete temp;
            // Greater than 1node
            if(front)   front->prev = nullptr;
            // 1 node
            else    rear = nullptr;
            siz--;
            return val;
        }
    }

    int start(){
        if(front == nullptr){
            cout<<"Deque is empty"<<endl;
            return -1;
        }
        else{
            return front->data;
        }
    }

    int end(){
        if(front==nullptr){
            cout<<"Deque is empty"<<endl;    
            return -1;
        }
        else    return rear->data;
    }

    int size(){
        return siz;
    }

};

int main(){
    
    Deque dq;
    dq.push_back(5);
    dq.push_back(10);
    dq.push_front(15);
    dq.push_front(20);
    cout<<"start : "<<dq.start()<<endl;
    cout<<"end : "<<dq.end()<<endl;
    cout<<"Size : "<<dq.size()<<endl;

    dq.pop_front();
    cout<<"start : "<<dq.start()<<endl;
    cout<<"end : "<<dq.end()<<endl;
    cout<<"Size : "<<dq.size()<<endl;

    dq.pop_back();
    cout<<"start : "<<dq.start()<<endl;
    cout<<"end : "<<dq.end()<<endl;
    cout<<"Size : "<<dq.size()<<endl;

    return 0;
}