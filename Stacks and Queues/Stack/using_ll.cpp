#include <iostream>
using namespace std;


template <typename T>
class node{
    public:

    T data;
    node<T> *next;

    node(T data){
        this->data = data;
        next = NULL;
    }
};

template <typename T>
class stack1{
    node<T>* head;
    int size;

    public:

    stack1(){
        head =NULL;
        size = 0;
    }
    T top(){
        if(isEmpty()){
            return 0;
        }
        return (head->data);
    }
    int getSize(){
        return size;
    }

    bool isEmpty(){
        return (head == NULL);
    }

    void push(T data){
        node<T>* nn = new node<T>(data);
        nn -> next = head;
        head = nn;
        size++;
    }

    void pop(){
        if(isEmpty()){
            return ;
        }
        T pop = head->data;
        node<T> *a = head;
        head = head ->next;
        delete a;
        size--;
        return;
    }
    void print(){
        node<T> *temp = head;
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};

