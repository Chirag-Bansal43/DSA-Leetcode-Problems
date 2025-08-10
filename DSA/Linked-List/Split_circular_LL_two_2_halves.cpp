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
    };



void print(Node* head){
    Node* temp=head;
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp!=head);
    cout<<endl;
}


void splitCircularList(Node *head)
{
    int cnt=1;
    Node* temp;
    for(temp=head;temp->next!=head;temp=temp->next){
        cnt++;
    }
    int length = cnt/2;
    
    temp = head;
    cnt=1;
    while(cnt < length){
        temp=temp->next;
        cnt++;
    }

    Node* head2 = temp->next;
    temp->next = head;
    Node* head1 = head;
    
    temp = head2;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next = head2;

    print(head1);
    print(head2);
}

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

    insertAfterTail(tail,10);
    print(tail);
    cout<<"tail "<<tail->data<<endl<<endl;
    
    splitCircularList(tail->next);

    return 0;
}