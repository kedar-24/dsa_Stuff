#include <iostream>
#include <queue>
#include "bst.h"
#include "class.h"
using namespace std;

// 4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1
int main(){
    BST b1;
    b1.insert(10);
    b1.insert(5);
    b1.insert(20);
    b1.insert(7);
    b1.insert(3);
    b1.insert(15);

    b1.printTree();

    
}