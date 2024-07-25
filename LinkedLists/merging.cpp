#include <iostream>
using namespace std;

class node{
    public:
    
    int data;
    node* next;

    node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

node* takeinput(){
    int data;
    cin>>data;
    node* head=NULL;
    node* tail=NULL;
    while(data != -1){
        node* nn = new node(data);
        if(head == NULL){
            head=tail=nn;
        }else{
            tail -> next = nn;
            tail = tail -> next;
        }
        cin>>data;
    }
    return head;
}

node* merge(node* h1, node* h2){
    node * result = NULL;

    if(h1 == NULL){
        return h2;
    }
    if(h2 == NULL){
        return h1;
    }

    if(h1->data < h2->data){
        result = h1;
        result -> next = merge(h1->next, h2);
    }else{
        result = h2;
        result -> next = merge(h1, h2->next);
    }

    return result;
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
        temp = temp -> next;
    }
    cout<<endl;
}

void mergesort(node** head){
    if((*head) == NULL || (*head)->next == NULL){
        return ;
    }

    node * middle = mid(*head);
    node * left = *head;
    node * right = middle -> next;
    middle->next = NULL; 

    mergesort(&left);
    mergesort(&right);

    *head = merge(left, right); 
}

int main(){
    node* h1 = takeinput();
    //node* h2 = takeinput();

    //node* hs = merge(h1,h2);

    print(h1);
    mergesort(&h1);
    print(h1);
}