#include <iostream>
using namespace std;
#include "using_ll.cpp"

int main(){
    stack1<char> s1;

    char str[1000];
    cin.getline(str,1000);

    for(int i=0; str[i]!='\0'; i++){
        if(str[i]=='}'){
            while(s1.top()!='{'){
                s1.pop();
            }
            s1.pop();
        }else{
            s1.push(str[i]);
        }
    }

    s1.print();

    if(s1.getSize()%2==0){
        cout<<((s1.getSize())/2)<<endl;
    }else{
        cout<<"-1"<<endl;
    }



}