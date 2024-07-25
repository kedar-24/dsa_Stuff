#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node * next;

    node(int data){
        this->data = data;
        this->next = NULL;
    }
};

node* takeinput(){
    int data;
    cin>>data;
    node* head = NULL;
    node* tail = NULL;
    while(data!= -1){
        node* nn = new node(data);
        if(head==NULL){
            head=tail=nn;
        }else{
            tail -> next = nn;
            tail = tail -> next;
        }
        cin>>data;
    }
    return head;
}

int length(node* head){
    if(head==NULL){
        return 0;
    }else{
        return (1+length(head->next));
    }
}

node* mid(node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    node* slow = head;
    node* fast = head;
    while(fast->next->next != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

void print(node* head){
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl; 
}

int main(){
    node* head;
    head = takeinput();
    
    print(head);

    cout<<mid(head)->data<<endl;
}