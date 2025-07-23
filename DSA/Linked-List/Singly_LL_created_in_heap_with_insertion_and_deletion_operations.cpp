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

void insertAtPosition(Node*& head,Node*& tail,int position,int d){
    Node* temp = head;
    int cnt = 1;
    while(cnt < position-1){
        temp = temp->next;
        cnt++;
    }
    
    // Inserting at first
    if(position == 1)   insertAtHead(head,tail,d);
    
    // Inserting at end
    else if(temp->next == nullptr)  insertAtTail(tail,head,d);

    // Inserting in middle
    else{
        Node* newNode = new Node(d);
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// Deletion in a Singly Linked List

void deletionByPosition(Node*& head,Node*& tail,int position){
    // Linked List is empty
    if(head == nullptr){ 
        cout<<"Linked List is empty no deletion can take place"<<endl;
        return;
    }

    Node* prev = nullptr;
    Node* curr = head;
    int cnt = 1;
    while(cnt<position){
        prev = curr;
        curr=curr->next;
        cnt++;
    }

    // deleting head node
    if(position == 1){
        head = curr->next;
        curr->next = nullptr;
        delete curr;
    }
    else{
        prev->next = curr->next;
        curr->next = nullptr;
        delete curr;
        // If deleted node is last node then after deletion of last node tail become dangling pointer
        if(prev->next == nullptr){ // means prev node is last node of linked list that means we just deleted last node of linked list so we need to update the tail pointer 
            tail = prev;
        }
    }
}

void deletionByValue(Node*& head,Node*& tail,int value){
    // Linked List is empty
    if(head == nullptr){ 
        cout<<"Linked List is empty no deletion can take place"<<endl;
        return;
    }

    Node* prev = nullptr;
    for(Node* curr = head; curr != nullptr ; curr=curr->next){ // O(n)
        if(curr->data == value){
            // curr is first node
            if(prev == nullptr){
                head = head->next;
                curr->next = nullptr;
                delete curr;
            }
            else{
                prev->next = curr->next;
                curr->next = nullptr;
                delete curr;
                // If deleted node is last node then after deletion of last node tail become dangling pointer
                if(prev->next == nullptr){ // means prev node is last node of linked list that means we just deleted last node of linked list so we need to update the tail pointer 
                    tail = prev;
                }
            }
            return;
        }
        prev = curr;
    }

    cout<<"The value "<<value<<" is not present in linked list"<<endl;
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

int main(){

    Node* head = nullptr;
    Node* tail = nullptr;

    print(head);

    insertAtTail(tail,head,5);
    print(head);

    // insertAtHead(head,tail,5);
    // print(head);

    insertAtHead(head,tail,3);
    print(head);
    
    insertAtTail(tail,head,7);
    print(head);

    insertAtTail(tail,head,10);
    print(head);

    insertAtPosition(head,tail,5,13);
    print(head);

    cout<<"head "<<head->data<<"  "<<"tail "<<tail->data<<endl<<endl;

    deletionByPosition(head,tail,1);
    print(head);
    cout<<"head "<<head->data<<"  "<<"tail "<<tail->data<<endl<<endl;

    deletionByValue(head,tail,3);
    print(head);
    cout<<"head "<<head->data<<"  "<<"tail "<<tail->data<<endl<<endl;

    delete head;

    return 0;
}