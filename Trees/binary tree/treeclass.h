template <typename T>
class btnode{
    public:

    T data;
    btnode<T>* right;
    btnode<T>* left;

    btnode(int data){
        this->data = data;
        right = NULL;
        left = NULL;
    }

    ~btnode(){
        delete left;
        delete right;
    }
};