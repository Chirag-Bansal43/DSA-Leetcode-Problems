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
//-----------------------------------------------------------------------------------------------
// Iterative Solution

Node* reverse_001(Node*& j,Node*& i){
    Node* prev = nullptr;
    Node* curr = j;
    while(prev != i){
        Node* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    j = curr;
    i = curr;
    return prev;
}

// Iterative way of Solving
// T.C = O(2*n) because Linked List is traversed two times ; one in main fxn using i pointer and one to reverse the LL in reverse fxn
// S.C = O(1)
Node* ReverseInKGroups_001(Node* head,int K){
    Node* i=head;   Node* FirstNodeOfRevLL = nullptr;
    Node* j=head;   Node* LastNodeOfCurrRevLL = nullptr;
    int cnt = 1;    bool flag = false;
    while(j != nullptr){
        while(cnt != K && i!=nullptr){
            i=i->next;
            cnt++;
        }
        // if length of LL is not the multiple of K
        // some nodes left at the end
        if(i == nullptr){
            head->next = j;
            break;
        }
        LastNodeOfCurrRevLL = j;
        Node* revHead = reverse_001(j,i);
        if(flag == false){
            FirstNodeOfRevLL = revHead;
            flag = true;
        }
        else{
            head->next = revHead;
            head = LastNodeOfCurrRevLL;
        }
        cnt = 1;
    }
    return FirstNodeOfRevLL;
}
//------------------------------------------------------------------------------------------------------------
// Recursive Solution

Node* reverse_002(Node* head,Node* tail){
    Node* prev = nullptr;
    Node* curr = head;
    while(curr != tail){
        Node* forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}


// Recursive way of Solving -> Very Interesting you must understand the flow of this
// T.C = O(2n + n/k) = O(n) -> whole LL is traversed two times ; one by using tail pointer and other for reversing the nodes in reverse fxn() + (n/k) time is used in backtracking the fxn calls and join these hext->next connections for each k group 
// S.C = O(n/k) = O(n) -> Recursion stack depth is n/k as fxn calls for each K group will wait in stack
Node* ReverseInKGroups_002(Node* head,int K){
    Node* tail = head;
    int cnt = 0;
    while(cnt != K){
        if(tail == nullptr) return head; // Base Case
        tail = tail->next;
        cnt++;
    }

    Node* newHead = reverse_002(head,tail);
    head->next = ReverseInKGroups_002(tail,K);

    return newHead;
}

int main(){
    Node* head = nullptr;
    Node* tail = nullptr;

    insertAtTail(tail,head,2);
    insertAtTail(tail,head,3);
    insertAtTail(tail,head,8);
    insertAtTail(tail,head,7);
    insertAtTail(tail,head,11);
    insertAtTail(tail,head,9);
    insertAtTail(tail,head,47);
    insertAtTail(tail,head,93);

    print(head);
    cout<<"head : "<<head->data<<" tail : "<<tail->data<<endl;

    Node* revLL = ReverseInKGroups_002(head,3);
    print(revLL);

    return 0;
}