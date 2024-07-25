#include <iostream>
using namespace std;

template <typename T>
class node{
    public:
    T data;
    node<T> *next;

    node(T data){
        this->data = data;
        this->next = NULL;
    }
};

template <typename T>
class Dqueue{
    node<T> *head;
    node<T> *tail;
    int size;
    int capacity;

    public:

    Dqueue(int capacity){
        head = tail = NULL;
        size = 0;
        this->capacity = capacity;
    }

    int getSize(){ return size;}

    bool isEmpty(){return head==NULL;}

    T getFront(){
        if(isEmpty()){
            return 0;
        }
        return head->data;
    }

    T getRear(){
        if(isEmpty()){
            return 0;
        }
        return tail->data;
    }

    void enqend(T element){
        if(size != capacity){
            node<T> *nn = new node<T>(element);
            if(head == NULL){
                head = tail = nn;
                size++;
                return;
            }
            tail->next = nn;
            tail = nn;
            size++;
        }else{
            cout<<"-1"<<endl;
        }
        
    }

    void enqfront(T element){
        if(size != capacity){
            node<T> *nn = new node<T>(element);
            if(head == NULL){
                head = tail = nn;
                size++;
                return;
            }
            nn->next = head;
            head = nn;
            size++;
        }else{
            cout<<"-1"<<endl;
        }
    }

    T deqend(){
        if(isEmpty()){
            return 0;
        }
        T ans = tail-> data;
        delete tail;
        size--;
        node<T> *temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        tail = temp;
        return ans;
    }

    T dequeue(){
        if(head == NULL){
            return 0;
        }
        T ans = head->data;
        node<T> *a = head;
        head = head -> next; 
        delete a;
        size--; 
        return ans;
    }
};

int main(){
    Dqueue<int> d1(10);

    d1.enqend(10);
    d1.enqend(20);
    d1.enqend(30);
    d1.enqend(1);
    d1.enqend(2);
    d1.enqfront(40);
    d1.enqfront(50);
    d1.enqfront(60);
    d1.enqfront(70);
    d1.enqfront(80);
    d1.enqfront(90);

    cout<<d1.getFront()<<endl;
    cout<<d1.getRear()<<endl;

    while(!d1.isEmpty()){
		cout<<d1.getFront()<<" ";
		d1.dequeue();
	}
}