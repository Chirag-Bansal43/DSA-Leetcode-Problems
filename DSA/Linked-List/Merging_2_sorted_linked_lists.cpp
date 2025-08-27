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
        int dataue = this->data;
        if(this->next != nullptr){
            delete next;    // recursively delete whole linked list
            this->next = nullptr;
        }
        cout<<"memory is freed for node with data "<<dataue<<endl;
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

// Approach 1 : Similar two merging 2 sorted arrays (we merge two sorted LL by changing their links)
// T.C = O(m+n) , S.C = O(1)
Node* mergeTwoLists_001(Node* head1,Node* head2){
    // creating a dummy node so that I can add nodes after it in sorted manner
    Node* listHead = new Node(-1);
    Node* listTail = listHead;

    // Traversing the two sorted lists
    Node* curr1 = head1;
    Node* curr2 = head2;
    while(curr1 != nullptr && curr2 != nullptr){
        while(curr1 != nullptr && curr2 != nullptr && curr1->data <= curr2->data){
            listTail->next = curr1;
            listTail=curr1;
            curr1=curr1->next;
        }
        while(curr1 != nullptr && curr2 != nullptr && curr2->data <= curr1->data){
            listTail->next = curr2;
            listTail=curr2;
            curr2=curr2->next;
        }
    }

    // Attatching the remaining sorted sublist to our main list
    if(curr1 != nullptr){
        listTail->next = curr1;
    }

    if(curr2 != nullptr){
        listTail->next = curr2;
    }

    Node* head = listHead->next;
    listHead->next = nullptr;
    delete listHead;
    
    return head;
}

// Approach 2 : Solving using Sliding Window Concept
// T.C = O(m+n) in worst case , S.C = O(1)
Node* solve(Node* first, Node* second){
    Node* curr1 = first;
    Node* next1 = first->next;
    Node* curr2 = second;
    Node* next2 = second->next;

    // Edge case (first LL have only one node)
    if(first->next == nullptr){
        first->next = second;
        return first;
    }

    while(curr2 != nullptr){
        if(curr2->data >= curr1->data && curr2->data <= next1->data){

            // Insert the node in between the window curr1 and next1
            curr1->next = curr2;
            next2=curr2->next;
            curr2->next = next1;
            curr1 = curr2;
            curr2 = next2;
        }
        else{
            // Move the window forward
            curr1=next1;
            next1=next1->next;
            if(next1 == nullptr){
                curr1->next = curr2;
                return first;
            }
        }
    }
    return first;
}

Node* mergeTwoLists_002(Node* first,Node* second){
    // starting edge cases
    if(first == nullptr)    return second;
    if(second == nullptr)    return first;

    if(first->data <= second->data){
        return solve(first,second);
    }
    else{
        return solve(second,first);
    }

    return nullptr;
}

int main(){
    
    Node* head1 = nullptr;
    Node* tail1 = nullptr;
    Node* head2 = nullptr;
    Node* tail2 = nullptr;

    // First sorted List
    insertAtTail(tail1,head1,2);
    print(head1);
    insertAtTail(tail1,head1,5);
    print(head1);
    insertAtTail(tail1,head1,7);
    print(head1);
    insertAtTail(tail1,head1,11);
    print(head1);
    insertAtTail(tail1,head1,15);
    print(head1);
    cout<<endl<<endl;
    // Second sorted list
    insertAtTail(tail2,head2,1);
    print(head2);
    insertAtTail(tail2,head2,6);
    print(head2);
    insertAtTail(tail2,head2,9);
    print(head2);
    insertAtTail(tail2,head2,10);
    print(head2);
    insertAtTail(tail2,head2,13);
    print(head2);

    Node* head = mergeTwoLists_002(head1,head2);

    cout<<"\nMerged Linked List :-"<<endl;
    print(head);

    return 0;
}