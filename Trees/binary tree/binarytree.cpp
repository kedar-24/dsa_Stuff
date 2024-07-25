#include <iostream>
#include "treeclass.h"
#include <queue>
using namespace std;

void printtree(btnode<int>* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" : ";
    if(root->left){
        cout<<"L"<<root->left->data<<" ";
    }
    if(root->right){
        cout<<"R"<<root->right->data<<" ";
    }
    cout<<endl;
    printtree(root->left);
    printtree(root->right);
}

btnode<int>* bttakeinput(){
    int rootdata;
    cout<<"enter data : "<<endl;
    cin>>rootdata;
    if(rootdata == -1){
        return NULL;
    }
    btnode<int>* root = new btnode<int>(rootdata);
    btnode<int>* leftchild = bttakeinput();
    btnode<int>* rightchild = bttakeinput();
    root->left = leftchild;
    root->right = rightchild;
    return root;
}

btnode<int>* takeinput(){
    int rootdata;
    cout<<"enter root data : "<<endl;
    cin>>rootdata;
    if(rootdata == -1){
        return NULL;
    }

    btnode<int>* root = new btnode<int>(rootdata);

    queue<btnode<int>*> q;
    q.push(root);
    while(!q.empty()){
        btnode<int>* front = q.front();
        q.pop();
        int leftchilddata;
        cout<<"Enter left child data of "<<front->data<<" : ";
        cin>>leftchilddata;
        if(leftchilddata != -1){
            btnode<int>* leftchild = new btnode<int>(leftchilddata);
            front->left = leftchild;
            q.push(leftchild);
        }
        int rightchilddata;
        cout<<"Enter right child data of "<<front->data<<" : ";
        cin>>rightchilddata;
        if(rightchilddata != -1){
            btnode<int>* rightchild = new btnode<int>(rightchilddata);
            front->right = rightchild;
            q.push(rightchild);
        }
    }
    return root;
}

void printwise(btnode<int>* root){
    queue<btnode<int>*> q;
    q.push(root);
    while(!q.empty()){
        btnode<int>* front = q.front();
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

int numberofnodes(btnode<int>* root){
    if(root == NULL){
        return 0;
    }
    return (1 + numberofnodes(root->left) + numberofnodes(root->right));
}

bool searchtree(btnode<int>* root, int k){
    if(root->data == k){
        return true;
    }
    bool ans = false;
    if(root->left){
        ans = ans | searchtree(root->left, k);
    }
    if(root->right){
        ans = ans | searchtree(root->right, k);
    }

    return ans;
}

int heightoftree(btnode<int>* root){
    if(root == NULL){
        return 0;
    }
    return 1 + max(heightoftree(root->left), heightoftree(root->right));
}

void mirror(btnode<int>* root){
    if(root == NULL){
        return;
    }
    mirror(root->left);
    mirror(root->right);
    btnode<int>* temp = root->left;
    root->left = root ->right;
    root->right = temp;

}

void inorder(btnode<int>* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(btnode<int>* root){
    if(root == NULL){
        return;
    }
    preorder(root->left);
    preorder(root->right);
    cout<<root->data<<" ";
}

void postorder(btnode<int>* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    postorder(root->left);
    postorder(root->right);
}

btnode<int>*  buildTreeHelper(int* in, int* pre, int inS, int inE, int preS, int preE){
    if(inS>inE){
        return NULL;
    }

    int rootData = pre[preS];
    int rootindex = -1;
    for(int i = inS; i<=inE; i++){
        if(in[i]==rootData){
            rootindex = i;
            break;
        }
    }
    int lInS = inS;
    int lInE = rootindex -1;
    int lPreS = preS + 1;
    int lPreE = lInS - lInE + lPreS;
    int rInS = rootindex + 1; 
    int rInE = inE;
    int rPreS = lPreE + 1;
    int rPreE = preE;
    btnode<int>* root = new btnode<int>(rootData);
    root->left = buildTreeHelper(in, pre, lInS, lInE, lPreS, lPreE);
    root->right = buildTreeHelper(in, pre, rInS, rInE, rPreS, rPreE);

    return root;
}

btnode<int>* buildTree(int* in, int* pre, int size){
    return buildTreeHelper(in, pre, 0, size-1, 0, size-1);
}

int main(){
    /*btnode<int>* root = new btnode<int>(1);
    btnode<int>* node1 = new btnode<int>(2);
    btnode<int>* node2 = new btnode<int>(3);
    1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
    root->left = node1;
    root->right = node2;
    */
    int in[9]={4,2,5,1,8,6,9,3,7};
    int pre[9]={1,2,4,5,3,6,8,9,7};

    btnode<int>* root = buildTree(in, pre, 9);
    cout<<endl;
    printwise(root);
    /*cout<<endl;
    cout<<"number of nodes : "<<numberofnodes(root)<<endl;
    cout<<searchtree(root,0);
    cout<<"\nHeight : "<<heightoftree(root);
    mirror(root);
    cout<<endl;
    printwise(root);*/
    cout<<endl;
    inorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    postorder(root);
}