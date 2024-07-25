#include <iostream>
using namespace std;

int staircase(int n){
    if( n==0 ){
        return 1;
    }
    else if(n<0){
        return 0;
    }else{
        return staircase(n-3) + staircase(n-2) + staircase(n-1);
    }
}

int staircase_1(int n){
    int *arr = new int[n+1];
    arr[0] = 1;
    arr[1] = 1;
    arr[2] = 2;
    for(int i=3; i<=n; i++){
            arr[i] = arr[i-1] + arr[i-2] + arr[i-3];
        }
    return arr[n];
}
int main(){
    int n;
    cin>>n;
    cout<<staircase_1(n)<<endl;
}