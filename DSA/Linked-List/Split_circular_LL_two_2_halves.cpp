#include <bits/stdc++.h> 
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    ~Node(){
        int value = this->data;
        cout<<"memory is freed for node with value "<<value<<endl;
    }
};

// Insertion In a Circular Linked List

void insertAfterHead(Node*& head,int d){
    // LL empty
    if(head == nullptr){
        Node* newNode = new Node(d);
        newNode->next = newNode;
        head = newNode;
        return;
    }

    // LL is not empty
    Node* newNode = new Node(d);
    newNode->next = head->next;
    head->next = newNode;
}

void print(Node* head){
    Node* temp=head;
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp!=head);
    cout<<endl;
}

// T.C = O(2n) , S.C = O(1)
void splitCircularList(Node *head)
{
    int cnt=1;
    Node* temp;
    //O(n)
    for(temp=head;temp->next!=head;temp=temp->next){
        cnt++;
    }

    int length1,length2; // length of two circular sub linked lists
    if(cnt%2==0){   //LL have even no. of nodes
        length1 = cnt/2;
        length2 = cnt/2;
    }
    else{ // LL have odd no. of nodes
        length1 = cnt/2+1;
        length2 = cnt/2;
    }
    
    temp = head;
    cnt=1;
    //O(n/2)
    while(cnt < length1){
        temp=temp->next;
        cnt++;
    }

    Node* head2 = temp->next;
    temp->next = head;
    Node* head1 = head;
    
    temp = head2;
    //O(n/2)
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next = head2;

    print(head1);
    print(head2);
}

int main(){
    Node* head = nullptr;
    insertAfterHead(head,2);
    print(head);
    cout<<"head "<<head->data<<endl<<endl;

    insertAfterHead(head,3);
    print(head);
    cout<<"head "<<head->data<<endl<<endl;

    insertAfterHead(head,6);
    print(head);
    cout<<"head "<<head->data<<endl<<endl;

    insertAfterHead(head,10);
    print(head);
    cout<<"head "<<head->data<<endl<<endl;

    insertAfterHead(head,12);
    print(head);
    cout<<"head "<<head->data<<endl<<endl;
    
    splitCircularList(head);

    return 0;
}