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

// Method1 Sort 0s 1s 2s by data replacement
// T.C=O(2n) , S.C = O(1)
Node* Sort0s1s2s_001(Node* head){
    Node* temp;
    int cnt0=0,cnt1=0,cnt2=0;
    for(temp=head;temp!=nullptr;temp=temp->next){
        if(temp->data == 0) cnt0++;
        else if(temp->data ==1) cnt1++;
        else    cnt2++;
    }
    temp=head;
    int cnt=0;
    while(cnt<cnt0){
        temp->data=0;
        temp=temp->next;
        cnt++;
    }
    cnt=0;
    while(cnt<cnt1){
        temp->data=1;
        temp=temp->next;
        cnt++;
    }
    cnt=0;
    while(cnt<cnt2){
        temp->data=2;
        temp=temp->next;
        cnt++;
    }
    return head;
}

// Method -2 Sort by changing the links of linked list nodes not by data replacement
// T.C = O(n)   S.C = O(1)
Node* Sort0s1s2s_002(Node*& head){
    // Introducing the dummy nodes to make sublists of 0s 1s & 2s
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead; 
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;

    // Traversing the list
    Node* curr = head;
    while(curr != nullptr){
        if(curr->data == 0){
            zeroTail->next = curr;
            zeroTail = curr;
        }
        else if(curr->data == 1){
            oneTail->next = curr;
            oneTail = curr;
        }
        else{
            twoTail->next = curr;
            twoTail = curr;
        }
        curr=curr->next;
    }

    // Merge these sublists
    if(oneHead->next != nullptr){
        zeroTail->next = oneHead->next;
        oneTail->next = twoHead->next;
        twoTail->next = nullptr;
    }
    else{
        zeroTail->next = twoHead->next;
        twoTail->next = nullptr;
    }

    head = zeroHead->next;
    

    zeroHead->next=nullptr;
    oneHead->next=nullptr;
    twoHead->next=nullptr;
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;
}

int main(){

    Node* head = nullptr;
    Node* tail = nullptr;
    insertAtTail(tail,head,1);
    print(head);
    insertAtTail(tail,head,0);
    print(head);    
    insertAtTail(tail,head,2);
    print(head);
    insertAtTail(tail,head,1);
    print(head);
    insertAtTail(tail,head,2);
    print(head);
    cout<<"head "<<head->data<<"  tail "<<tail->data<<endl<<endl;

    Sort0s1s2s_002(head);

    print(head);
    cout<<"head "<<head->data<<"  tail "<<tail->data<<endl<<endl;

    delete head;
    return 0;
}