#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> v;

    for(int i=0; i<100; i++){
        cout<<"capacity : "<<v.capacity()<<endl;
        cout<<"size : "<<v.size()<<endl;
        v.push_back(i+1);
    }

    v[1] = 100;
    v.push_back(23);
    v.push_back(27);

    for(int i =0 ; i<v.size(); i++){
        cout<<v.at(i)<<endl;
    }
}