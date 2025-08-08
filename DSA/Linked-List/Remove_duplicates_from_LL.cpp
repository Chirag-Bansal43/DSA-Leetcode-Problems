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

// Insertion in a Singly Linked List 

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

// Traversing a Linked list
void print(Node*& head){
    Node* temp = head;
    while(temp != nullptr){
        cout<< temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

// Remove Duplicates from sorted Linked List
// T.C = O(n) , S.C = O(1)
Node* deleteDuplicates_Sorted(Node* head) {
    if(head == nullptr) return head;
    Node* temp = head;
    while(temp->next != nullptr){
        if(temp->next->data == temp->data){
            Node* forward = temp->next;
            temp->next = temp->next->next;
            forward->next = nullptr;
            delete forward;
        }
        else{
            temp=temp->next;
        }
    }
    return head;
}

//Remove Duplicates from Unsorted Linked List

// Brute Force => T.C = O(n^2) , S.C = O(1)
Node* deleteDuplicates(Node* head) {
    Node* present = head;
    while(present != nullptr){
        Node* prev = present;
        Node* curr = present->next;
        while(curr != nullptr){
            if(curr->data == present->data){
                prev->next = curr->next;
                curr->next = nullptr;
                delete curr;
                curr = prev->next;
            }
            else{
                prev = curr;
                curr = curr->next;
            }
        }
        present = present->next;
    }
    return head;
}



int main(){
    Node* head = nullptr;
    Node* tail = nullptr;

    print(head);

    insertAtTail(tail,head,3);
    print(head);
    insertAtTail(tail,head,3);
    print(head);
    insertAtTail(tail,head,3);
    print(head);

    insertAtTail(tail,head,5);
    print(head);
    insertAtTail(tail,head,5);
    print(head);
    insertAtTail(tail,head,5);
    print(head);
    
    insertAtTail(tail,head,7);
    print(head);
    insertAtTail(tail,head,7);
    print(head);

    insertAtTail(tail,head,10);
    print(head);
    cout<<"head "<<head->data<<"  "<<"tail "<<tail->data<<endl<<endl;

    deleteDuplicates(head);
    print(head);


    return 0;
}