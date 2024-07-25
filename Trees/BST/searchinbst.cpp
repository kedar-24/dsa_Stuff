#include <iostream>
#include <queue>
#include "class.h"
using namespace std;

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

bstnode<int>* searchbst(bstnode<int>* root, int k){
    if(root->data == k){
        return root;
    }
    if(k>root->data){
        return searchbst(root->right, k);
    }
    return searchbst(root->left, k);
}

void inrange(bstnode<int>* root, int k1, int k2){
    if(root == NULL){
        return;
    }
    inrange(root->left, k1, k2);

    if(k1<= root->data && k2>= root->data){
        cout<<root->data<<" ";
    }

    inrange(root->right, k1, k2);
}

int maxi(bstnode<int>* root){
    if(root == NULL){
        return INT_MIN;
    }
    return max(root->data, max(maxi(root->right), maxi(root->left)));
}

int mini(bstnode<int>* root){
    if(root == NULL){
        return INT_MAX;
    }
    return min(root->data, min(mini(root->right), mini(root->left)));
}

bool isBST1(bstnode<int>* root){
    if(root == NULL){
        return true;
    }
    int leftmax = maxi(root->left);
    int rightmin = mini(root->right);
    bool output = (root->data > leftmax) && (root->data < rightmin) && (isBST1(root->left)) && (isBST1(root->right));
    return output;
}

class IsBSTreturn{
    public:
    bool isbst;
    int maximum;
    int minimum;
};

IsBSTreturn isBST2(bstnode<int>* root){
    if(root == NULL){
        IsBSTreturn output;
        output.isbst = true;
        output.maximum = INT_MIN;
        output.minimum = INT_MAX;
        return output;
    }
    IsBSTreturn leftoutput = isBST2(root -> left);
    IsBSTreturn rightoutput = isBST2(root -> right);
    int minimum = min(root->data, min(leftoutput.minimum, rightoutput.minimum));
    int maximum = max(root->data, max(leftoutput.maximum, rightoutput.maximum));
    bool isbstfinal = (root->data > leftoutput.maximum) && (root->data < rightoutput.minimum) && leftoutput.isbst && rightoutput.isbst;
    IsBSTreturn output;
    output.isbst = isbstfinal;
    output.maximum = maximum;
    output.minimum = minimum;
    return output;
}

bool isBST3(bstnode<int>* root, int min = INT_MIN, int max = INT_MAX){
    if(root == NULL){
        return true;
    }
    if(root->data < min || root->data >max){
        return false;
    }
    bool islok = isBST3(root->left, min, root->data-1);
    bool isrok = isBST3(root->right, root->data, max);
    return islok && isrok;
}
// 8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
// 4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1 
// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1 

int main(){
    bstnode<int>* root = takeinput();
    cout<<endl;
    printwise(root);
    /*int n;
    cin>>n;
    if(searchbst(root,n)== NULL){
        cout<<"False."<<endl;
    }else{
        cout<<"True."<<endl;
    }*/
    inrange(root, 6, 10);
    cout<<"\nis a BST"<<isBST3(root)<<endl;
    delete root;
}