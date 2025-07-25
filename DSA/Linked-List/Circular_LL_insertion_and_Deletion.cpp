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
        cout<<"memory is freed for node with value "<<value<<endl;
    }
};

// Insertion In a Circular Linked List

void insertAfterTail(Node*& tail,int d){
    // LL empty
    if(tail == nullptr){
        Node* newNode = new Node(d);
        newNode->next = newNode;
        tail = newNode;
        return;
    }

    // LL is not empty
    Node* newNode = new Node(d);
    newNode->next = tail->next;
    tail->next = newNode;
    tail = newNode;
}

void insertAfterValue(Node*& tail,int value,int d){
    if(tail == nullptr){
        cout<<"Linked List is empty"<<endl;
        return;
    }
    
    Node* temp = tail;
    do{
        if(temp->data == value){
            Node* newNode = new Node(d);
            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }
        temp=temp->next;
    }while(temp != tail);

    cout<<"Value not present in linked list"<<endl;
}

// Deletion from a Circular Linked List

void deletionByValue(Node*& tail,int value){
    // 0 node
    if(tail == nullptr){
        cout<<"No node in Linked list deletion can't be performed"<<endl;
        return;
    }

    Node* prev = tail;
    Node* curr = tail->next;
    Node* temp = tail->next;

    do{
        if(curr->data == value){
            prev->next = curr->next;
            curr->next = nullptr;
            
            // 1 node in ll
            if(prev == curr){
                tail = nullptr;
            }
            // >=2 node
            if(curr == tail){
                tail = prev;
            }
            delete curr;
            return;
        }
        prev = curr;
        curr = curr->next;
    }while(curr != temp);

    cout<<" Value not present in linked list "<<endl;

}

// Traversal in Circular Linked List

void print(Node*& tail){
    if(tail == nullptr){
        cout<<"LL is empty"<<endl;
    }
    else{
        Node* temp = tail;
        do{
            cout<<temp->data<<" ";
            temp = temp->next;
        }while(temp != tail);
        cout<<endl;
    }
}

// Destructor Function for deleting circular linked list

void destructor(Node*& tail){
    // 0 node 
    if(tail == nullptr){
        return;
    }
    
    Node* curr = tail->next;
    // 1 node
    if(curr == tail){
        delete tail;
        return;
    }

    // >=2 node
    do{
        Node* temp = curr->next;
        delete curr;
        curr = temp;
    }while(curr != tail);
    
    delete tail;
}


int main(){
    
    Node* tail = nullptr;
    insertAfterTail(tail,2);
    print(tail);
    cout<<"tail "<<tail->data<<endl<<endl;

    insertAfterTail(tail,3);
    print(tail);
    cout<<"tail "<<tail->data<<endl<<endl;

    insertAfterTail(tail,6);
    print(tail);
    cout<<"tail "<<tail->data<<endl<<endl;

    insertAfterValue(tail,6,8);
    print(tail);
    cout<<"tail "<<tail->data<<endl<<endl;

    insertAfterValue(tail,2,5);
    print(tail);
    cout<<"tail "<<tail->data<<endl<<endl;

    deletionByValue(tail,6);
    print(tail);
    cout<<"tail "<<tail->data<<endl<<endl;


    destructor(tail);

    return 0;
}