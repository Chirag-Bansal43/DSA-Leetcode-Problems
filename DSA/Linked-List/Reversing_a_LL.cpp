#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int d){
        this->data = d;
        this->next = nullptr;
    }

    ~Node(){
        int value = this->data;
        if(this->next != nullptr){
            delete next;    // recursively delete whole linked list
            this->next = nullptr;
        }
        cout<<"memory is freed for node with data "<<value<<endl;
    }
};

void insertAtHead(Node*& head,Node*& tail,int d){
    Node* temp = new Node(d);
    temp->next = head;
    if(head == nullptr) tail = temp;
    head = temp;
}


void insertAtTail(Node*& tail,Node*& head,int d){
    if(tail == nullptr){
        Node* temp = new Node(d);
        tail = temp;
        head = temp;
    }
    else{
        Node* temp = new Node(d);
        tail->next = temp;
        tail = temp;
    }
}

void print(Node*& head){
    Node* temp = head;
    while(temp != nullptr){
        cout<< temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

// Iterative Solution
// T.C = O(n) , S.C = O(1)
Node* ReversingLL_001(Node*& head){
    Node* prev = nullptr;
    Node* curr = head;
    while(curr != nullptr){
        Node* forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    head = prev;
    return head;
}

// Recursive Solution
// Using Forward Recursion -> which is easy to visualise
void ReversingLL_002(Node*& head,Node* prev,Node* curr){
    // Base case
    if(curr == nullptr){
        head = prev;
        return;
    }
    Node* forward = curr->next;
    curr->next = prev;
    ReversingLL_002(head,curr,forward);
}

// Using Backward Recursion -> har ek node ka prev, curr, forward alag hoga and unke liye alag memory assign hogi stack mein and inn pointers ka scope ussi node ke function call ki body mein hi simiit rahega uske bahar inn pointers ka koi vajud nahi ha
void ReversingLL_003(Node*& head,Node* prev,Node* curr){
    // Base case
    if(curr == nullptr){
        head = prev;
        return;
    }
    Node* forward = curr->next;
    ReversingLL_003(head,curr,forward);
    curr->next = prev;
}

// Unique way of applying Recursion
// Returns head of reversed linked list
Node* ReversingLL_004(Node* head){  // head is not pass by reference for each fxn call for each node there is different head; head is address of the node for which fxn gets called
    // base case
    if(head == nullptr || head->next == nullptr){
        return head;
    }

    Node* chotaHead = ReversingLL_004(head->next);
    head->next->next = head;
    head->next = nullptr;

    return chotaHead;
}


int main(){

    Node* head = nullptr;
    Node* tail = nullptr;

    insertAtTail(tail,head,3);
    insertAtTail(tail,head,5);
    insertAtTail(tail,head,8);
    insertAtTail(tail,head,11);

    print(head);

    // Node* prev = nullptr;
    // Node* curr = head;
    // ReversingLL_003(head,prev,curr);
    //print(head);

    head = ReversingLL_004(head); // here head is passed by value in function
    print(head);

    // ReversingLL_001(head);
    // print(head);

    delete head;
    return 0;
}