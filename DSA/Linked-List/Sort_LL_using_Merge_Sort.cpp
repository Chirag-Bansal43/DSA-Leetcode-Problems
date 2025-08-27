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

// Sorting Linked List using Merge Sort Algorithm
// T.C = O(n* log2n) , S.C = O(log2 n) space required for recursion calls wait in stack which uses some small memory for storing metadata (like memory for pointers etc.) for each recursion call 
// Depth of Recursion is log2n , where n is the number of elements in linked list...
// Point to note here is that Unlike arrays , No temperory array is required for merging the two sorted parts of a linked list that's why Merge Sort Algorithm is the Optimal sorting algorithm for sorting Linked Lists.
// Quick sort algo. required a lot of random access of elements which can't be done in data Structures like linked lists. Therefore, Quick Sort is not used to sort linked lists.
Node* mergeLL(Node* head1,Node* head2){
    Node* curr1 = head1;
    Node* next1 = head1->next;
    Node* curr2 = head2;
    Node* next2 = head2->next;
    if(next1 == nullptr){
        curr1->next = curr2;
        return head1;
    }

    while(curr2 != nullptr){
        if(curr2->data >= curr1->data && curr2->data <= next1->data){
            curr1->next = curr2;
            curr2->next = next1;
            curr1 = curr2;
            curr2 = next2;
            if(next2 != nullptr)
                next2 = next2->next;
        }
        else{
            curr1 = next1;
            next1 = next1->next;
            if(next1 == nullptr){
                curr1->next = curr2;
                return head1;
            }
        }
    }
    return head1;
}

Node* getMid(Node* head){
    Node* slow = head;
    Node* fast = head->next;
    while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}


Node* mergeSortLL(Node* head){
    // Base case
    if(head == nullptr || head->next == nullptr){
        return head;
    }
    Node* mid = getMid(head);
    Node* head1 = head;
    Node* head2 = mid->next;
    mid->next = nullptr;
    head1 = mergeSortLL(head1);
    head2 = mergeSortLL(head2);
    if(head1->data <= head2->data){
        return mergeLL(head1,head2);
    }
    else{
        return mergeLL(head2,head1);
    }
    return nullptr;
}


int main(){
    // [3->4->1->6->2->5->7->null]
    Node* head =  nullptr;
    Node* tail =  nullptr;

    insertAtTail(tail,head,3);
    print(head);
    insertAtTail(tail,head,4);
    print(head);
    insertAtTail(tail,head,1);
    print(head);
    insertAtTail(tail,head,6);
    print(head);
    insertAtTail(tail,head,2);
    print(head);
    insertAtTail(tail,head,5);
    print(head);
    insertAtTail(tail,head,7);
    print(head);

    cout<<"\nSorted Linked List :-"<<endl;
    head = mergeSortLL(head);
    print(head);

    return 0;
}