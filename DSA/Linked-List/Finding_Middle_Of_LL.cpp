#include <bits/stdc++.h>
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

// Brute Force Soln
// T.C = O(n) , S.C=O(1)
Node* MiddleNode_001(Node*& head){ // O(n + n/2) = O(3n/2)
    // Empty LL 
    if(head == nullptr) return nullptr;
    Node* curr = head;
    int cnt = 1;
    while(curr->next != nullptr){ // O(n)
        curr = curr->next;
        cnt++;
    }
    int length = cnt;
    int middle = length/2 + 1;

    cnt = 1;
    curr = head;
    while(cnt != middle){ // O(n/2)
        curr = curr->next;
        cnt++;
    }
    return curr;
}

// Optimal Approach -> 2 Pointer Approach
// One Pointer travels double distance than the other... -> Concept of Fast and Slow Pointer
// T.C = O(n/2) , S.C = O(1)
Node* MiddleNode_002(Node*& head){
    Node* fast = head;
    Node* slow = head;

    while(fast!=nullptr && fast->next!=nullptr){
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

int main(){
    Node* head = nullptr;
    Node* tail = nullptr;

    insertAtTail(tail,head,3);
    insertAtTail(tail,head,5);
    insertAtTail(tail,head,8);
    insertAtTail(tail,head,11);
    insertAtTail(tail,head,15);

    print(head);
    int MiddleEle =  MiddleNode_002(head)->data;
    cout<<"Middle Element of Linked List : "<<MiddleEle<<endl;

    return 0;
}