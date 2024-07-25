class trinode{
    public:

    char data;
    trinode** children;
    bool isTerminal;

    trinode(char data){
        this -> data = data;
        children = new trinode*[26];
        for(int i=0; i<26; i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }
};