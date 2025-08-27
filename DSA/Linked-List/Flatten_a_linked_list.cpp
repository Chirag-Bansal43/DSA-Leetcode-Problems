#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* child;

    Node(int data){
        this->data = data;
        this->next = nullptr;
        this->child = nullptr;
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
        temp = temp->child;
    }
    cout<<endl;
}

Node* mergeLL(Node* head,Node* curr){
    Node* curr1 = head;
    Node* curr2 = curr;
    Node* next1 = curr1->child;
    Node* next2 = curr2->child;
    if(next1 == nullptr){
        curr1->child = curr2;
        return head;
    }
    while(curr2 != nullptr){
        if(curr2->data >= curr1->data && curr2->data <= next1->data){
            curr1->child = curr2;
            curr2->child = next1;
            curr1 = curr2;
            curr2 = next2;
            if(next2 != nullptr)
                next2 = next2->child;
        }
        else{
            curr1 = next1;
            next1 = next1->child;
            if(next1 == nullptr){
                curr1->child = curr2;
                return head;
            }
        }
    }
    return head;
}

// Iterative way of solving 
// T.C = O(n*n*k) , where  ‘n’ denotes the number of head nodes and ‘k’ is the average number of child nodes in all 'n' sub-lists.
// S.C = O(1)
Node* flattenLinkedList_001(Node* head){
    if(head->next == nullptr)   return head;
    Node* curr = head->next;
    Node* forward = curr->next;
    head->next = nullptr;
    while(curr != nullptr){
        curr->next = nullptr;
        if(head->data <= curr->data){
            head = mergeLL(head,curr);
        }
        else{
            head = mergeLL(curr,head);
        }
        curr = forward;
        if(forward != nullptr)
            forward = forward->next;
    }
    return head;
}

// Recursive way of solving
// T.C = O(n*n*k) , where  ‘n’ denotes the number of head nodes and ‘k’ is the average number of child nodes in all 'n' sub-lists.
// S.C = O(log n) for recursive function calls in stack
Node* flattenLinkedList_002(Node* head) 
{   // Base Case
    if(head->next == nullptr)
        return head;

    Node* curr = head->next;
    head->next = nullptr;
    curr = flattenLinkedList_002(curr);
    if(head->data <= curr->data)
        head = mergeLL(head,curr);
    else
        head = mergeLL(curr,head);

    return head;
}



int main(){
    
    /*
        1->4->7->9->20->null
        |  |  |  |
        2  5  8  12
        |  |
        3  6
    */

    // Making above Linked List structure
    Node* head = nullptr;
    Node* tail = nullptr;
    Node* temp = nullptr;
    insertAtTail(tail,head,1);
    temp = tail;
    temp->child = new Node(2);
    temp=temp->child;
    temp->child = new Node(3);
    temp=temp->child;
    temp->child = nullptr;

    insertAtTail(tail,head,4);
    temp = tail;
    temp->child = new Node(5);
    temp=temp->child;
    temp->child = new Node(6);
    temp=temp->child;
    temp->child = nullptr;

    insertAtTail(tail,head,7);
    temp = tail;
    temp->child = new Node(8);
    temp=temp->child;
    temp->child = nullptr;

    insertAtTail(tail,head,9);
    temp = tail;
    temp->child = new Node(12);
    temp=temp->child;
    temp->child = nullptr;

    insertAtTail(tail,head,20);
    temp = tail;
    temp->child = nullptr;

    flattenLinkedList_002(head);

    print(head);

    return 0;
}