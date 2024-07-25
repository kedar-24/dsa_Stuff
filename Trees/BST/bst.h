#include <iostream>
using namespace std;
#include "class.h"
#include <queue>
//template <typename T>
class BST{
    bstnode<int>* root;

    public:

    BST(){
        root = NULL;
    }

    ~BST(){
        delete root;
    }
    bstnode<int>* giveroot(){
        return root;
    }
    

    private :

    void printTree(bstnode<int>* node){
        if(node == NULL){
            return;
        }
        cout<<node->data<<" : ";
        if(node->left){
            cout<<"L"<<node->left->data<<" ";
        }
        if(node->right){
            cout<<"R"<<node->right->data<<" ";
        }
        cout<<endl;
        printTree(node->left);
        printTree(node->right);
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

    bstnode<int>* deletehelper(bstnode<int>* node, int data){
        if(node == NULL){
            return NULL;
        }
        if(node->data < data){
            node->right = deletehelper(node->right, data);
            return node;
        }
        else if(node->data > data){
            node->left = deletehelper(node->left, data);
            return node;
        }
        if(node->data == data){
            if(node->left == NULL && node->right == NULL){
                delete node;
                return NULL;
            }
            else if(node->right == NULL){
                bstnode<int>* output = node->left;
                node->left = NULL;
                delete node;
                return output;
            }
            else if(node->left == NULL){
                bstnode<int>* output = node->right;
                node->right = NULL;
                delete node;
                return output;
            }
            if(node->left != NULL && node->right != NULL){
                node->data = maxi(node->left);
                node->left = deletehelper(node->left, node->data);
                return node;
            }
        }
        
        return node;
    }

    bstnode<int>* inserthelper(bstnode<int>* node, int data){
        if(node == NULL){
            bstnode<int>* output = new bstnode<int>(data);
            return output;
        }
        if(data < node->data){
            node->left = inserthelper(root->left, data);
        }else{
            node->right = inserthelper(node->right, data);
        }
        return node;
    }

    bool helperdata(int data, bstnode<int>* node){
        if(node == NULL){
            return false;
        }
        if(node->data == data){
            return true;
        }else if(node->data > data){
            return helperdata(data, node->left);
        }else{
            return helperdata(data, node->right);
        }
    }
    public:

    bool hasData(int data){
        return helperdata(data, root);
    }
    void insert(int data){
        this->root = inserthelper(this->root, data);
    }

    void deletedata(int data){
        root = deletehelper(root, data);
    }
    
    void printTree(){
        printTree(root);
    }
};