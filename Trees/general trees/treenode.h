#include <vector>
using namespace std;

template <typename T>
class tree_node{
    public:

    T data;
    vector<tree_node<T>*> children;

    tree_node(T data){
        this->data = data;
    }


};