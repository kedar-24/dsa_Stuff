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
node* reversell_Better(node* head){
    return reverseLL1(head).head;
}
node* reverseLL(node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    
    node* smallans = reverseLL(head->next);

    node* temp = smallans;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = head;
    head->next=NULL;

    return smallans;
}
void print(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int search(node*head, int n){
    if(head == NULL){
        return -1;
    }
    if(head->data == n){
        return 0;
    }
    return (1+search(head->next, n));
}

node* OddEven(node* head){
    node*temp =head;
    node *oh = NULL, *ot = NULL, *eh = NULL, *et = NULL;
    while(temp!=NULL){
        if((temp->data)%2 == 0){
            if(eh == NULL){
                eh = et = temp;
            }else{
                et -> next = temp;
                et = et->next;
            }
        }else{
            if(oh == NULL){
                oh = ot = temp;
            }else{
                ot -> next = temp;
                ot = ot->next;
            }
        }
        temp=temp->next;
    }
    if(ot == NULL){
        return eh;
    }
    ot -> next = eh;
    return oh;
}

void deletebad(node* head, int m, int n){
    node* t1 = head;
    node* t2 ;
    int c;
    while(t1!=NULL){
        c=1;
        while(c<=m && t1 != NULL){
            t1=t1->next;
            c++;
        }
        t2 = t1 -> next;
        c=1;
        while(c<n && t2 != NULL){
            node* a = t2;
            t2=t2->next;
            delete a;
            c++;
        }
        t1 -> next = t2;
        t1 = t2;
    }
}


int main(){
    node* head;
    head = takeinput();
    /*int n;
    cin>>n;
    print(head);
    //head = reversell_Better(head);
    //print(head);
    cout<<search(head,n)<<endl;
    */

    //head = OddEven(head);
    print(head);
    deletebad(head, 2, 3);
    print(head);

}