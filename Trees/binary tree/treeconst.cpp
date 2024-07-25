#include <iostream>
#include <queue>
#include "treeclass.h"
using namespace std;

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

void inorder(btnode<int>* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void Postorder(btnode<int>* root){
    if(root == NULL){
        return;
    }
    Postorder(root->left);
    Postorder(root->right);
    cout<<root->data<<" ";
}

void preorder(btnode<int>* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
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
    int lPreE = lInE - lInS + lPreS;
    int rPreS = lPreE + 1;
    int rPreE = preE;
    int rInS = rootindex + 1; 
    int rInE = inE;

    btnode<int>* root = new btnode<int>(rootData);
    root->left = buildTreeHelper(in, pre, lInS, lInE, lPreS, lPreE);
    root->right = buildTreeHelper(in, pre, rInS, rInE, rPreS, rPreE);

    return root;
}

btnode<int>* buildTree(int* in, int* pre, int size){
    return buildTreeHelper(in, pre, 0, size-1, 0, size-1);
}

btnode<int>*  postbuildTreeHelper(int* in, int* post, int inS, int inE, int postS, int postE){
    if(inS>inE){
        return NULL;
    }

    int rootData = post[postE];
    int rootindex = -1;
    for(int i = inS; i<=inE; i++){
        if(in[i]==rootData){
            rootindex = i;
            break;
        }
    }
    int lInS = inS;
    int lInE = rootindex - 1;
    int lPostS = postS;
    int lPostE = lInE - lInS + lPostS;
    int rPostS = lPostE + 1;
    int rPostE = postE -1;
    int rInS = rootindex + 1; 
    int rInE = inE;

    btnode<int>* root = new btnode<int>(rootData);
    root->left = postbuildTreeHelper(in, post, lInS, lInE, lPostS, lPostE);
    root->right = postbuildTreeHelper(in, post, rInS, rInE, rPostS,rPostE);

    return root;
}

btnode<int>* postbuildTree(int* in, int* post, int size){
    return postbuildTreeHelper(in, post, 0, size-1, 0, size-1);
}

int heightoftree(btnode<int>* root){
    if(root == NULL){
        return 0;
    }
    return 1 + max(heightoftree(root->left), heightoftree(root->right));
}

int diameter(btnode<int>* root){
    if(root == NULL){
        return 0;
    }

    int o1 = heightoftree(root->left) + heightoftree(root->right);
    int o2 = diameter(root->right);
    int o3 = diameter(root->left);

    return max(o1,max(o2,o3));
}

pair<int, int> diameterHeight(btnode<int>* root){
    if(root == NULL){
        pair<int,int> p;
        p.first=0;
        p.second=0;
        return p;
    }
    pair<int,int> leftans = diameterHeight(root->left);
    pair<int,int> rightans = diameterHeight(root->right);
    int Lh = leftans.second;
    int Ld = leftans.first;
    int Rh = rightans.second;
    int Rd = rightans.first;

    int height = 1 + max(Lh, Rh);
    int diameter = max(Lh + Rh, max(Ld, Rd));
    pair<int,int> p;
    p.first = diameter;
    p.second = height;
    return p;
}

int diameterB(btnode<int>* root){
    return diameterHeight(root).first;
}

int Max(btnode<int>* root){
    if(root == NULL){
        return INT_MIN;
    }

    int op1 = root->data;
    int op2 = Max(root->left);
    int op3 = Max(root->right);

    return max(op1,max(op2,op3));
}

int Min(btnode<int>* root){
    if(root == NULL){
        return INT_MAX;
    }

    int op1 = root->data;
    int op2 = Min(root->left);
    int op3 = Min(root->right);

    return min(op1,min(op2,op3));
}

int sumofall(btnode<int>* root){
    if(root == NULL){
        return 0;
    }
    return (root->data + sumofall(root->left) + sumofall(root->right));
}

bool balanced(btnode<int>* root){
    int b = abs(heightoftree(root->left) - heightoftree(root->right));
    if(b<=1){
        return true;
    }else{
        return false;
    }
}

btnode<int>* deleteleaf(btnode<int>* root){
    if(root == NULL){
        return NULL;
    }

    if(root->left == NULL && root->right == NULL){
        delete root;
        return NULL;
    }
    root->left = deleteleaf(root->left);
    root->right = deleteleaf(root->right);


    return root;
}

int main(){
    int in[]={4,2,5,1,8,6,9,3,7};
    int pre[]={1,2,4,5,3,6,8,9,7};
    int post[]={4,5,2,8,9,6,7,3,1};

    btnode<int>* root1 = takeinput();

    /*cout<<endl;
    printwise(root1);
    cout<<endl;
    Postorder(root1);
    cout<<endl;
    preorder(root1);
    cout<<endl<<"diameter : "<<diameterB(root1);
    cout<<endl<<"Max : "<<Max(root1);
    cout<<endl<<"Min : "<<Min(root1);
    cout<<endl<<"Sum of Nodes : "<<sumofall(root1);
    if(balanced(root1)){
        cout<<"\nTrue"<<endl;
    }else{
        cout<<"\nFalse"<<endl;
    }
    */
    cout<<endl;
    printwise(root1);
    deleteleaf(root1);
    cout<<endl;
    printwise(root1);
}