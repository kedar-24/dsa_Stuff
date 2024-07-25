#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int data){
        this->data = data;
        next = NULL; 
    }
};

void print(node* head){
    node * temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

node* takeinput(){
    int data;
    cin>>data;
    node* head = NULL;
    while(data!=-1){
        node* nn = new node(data);
        if(head == NULL){
            head = nn;
        }else{
            node* temp = head;
            while(temp->next!=0){temp=temp->next;}
            temp->next=nn;
        }
        cin>>data;
    }
    return head;
}

//head and tail.
node* takeinputh(){
    int data;
    cin>>data;
    node *head = NULL;
    node *tail = NULL;
    while(data!=-1){
        node* nn = new node(data);
        if(head == NULL && tail == NULL){
            head = tail = nn;
        }else{
            tail -> next = nn;
            tail = tail->next;
        }
        cin>>data;
    }
    return head;
}

node* inith(node* head,int pos, int val){
    node* temp = head;
    node* nn = new node(val);
    if(pos==0){
        nn->next = head;
        head = nn;
        return head;
    }
    int c=0;
    while(temp!=NULL && c<pos-1){
        temp=temp->next;
        c++;
    }
    if(temp!=NULL){
        nn->next = temp->next;
        temp->next = nn;
    }
    return head;
    
}

node* deletenode(node* head, int pos){
    node* temp = head;
    if(pos==0){
        head = head ->next;
        delete temp;
        return head;
    }
    int c=0;
    while(temp!=NULL && c<pos-1){
        temp = temp -> next;
        c++;
    }
    if(temp!=NULL){
        node* a = temp-> next;
        temp ->next = a-> next;
        a-> next = NULL;
        delete a;
    }
    return head;
}

int length(node* head){
    if(head==NULL){
        return 0;
    }else{
        return (1+ length(head->next));
    }
}

node* insertRec(node* head, int i, int val){
    if(i==0 || head == NULL){
        node* nn = new node(val);
        nn->next = head;
        head = nn;
    }else{
        head->next = insertRec(head->next,i-1,val);
    }
    return head;
}

node* deleteRec(node* head, int i){
    if(i==0 || head==NULL){
        node*temp = head;
        head = head-> next;
        delete temp;
    }else{
        head->next = deleteRec(head->next, i-1);
    }
    return head;
}
int find(node* head, int val){
    node* temp= head;
    int c=0;
    while(temp!=NULL){
        if(temp -> data == val){
            return c;
        }
        temp = temp->next;
        c++;
    }
    return -1;

}
int findRec(node* head, int val){
    if(head!=NULL && head->data == val){
        return 0;
    }else{
        return (1+find(head->next,val));
    }
    return -1;
}

int main(){
    node n1(10);
    node* head = &n1;
    node n2(20);
    node n3(30);
    n1.next = &n2;
    n2.next = &n3;

    print(head);
    cout<<length(head)<<endl;
    cout<<find(head,0)<<endl;

    node* head2 = takeinputh();
    print(head2);

    head2 = insertRec(head2, 5, 999);
    print(head2);

    head2 = deleteRec(head2,5);
    print(head2);

    cout<<find(head2,5)<<endl;

} 