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

node* AppendlastN(node* head, int n){
    node* temp = head;
    for(int i =0; i<(length(head)-(n-1)); i++){
        temp = temp->next;
    }
    node* nh = temp->next;
    temp->next=NULL;
    node* nt = nh;
    while(nt->next!=NULL){
        nt=nt->next;
    }
    nt->next = head;

    return nh;
}
void print(node* head){
    node * temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void removeDup(node*head){
    node* t1 = head;
    node* t2 = head-> next;
    while(t2!=NULL){
        if(t1->data!=t2->data){
            t1->next = t2;
            t1=t2;
            t2=t2->next;
        }else{
            node* a = t2;
            t2 = t2->next;
            delete a;
        }
    }
    t1->next = t2;
}

void printrev(node*  head){
    if(head->next == NULL){
        //cout<<head->data<<" ";
    }else{
        printrev(head->next);
        //cout<<head->data<<" ";
    }
    cout<<head->data<<" ";
}

void reverse(node* head){
    node* temp = head;
    node* prev = NULL;
    node* next = NULL;
    while(temp!=NULL){
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    head = prev;
}

bool isPalindrome(node* head){
    int c = 0;
    node* temp = head;
    while(c<((length(head)-1)/2)){
        temp = temp->next; 
        c++;
    }
    node* h2 = temp->next;
    print(h2);
    temp = NULL;
    reverse(h2);
    print(head);
    int c1 = length(head), c2 = length(h2);
    while(c2>=0){
        if(head->data == h2->data){
            head = head->next; c1--;
            h2 = h2->next; c2--;
        }else{
            return false;
        }
    }
    return true;

}
int main(){
    node* head;
    /*head = takeinput();
    print(head);
    head = AppendlastN(head,3);
    print(head);*/

    node*  h1;
    h1 = takeinput();
    /*print(h1);
    removeDup(h1);
    print(h1);*/
    //print(h1);
    //printrev(h1);

    cout<<endl<<isPalindrome(h1)<<endl;
    
}