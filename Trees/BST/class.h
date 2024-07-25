#include <iostream>
using namespace std;
template <typename T>
class bstnode{
    public: 

    T data;
    bstnode<T>* left;
    bstnode<T>* right;

    bstnode(T data){
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~bstnode(){
        delete left;
        delete right;
    }
};