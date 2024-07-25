#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

vector<int> removeDuplicate(int *a, int size){
    vector<int> output;
    unordered_map<int, bool> seen;
    for(int i=0; i<size; i++){
        if(seen.count(a[i])>0){
            continue;
        }
        seen[a[i]] = true;
        output.push_back(a[i]);
    }
    return output;
}

int main(){
    unordered_map<string, int> ourmap;
    pair<string, int> p("abc", 1);

    ourmap.insert(p);
    ourmap["def"] = 2;

    cout<<ourmap["abc"]<<endl;
    cout<<ourmap.at("abc")<<endl;
    //cout<<ourmap.at("ghi")<<endl;
    cout<<"size : "<<ourmap.size()<<endl;
    cout<<ourmap["ghi"]<<endl;
    cout<<"size : "<<ourmap.size()<<endl;

    if(ourmap.count("ghi")>0){
        cout<<"ghi is present."<<endl;
    }

    ourmap.erase("ghi");
    cout<<"size : "<<ourmap.size()<<endl;

    if(ourmap.count("ghi")>0){
        cout<<" ghi is present."<<endl;
    }

    int a[] = {1,2,3,1,2,5,7,6,3,2,1,4};
    vector<int> v = removeDuplicate(a, 12);

    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    vector<int>::iterator it = v.begin();
    while(it != v.end()){
        cout<<*it<<" ";
        it++;
    }
}