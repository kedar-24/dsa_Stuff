#include<iostream>
using namespace std;
template <typename T>
class node{
    public:

    T data;
    node<T> *next;

    node(T data){
        this-> data = data;
        next = NULL;
    }
};

template <typename T>
class queue{
    node<T> *head;
    node<T> *tail;
    int size;

    public:
    
    queue(){
        head = NULL;
        tail = NULL;
        size = 0;
    }

    bool isEmpty(){
        return {head == NULL};
    }

    int getSize(){ return size;}
    
    void enqueue(T val){
        node<T> *nn = new node<T>(val);
        if(head == NULL){
            head = tail = nn;
        }else{
            tail->next = nn;
            tail = tail->next;
        }
        size++;
    }

    T dequeue(){
        if(head == NULL){
            cout<<"Queue is empty."<<endl;
            return 0;
        }
        T ans = head->data;
        node<T> *a = head;
        head = head -> next; 
        delete a;
        size--; 
        return ans;
    }

    T front(){
        if(isEmpty()){
            return 0;
        }
        return head->data; 
    }

};