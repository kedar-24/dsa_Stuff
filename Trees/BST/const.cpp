#include <iostream> 
#include <queue>
#include "class.h"
using namespace std;

class llnode{
    public:
    int data;
    llnode* next;

    llnode(int data){
        this->data = data;
        next = NULL;
    }
};
bstnode<int>* takeinput(){
    int rootdata;
    cout<<"enter root data : ";
    cin>>rootdata;
    if(rootdata == -1){
        return NULL;
    }

    bstnode<int>* root = new bstnode<int>(rootdata);
    
    queue<bstnode<int>*> q;
    q.push(root);
    while(q.size()!=0){
        bstnode<int>* front = q.front();
        q.pop();
        int lcdata;
        cout<<"enter left child data of "<<front->data<<" : ";
        cin>>lcdata;
        if(lcdata != -1){
            bstnode<int>* left = new bstnode<int>(lcdata);
            front->left = left;
            q.push(left);
        }

        int rcdata;
        cout<<"enter right child data of "<<front->data<<" : ";
        cin>>rcdata;
        if(rcdata != -1){
            bstnode<int>* right = new bstnode<int>(rcdata);
            front->right = right;
            q.push(right);
        }
    }
    return root;
}

void printwise(bstnode<int>* root){
    if(root == NULL){
        return;
    }
    queue<bstnode<int>*> q;
    q.push(root);
    while(q.size()!=0){
        bstnode<int>* front = q.front();
        q.pop();
        cout<<front->data<<" : ";
        if(front->left != NULL){
            cout<<"L"<<front->left->data<<", ";
            q.push(front->left);
        }
        if(front->right != NULL){
            cout<<"R"<<front->right->data<<", ";
            q.push(front->right);
        }
        cout<<endl;
    }
}

bstnode<int>* makeatree(int* a, int si, int ei){
    if(si>ei){
        return NULL;
    }
    int mid = (si+ei)/2;
    bstnode<int>* root = new bstnode<int>(a[mid]);

    root->left = makeatree(a, si, mid-1);
    root->right = makeatree(a, mid+1, ei);

    return root;
}

int maxi(bstnode<int>* root){
    if(root->right == NULL){
        return root->data;
    }
    return maxi(root->right);
}
int mini(bstnode<int>* root){
    if(root->right == NULL){
        return root->data;
    }
    return mini(root->right);
}

void makesortedlist(bstnode<int>* root, vector<int> &v){
    if(root == NULL){
        return ;
    }
    makesortedlist(root->left, v);
    v.push_back(root->data);
    makesortedlist(root->right, v);

}

void printll(llnode* head){
    llnode* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<endl;
        temp= temp->next;
    }
}

/*pair<llnode, llnode> makesortedlist(bstnode<int>* root){
    if(root == NULL){
        pair<llnode, llnode> output;
        output.first = NULL;
        output.second = NULL;
    }
    pair<llnode, llnode> left = makesortedlist(root->left);
    pair<llnode, llnode> right = makesortedlist(root->right);
    llnode* nn = (root->data);
    left.second -> next = nn;
    nn -> next = right.first;
    pair<llnode, llnode> output;
    output.first = left.first;
    output.second = right.second;

    return output;

}*/

vector<int>* getroottonodepath(bstnode<int>* root, int data){
    if(root == NULL){
        return NULL;
    }
    if(root->data == data){
        vector<int>* output = new vector<int>;
        output->push_back(root->data);
        return output;
    }
    vector<int>* leftoutput = getroottonodepath(root->left, data);
    if(leftoutput!= NULL){
        leftoutput->push_back(root->data);
        return leftoutput;
    }
    vector<int>* rightoutput = getroottonodepath(root->right, data);
    if(rightoutput != NULL){
        rightoutput->push_back(root->data);
        return rightoutput ;
    }else{
        return NULL;
    }
}

vector<int>* getroottonodepathbst(bstnode<int>* root, int data){
    if(root == NULL){
        return NULL;
    }

    if(root->data == data){
        vector<int>* output = new vector<int>;
        output->push_back(root->data);
        return output;
    }
    if(root->data > data){
        vector<int>* leftoutput = getroottonodepathbst(root->left, data);
        if(leftoutput != NULL){
            leftoutput->push_back(root->data);
            return leftoutput;
        }else{
            return NULL;
        }
    }
    if(root->data < data){
        vector<int>* rightoutput = getroottonodepathbst(root->right, data);
        if(rightoutput != NULL){
            rightoutput->push_back(root->data);
            return rightoutput;
        }else{
            return NULL;
        }
    }
    return NULL;
}
// 4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1
// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
// 8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1

int main(){
    int a[7] = {1, 2, 3, 4, 5, 6, 7};
    bstnode<int>* root = makeatree(a,0,6);
    printwise(root);

    bstnode<int>* root1 = takeinput();
    
    vector<int>* v = getroottonodepathbst(root1, 2);
    cout<<endl;
    for(int i=0; i<v->size(); i++){
        cout<<v->at(i)<<" ";
    }
    delete root;
    delete root1;
    delete v;

}