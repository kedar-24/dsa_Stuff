#include <iostream>
#include "trie.h"
using namespace std;

int main(){
    Trie t;
    t.insertword("and");
    t.insertword("are");
    t.insertword("dot");

    cout<<t.searchWord("and")<<endl;

    t.removeword("and");
    cout<<t.searchWord("and")<<endl;
}