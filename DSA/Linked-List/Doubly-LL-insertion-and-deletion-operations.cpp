#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node* prev;
    Node* next;

    Node(int d){
        this->data = d;
        this->prev = nullptr;
        this->next = nullptr;
    }
    ~Node(){
        int value = this->data;
        if(this->next != nullptr){
            delete next;
            this->next = nullptr;
        }
        this->prev = nullptr;
        cout<<"memory is freed for node with value "<<value<<endl;
    }
};

#pragma region // Insertion in a Doubly Linked List

void insertionAtHead(Node*& head,Node*& tail,int d){
    // Linked List is empty
    if(head == nullptr){
        Node* nodeToInsert = new Node(d);
        head = nodeToInsert;
        tail = nodeToInsert;
    }
    // Linked List is not empty
    else{
        Node* nodeToInsert = new Node(d);
        nodeToInsert->next = head;
        head->prev = nodeToInsert;
        head = nodeToInsert;
    }
}

void insertAtTail(Node*& tail,Node*& head,int d){
    // Linked List is empty
    if(head == nullptr){
        Node* nodeToInsert = new Node(d);
        head = nodeToInsert;
        tail = nodeToInsert;
    }
    else{
        Node* nodeToInsert = new Node(d);
        tail->next = nodeToInsert;
        nodeToInsert->prev = tail;
        tail = nodeToInsert;
    }
}

void insertAtPosition(Node*& head,Node*& tail,int position,int d){
    // Linked List is empty
    try{
        if(head == nullptr){
            Node* nodeToInsert = new Node(d);
            head = nodeToInsert;
            tail = nodeToInsert;
            if(position > 1){
                throw position;
            }
            return;
        }
    }
    catch(int position){
        cout<<"Warning : Linked List is empty so you can't insert at position "<<position<<" . So, The node is inserted at first position"<<endl;
    }

    // Linked list is not empty
    Node* temp = head;
    int cnt = 1;
    while(cnt < position-1){
        temp = temp->next;
        cnt++;
    }
    
    // insertion at starting 
    if(position == 1)
        insertionAtHead(head,tail,d);
    // insertion at end
    else if(temp->next == nullptr)
        insertAtTail(tail,head,d);
    // insertion in middle
    else{
        Node* nodeToInsert = new Node(d);
        nodeToInsert->next = temp->next;
        temp->next->prev = nodeToInsert;
        temp->next = nodeToInsert;
        nodeToInsert->prev = temp;
    }
}
#pragma endregion

#pragma region // Deletion in a Doubly linked List

void deletionByPosition(Node*& head,Node*& tail,int position){
    // if LL is empty
    if(head == nullptr){
        cout<<"LL is empty not deletion can takes place"<<endl;
        return;
    }

    // LL is not empty

    Node* previous = nullptr;
    Node* current = head;
    int cnt = 1;
    while(cnt < position){
        previous = current;
        current = current->next;
        cnt++;
    }

    if(position == 1){
        head = head->next;
        current->next = nullptr;
        head->prev = nullptr;
        delete current;
    }

    else if(current->next == nullptr){
        current->prev = nullptr;
        previous->next = nullptr;
        tail = previous;
        delete current;
    }

    else{
        previous->next = current->next;
        current->next->prev = previous;
        current->next = nullptr;
        current->prev = nullptr;
        delete current;
    }

}

void deletionByValue(Node*& head,Node*& tail,int value){
    // if LL is empty
    if(head == nullptr){
        cout<<"LL is empty not deletion can takes place"<<endl;
        return;
    }

    // LL is not empty

    Node* previous = nullptr;
    Node* current;

    for(current = head; current!=nullptr ; current=current->next){ //O(n)
        if(current->data == value){
            if(previous == nullptr){
                head = head->next;
                current->next = nullptr;
                head->prev = nullptr;
                delete current;
            }
            else if(current->next == nullptr){
                current->prev = nullptr;
                previous->next = nullptr;
                tail = previous;
                delete current;
            }
            else{
                previous->next = current->next;
                current->next->prev = previous;
                current->next = nullptr;
                current->prev = nullptr;
                delete current;
            }
            return;
        }
        previous = current;
    }
    cout<<"Value not present in Linked List"<<endl;
}
#pragma endregion

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

    insertAtPosition(head,tail,1,3);
    print(head);

    insertAtPosition(head,tail,2,5);
    print(head);

    insertAtPosition(head,tail,1,1);
    print(head);

    insertAtPosition(head,tail,3,4);
    print(head);

    cout<<"head "<<head->data<<"  "<<"tail "<<tail->data<<endl<<endl;

    insertAtTail(tail,head,7);
    print(head);

    cout<<"head "<<head->data<<"  "<<"tail "<<tail->data<<endl<<endl;

    deletionByPosition(head,tail,4);
    print(head);

    cout<<"head "<<head->data<<"  "<<"tail "<<tail->data<<endl<<endl;

    deletionByValue(head,tail,1);
    print(head);

    cout<<"head "<<head->data<<"  "<<"tail "<<tail->data<<endl<<endl;

    delete head;
    return 0;
}