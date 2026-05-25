#include <bits/stdc++.h>
using namespace std;

// STACK IMPLEMENTATION USING CLASS

class Stack{
    private:
    // properties
    int *arr;
    int top;
    int size;

    public:
    //constructor
    Stack(int size){
        this->size = size;
        arr = new int[size];
        this->top = -1;
    }

    // Methods
    void push(int element){
        if(size-top > 1){
            top++;
            arr[top] = element;
        }
        else{
            cout<<"Stack Overflow"<<endl; 
        }
    }

    void pop(){
        if(top>=0){
            top--;
        }
        else{
            cout<<"Stack Underflow"<<endl;
        }
    }

    int peek(){
        if(top>=0){
            return arr[top];
        }
        else{
            cout << "Stack is empty"<<endl;
        }
        return -1;
    }

    bool empty(){
        if(top == -1)   return true;
        return false;
    }

    void print_Stack(){
        cout<<"\nPrinting Stack : "<<endl;
        for(int i = top; i >=0; i--){
            cout<<' '<<arr[i];
        }
        cout<<endl;
    }

    ~Stack(){
        delete[] arr;
    }

};




/*
void printStack(stack<int> s){
    int n = s.size();
    cout<<"\nPrinting Stack : "<<endl;
    for(int i = 0; i < n; i++){
        cout<<' '<<s.top();
        s.pop();
    }
}*/


int main(){
    /* STACK IMPLEMENTATION USING STL
    stack<int> s;
    s.push(2);
    s.push(4);
    s.push(6);
    s.push(8);
    s.push(10);

    printStack(s);


    for(int i = 0; i < 5; i++){
        cout<<"\nElement poped from stack : "<<s.top();
        s.pop();
    }

    printStack(s);

    // Isempty
    s.empty()? cout<<"Stack is empty" : cout<<"Stack is not empty"; */


    Stack st(6);
    for(int i=0;i<6;i++){
        st.push(i);
    }

    st.print_Stack();

    st.push(7);
    st.print_Stack();

    char ch = 'c';
    
    switch (ch)
    {                                                   
    case 'c':
        /* code */
        break;
    
    default:
        break;
    }


    return 0;
}