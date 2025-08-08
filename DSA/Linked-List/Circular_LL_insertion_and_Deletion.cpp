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

// Detecting Loop in Linked List

// Method-1(Not Good because not work for cyclic LL inputs) : Using simple traversing using while loop
// This method does not work when input linked list have cycle in it
// T.C = O(n) , S.C = O(1)
bool isCircular_001(Node*& head){
    if(head == nullptr) return 1;
    // >=1 nodes in LL
    Node* temp = head->next;
    while(temp != nullptr && temp != head){
        temp=temp->next;
    }

    if(temp == head)    return 1;
    return 0;
}

// Method-2(work for all inputs but have high time complexity) : Using hash map<Node*,bool> or hash set<Node*>
// This method also works when input LL having cycle but not circular...
// T.C = O(n) in avg case in case of unordered_map | But T.C = O(n^2) in case of collisions in unordered_map in worst case
// S.C = O(n) of map data structure
// Written by me not perfect but i am happy :) ........................
bool isCircular_02(Node*& head){
    if(head == nullptr) return 1;
    unordered_map<Node*,bool> mpp;
    Node* temp = head;
    while(temp != nullptr){
        if(mpp.find(temp) == mpp.end()){
            mpp[temp] = true;
            temp=temp->next;
        }
        // two cases came in else 
        // 1. LL have cycle but not circular
        // 2. LL have cycle and circular LL
        else{ 
            if(mpp.find(temp)->first == head){
                // LL is circular
                return 1;
            }
            // LL having cycle but not circular
            return 0;
        }
    }
    // temp == null => LL is not circular
    return 0;
}

// Another nicer way of writing the same code 
bool isCircular_002(Node*& head){
    if(head == nullptr) return 1;

    unordered_map<Node*,bool> visited;
    Node* temp = head;
    //cout<<"temp node is visited or not : " <<visited[temp]<<endl; -> Bydefault value of any node address in map is false or 0
    while(temp!= nullptr){
        if(visited[temp] == true){ // node is visited
            if(temp == head)    return 1;
            return 0;
        }
        // If the node is not visited then By default it's value stored in map is 0(or false)
        visited[temp] = true;
        temp=temp->next;
    }
    return 0;
}

// Detecting cycle in LL

//Method : Optimal Approach
//Using Fast and Slow Pointer (Floyd's cycle detection algorithm)
// T.C = O(n) , S.C = O(1)
bool isCyclic(Node*& head){
    if(head == nullptr) return 0;

    Node* slow = head;
    Node* fast = head;
    while(fast!=nullptr && slow!=nullptr){
        fast=fast->next;
        if(fast!=nullptr)
            fast=fast->next;
        else return 0;

        slow=slow->next;
        
        if(slow == fast){
            return 1;
        }
    }
    return 0;
}

//Get Starting Element of Loop : Using Fast and Slow pointer
// T.C = O(n) , S.C = O(1)
Node *getStartingNodeOfLoop(Node *head) {
    if(head == nullptr) return nullptr;
    Node* slow = head;
    Node* fast = head;
    while(fast!=nullptr){
        fast=fast->next;
        if(fast!=nullptr)   fast=fast->next;
        else return nullptr;
        slow=slow->next;
        if(slow==fast){
            slow=head;
            while(slow!=fast){
                slow=slow->next;
                fast=fast->next;
            }
            return slow;
        }
    }
    return nullptr;
}

// Optimal : T.C = O(n) , S.C = O(1)
bool isCircular_003(Node* head){
    if(head == nullptr) return 1;

    Node* slow = head;
    Node* fast = head;
    while(fast!=nullptr && slow!=nullptr){
        fast=fast->next;
        if(fast!=nullptr)
            fast=fast->next;
        else return 0;

        slow=slow->next;
        
        if(slow == fast){
            slow = head;
            while(slow != fast){
                fast=fast->next;
                slow=slow->next;
            }

            if(slow == head)    return 1; // LL is Circular
            return 0; // else have cycle but not circular
        }
    }
    return 0;
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

    //Checking LL is circular or not
    if(isCyclic(tail))
        cout<<"LL is cyclic"<<endl<<endl;
    else    cout<<"LL is not cyclic"<<endl<<endl;

    destructor(tail);

    return 0;
}