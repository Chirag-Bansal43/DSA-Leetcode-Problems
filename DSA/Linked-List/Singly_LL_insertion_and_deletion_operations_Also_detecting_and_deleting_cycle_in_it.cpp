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

// Detect Circularity and Cycle in LL

// Bekar
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

// Good but high T.C
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

// Detecting cycle in Linked List

// Finding Cycle in LL : Using Fast and Slow pointer
// T.C = O(n) in worst case , S.C = O(1)
bool isCyclic(Node*& head){
    Node* slow = head;
    Node* fast = head;
    while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            return 1;
        }
    }
    return 0;
}

//Get Starting Element of Loop : Using Fast and Slow pointer
// T.C = O(n) , S.C = O(1)
Node *getStartingNodeOfLoop(Node *head) {
    Node* slow = head;
    Node* fast = head;
    while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
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
bool isCircular(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
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

// Deleting Loop from LL
// T.C=O(n) , S.C=O(1)
Node* deletingCycle(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            slow=head;
            while(slow->next!=fast->next){
                slow=slow->next;
                fast=fast->next;
            }
            fast->next=nullptr;
        }
    }
    cout<<"Loop is successfully deleted..."<<endl;
    return head;
}

// Finding Length of Loop in LL Same as Deleting Loop from LL
int LenOfLoop(Node* head){
    Node* slow = head;
    Node* fast = head;
    int cnt=1;
    while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
        cnt++;
        if(slow==fast){
            return cnt-1;
        }
    }
    return -1;
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

    // deletionByPosition(head,tail,1);
    // print(head);
    // cout<<"head "<<head->data<<"  "<<"tail "<<tail->data<<endl<<endl;

    // deletionByValue(head,tail,3);
    // print(head);
    // cout<<"head "<<head->data<<"  "<<"tail "<<tail->data<<endl<<endl;
    //--------------------------------------------------------------------------------------
    //Till now LL is [3->5->7->10->13->null]

    // Adding cycle to LL
    tail->next = head->next->next; // LL becomes like this [3->5->7->10->13->7 cyclic]

    //Checking LL is circular or not
    if(isCircular(head))
        cout<<"LL is circular"<<endl;
    else    cout<<"LL is not circular"<<endl;

    //Checking there is a cycle in LL or not
    if(isCyclic(head))
        cout<<"LL is cyclic"<<endl;
    else    cout<<"LL is not cyclic"<<endl;

    // Printing starting node data of loop in LL 
    cout<<"Starting Node of Loop in LL having value : "<< getStartingNodeOfLoop(head)->data<<endl;
    
    // Length of Loop
    cout<<"Length of Loop in LL : "<<LenOfLoop(head)<<endl<<endl;

    // Deleting Cycle in LL
    deletingCycle(head);
    print(head);
    cout<<"head "<<head->data<<" tail "<<tail->data<<endl;
    //Now Check Is there any cycle in LL
    if(isCyclic(head))
        cout<<"LL is cyclic"<<endl;
    else    cout<<"LL is not cyclic"<<endl;


    delete head;
    return 0;
}