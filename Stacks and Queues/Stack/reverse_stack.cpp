#include <iostream>
using namespace std;
#include "stack.cpp"

void reverse(stack1 &s1, stack1 &s2){
    if(s1.isEmpty()){
        return;
    }
    int a = s1.pop();

    reverse(s1,s2);

    while(s1.isEmpty()){
        s2.push(s1.pop());
    }

    s1.push(a);
    
    while(s2.isEmpty()){
        s1.push(s2.pop());
    }
    

}

int main(){
    stack1 s1,s2;

    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);
    s1.push(60);

    reverse(s1,s2);

    cout<<s1.pop()<<" ";
    cout<<s1.pop()<<" ";
    cout<<s1.pop()<<" ";
    cout<<s1.pop()<<" ";
    cout<<s1.pop()<<" ";
    cout<<s1.pop()<<" ";
}