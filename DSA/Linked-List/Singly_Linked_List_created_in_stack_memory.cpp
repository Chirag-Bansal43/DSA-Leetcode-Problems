#include <bits/stdc++.h>
using namespace std;

class Node
{
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

void print(Node*& head){
    Node* temp = head;
    
    // empty list
    if(temp == nullptr){
        cout<< "List is empty"<<endl;
    }
    // list is not empty
    else{
        while(temp != nullptr){
            cout<< temp->data <<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
}

int main(){
    // Linked List in stack memory for this automatically gets freed when then program goes out of scope of this variable  
    Node N1(2);
    Node N2(5);
    Node N3(10);
    Node N4(12);

    Node* head = &N1;
    
    // connecting nodes
    N1.next = &N2;
    N2.next = &N3;
    N3.next = &N4;


    print(head);

    return 0;
}