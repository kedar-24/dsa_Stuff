#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
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

bstnode<int>* duplicate(bstnode<int>* root){
    if(root == NULL){
        return NULL;
    }

    bstnode<int>* dup = new bstnode<int>(root->data);
    bstnode<int>* temp = root->left;
    duplicate(root->left);
    duplicate(root->right);
    dup->left = temp;
    root->left = dup;

    return root;
}

bool find(bstnode<int>* root, int n){
    if(root->data == n){
        return true;
    }
    bool ans = false;
    if(root->left){
        ans = ans | find(root->left, n);
    }
    if(root->right){
        ans = ans | find(root->right, n);
    }

    return ans;
}

void preorder(bstnode<int>* root, vector<int> &v){
    if(root == NULL){
        return;
    }
    v.push_back(root->data);
    preorder(root->left, v);
    preorder(root->right, v);
}

void pairSum(bstnode<int>* root, int s){
    vector<int> v;
    preorder(root,v);
    sort(v.begin(), v.end());
    for(int i=0, j=v.size()-1; j>i; ){
        if(v[i]+v[j] == s){
            cout<<"["<<v[i]<<","<<v[j]<<"] ";
            i++;
            j--;
        }
        if(v[i]+v[j]>s){
            j--;
        }
        if(v[i]+v[j]<s){
            i++;
        }

    }
}

bstnode<int>* LCA(bstnode<int>* root, int n1, int n2){
    if(root == NULL){
        return NULL;
    }
    if(root->data == n1 || root->data == n2){
        return root;
    }

    bstnode<int>* lca_l = LCA(root->left, n1, n2);
    bstnode<int>* lca_r = LCA(root->right, n1, n2);

    if(lca_l != NULL && lca_r !=NULL){
        return root;
    }

    if(lca_l != NULL){
        return lca_l;
    }else if(lca_r != NULL){
        return lca_r;
    }else{
        return NULL;
    }
}



bstnode<int>* LCAbst(bstnode<int>* root, int n1, int n2){
    if(root == NULL){
        return NULL;
    }

    if(root->data > n1 && root->data > n2){
        return (LCAbst(root->left, n1, n2));
    }
    if(root->data < n1 && root->data < n1){
        return LCAbst(root->right, n1, n2);
    }

    return root;
}

int leastcommonancestor(bstnode<int>* root, int n1, int n2){
    if(LCAbst(root,n1,n2)){
        return (LCAbst(root,n1,n2)->data);
    }else{
        return -1;
    }
}
// 10 7 15 2 8 12 25 -1 -1 -1 -1 -1 -1 -1 -1
// 6 4 8 3 7 2 1 -1 -1 -1 -1 -1 5 -1 -1 -1 -1 
// 1 2 3 4 5 -1 7 -1 -1 6 -1 8 9 -1 -1 -1 -1 -1 -1 
// 8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
int main(){
    bstnode<int>* root = takeinput();

    cout<<endl;
    printwise(root);
    cout<<endl;
    //duplicate(root);
    //printwise(root);
    vector<int> v;
    preorder(root, v);
    /*sort(v.begin(), v.end());
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }*/
    pairSum(root, 9);

    cout<<endl;
    cout<<leastcommonancestor(root,12,78)<<endl;
    delete root;
}