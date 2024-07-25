#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    
    node(int data){
        this->data = data;
        this->next = NULL;
    }
};

class Pair{
    public:
    node* head;
    node* tail;
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

void print(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void swap(node* head, int a, int b){
    node* temp =head;
    node *c1 = NULL, *c2 = NULL, *p1 = head, *p2 = head;
    int c = 0;
    while(temp!=NULL){
        for(c=0;c<a;c++){
            p1=p1->next;
            p2=p2->next;
        }
        c1 = p1 -> next;
        for(;c<b;c++){
            p2=p2->next;
        }
        c2 = p2 -> next;
    }

    p1->next = c2;
    p2->next = c1;
    c1->next = c2->next;
    c2->next = p2;
}

Pair reverseLL1(node* head){
    if(head == NULL || head->next == NULL){
        Pair ans;
        ans.head = head;
        ans.tail = head;
        return ans;
    }
    
    Pair smallans = reverseLL1(head->next);
    
    smallans.tail -> next = head;
    head->next = NULL;
    Pair ans;
    ans.head = smallans.head;
    ans.tail = head;
    return ans;

}

node* reverse(node* head, int k){
    if (head == NULL) 
        return head; 
    node* current = head; 
    node* next = NULL; 
    node* prev = NULL; 
    int count = 0; 
    while (current != NULL && count < k) { 
        next = current->next; 
        current->next = prev; 
        prev = current; 
        current = next; 
        count++; 
    } 
    if (next != NULL){
        head->next = reverse(next, k); 
    } 
    
    return prev;
} 
int main(){
    node* head = takeinput();

    print(head);
    swap(head, 1, 4);
    print(head);

}