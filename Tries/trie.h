#include "trinode.h"
#include <string>
using namespace std;
class Trie{
    trinode* root;
    public:

    Trie(){
        root = new trinode('\0');
    }

    void insertWord(trinode* root, string word){
        if(word.size() == 0){
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        trinode* child;
        if(root->children[index] != NULL){
            child = root->children[index];
        }else{
            child = new trinode(word[0]);
            root->children[index] = child;
        }

        insertWord(child, word.substr(1));
    }

    void insertword(string word){
        insertWord(root, word);
    }

    bool search(trinode* root, string word){
        if(word.size() == 0){
            if(root->isTerminal){
                return true;
            }
            return false;
        }

        int index = word[0] - 'a';
        trinode* child;
        if(root->children[index] != NULL){
            child = root->children[index];
        }else{
            return false;
        }

        return search(child, word.substr(1));
    }

    bool searchWord(string word){
        return search(root, word);
    }

    void remove(trinode* root, string word){
        if(word.size() == 0){
            root->isTerminal = false;
            return;
        }

        int index = word[0] - 'a';
        trinode* child;
        if(root->children[index] != NULL){
            child = root->children[index];
        }else{
            return;
        }

        remove(child, word.substr(1));

        // removing child node if it is useless.
        if(child->isTerminal == false){
            for(int i=0; i<26; i++){
                if(child->children[i] != NULL){
                    return;
                }
            }
            delete child;
            root->children[index] = NULL;
        }
    }

    void removeword(string word){
        remove(root, word);
    }
};