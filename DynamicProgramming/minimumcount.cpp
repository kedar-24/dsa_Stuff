#include <iostream>
#include <cmath>
using namespace std;

int mincount(int n){
    if(sqrt(n) - floor(sqrt(n)) == 0){
        return 1;
    }
    if(n<=3){
        return n;
    }
    int ans = n;
    for(int i=1; i<=sqrt(n); i++){
        int temp  = i*i;
        ans = min(ans, 1 + mincount(n-temp));
    }

    return ans;
}
int main(){
    int n;
    cin>>n;
    cout<<mincount(n)<<endl;
}