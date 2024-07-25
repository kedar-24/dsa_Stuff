#include <iostream>
#include <queue>
#include "treenode.h"
using namespace std;

tree_node<int>* takeinput_levwise(){
    int rootdata;
    cout
    
    <<"enter root data : ";
    cin>>rootdata;
    tree_node<int>* root = new tree_node<int>(rootdata);

    queue<tree_node<int>*> pendingnodes;

    pendingnodes.push(root);
    while(pendingnodes.size()!=0){
        tree_node<int>* front = pendingnodes.front();
        pendingnodes.pop();
        int nchild;
        cout<<"enter number of children of "<<front -> data<<endl;
        cin>>nchild;
        for(int i=0; i<nchild; i++){
            int cdata;
            cout<<"enter "<<i<<" th child of "<<front->data<<endl;
            cin>>cdata;
            tree_node<int> * child = new tree_node<int>(cdata);
            front->children.push_back(child);
            pendingnodes.push(child);
        }
    }
    return root;
};

tree_node<int>* takeinput(){
    int rootdata;
    cout<<"enter root data : ";
    cin>>rootdata;
    tree_node<int>* root = new tree_node<int>(rootdata);

    int n;
    cout<<"enter number of children of "<<rootdata<<endl;
    cin>>n;
    for(int i = 0; i<n; i++){
        tree_node<int>* child = takeinput();
        root->children.push_back(child);
    }
    return root;
} 

void print_Tree(tree_node<int>* root){
    if(root == NULL){
        return;
    }

    cout<<root->data<<" : ";
    for(int i=0; i<root->children.size(); i++){
        cout<<root->children[i]->data<<", ";
    }
    cout<<endl;
    for(int i=0; i<root->children.size(); i++){
        print_Tree(root->children[i]);
    }
}

void print_levelwise(tree_node<int>* root){
    if (root==NULL){
        return;
    }
    queue<tree_node<int>*> q;
    q.push(root);
    while (!q.empty()){
        int n = q.size();
        while (n > 0){
            tree_node<int>* p = q.front();
            q.pop();
            cout << p->data<< " ";
            for (int i=0; i<p->children.size(); i++){
                q.push(p->children[i]);
            }
            n--;
        }
        cout<<endl;
    }
}

int numnodes(tree_node<int>* root){
    if(root == NULL){
        return 0;
    }
    int ans = 1;
    for(int i=0; i<root->children.size(); i++){
        ans+= numnodes(root->children[i]);
    }
    return ans; 
}

int sumofnodes(tree_node<int>* root){
    if(root == NULL){
        return 0;
    }
    int ans = root->data;
    for(int i = 0; i<root->children.size(); i++){
        ans+= sumofnodes(root->children[i]);
    }
    return ans;
}

int maxnode(tree_node<int>* root){
    int max = root->data;
    for(int i = 0; i<root->children.size(); i++){
        if(max < maxnode(root->children[i])){
            max = maxnode(root->children[i]);
        }
    }
    return max;
}

/*int findheight(tree_node<int>* root){
    if(root == NULL){
        return 0;
    }
    int height = 1;
    for(int i=0; i<root->children.size(); i++){

    }
}*/
void print_levelk(tree_node<int>* root, int k){
    if(root == NULL){
        return ;
    }
    if(k == 0){
        cout<<root -> data<<" ";
        return;
    }
    for(int i=0; i<root->children.size(); i++){
        print_levelk(root->children[i], k-1);
    }
}

int countleaf(tree_node<int>* root){
    int cnt = 0;
    if(root == NULL){
        return 0;
    }
    if(root->children.size()==0){
        return 1;
    }
    for(int i=0; i<root->children.size(); i++){
        cnt += countleaf(root->children[i]);
    }
    return cnt;
}

void preorder(tree_node<int>* root){
    cout<<root->data<<" ";
    for(int i=0; i<root->children.size(); i++){
        preorder(root->children[i]);
    }
}

void postorder(tree_node<int>* root){
    for(int i=0; i<root->children.size(); i++){
        postorder(root->children[i]);
    }
    cout<<root->data<<" ";
}

void deletetree(tree_node<int>* root){
    for(int i=0; i<root->children.size(); i++){
        deletetree(root->children[i]);
    }
    delete root;
}

bool searchnode(tree_node<int>* root, int k){
    if(root->data == k){
        return true;
    }
    bool ans=false;
    for(int i=0; i<root->children.size(); i++){
        ans=ans | searchnode(root->children[i], k);
        if(ans==true) return ans;
    }

    return ans;
}

int nodegreaterthank(tree_node<int>* root, int k){
    if(root->data > k){
        return 1;
    }
    int grt = 0;
    for(int i=0; i<root->children.size(); i++){
        grt += nodegreaterthank(root->children[i], k);
    }
    return grt;
}
int main(){
    tree_node<int> *root = takeinput_levwise();
    
    /*tree_node<int> * root = new tree_node<int>(1);
    tree_node<int> * node1 = new tree_node<int>(2);
    tree_node<int> * node2 = new tree_node<int>(3);
    root->children.push_back(node1);
    root->children.push_back(node2);
    */
    print_Tree(root);

    /*cout<<numnodes(root)<<endl;
    cout<<sumofnodes(root)<<endl;
    print_levelk(root,2);
    cout<<maxnode(root)<<endl;*/
    cout<<countleaf(root)<<endl;
    preorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    print_levelwise(root);
    cout<<endl;
    cout<<searchnode(root, 41);
    cout<<endl;
    cout<<nodegreaterthank(root, 1);
}
// 1 3 2 3 4 2 5 6 0 0 0 0 