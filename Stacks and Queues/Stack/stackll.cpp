#include <iostream>
using namespace std;
#include "using_ll.cpp"

int main(){
    stack1<char> s1;
    char c;
    char n[50];
    cin.getline(n,50);

    for(int i = 0; i<49; i++){
        if(n[i] == '(' || n[i] == '[' || n[i] == '{'){
            s1.push(n[i]);
        }
        if(n[i] == ')'){
            if(s1.top() != '('){
                break;
            }else{
                s1.pop();
            }
        }else if(n[i] == ']'){
            if(s1.top() != '['){
                break;
            }else{
                s1.pop();
            }
        }else if(n[i] == '}'){
            if(s1.top() != '{'){
                break;
            }else{
                s1.pop();
            }
        }
    }
    //s1.print();

    if(s1.isEmpty()){
        cout<<"balanced paranthesis."<<endl;
    }else{
        cout<<"unbalanced."<<endl;
    }

    /*s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);
    s1.push(60);
    s1.push(70);

    cout<<s1.top()<<endl;

    cout<<s1.pop()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.pop()<<endl;
    */

}