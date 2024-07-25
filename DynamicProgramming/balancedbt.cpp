#include <iostream>
using namespace std;

int balancedBTs(int h){
    if(h <= 1){
        return 1;
    }

    int x = balancedBTs(h-1);
    int y = balancedBTs(h-2);

    int ans = x*x + 2*x*y;

    return ans;
}

int main(){
    int h;
    cin>>h;
    cout<<balancedBTs(h)<<endl;
}