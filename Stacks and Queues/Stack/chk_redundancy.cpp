#include <iostream>
using namespace std;
#include "using_ll.cpp"


int main(){
    stack1<char> s1;

    char str[50];
    cin.getline(str,50);
    int i=0;int c=0;
    while(str[i] != '\0'){
        if(str[i]==')'){
            c = 0;
            while(s1.top()!='('){
                c++;
                s1.pop();
            }
            s1.pop();
        }else{
            s1.push(str[i]);
        }
        i++;
    }

    if(c!=0){
        cout<<"false"<<endl;
    }else{
        cout<<"true"<<endl;
    }

}