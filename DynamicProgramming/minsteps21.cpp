#include <iostream>
using namespace std;

int minsteps_2(int n){
    int *arr = new int[n+1];
    arr[1] = 0;
    for(int i=2; i<=n; i++){
        if(i%2 == 0 && i%3 == 0){
            arr[i] = 1 + min(arr[i-1], min(arr[i/2], arr[i/3]));
        }else if(i%2 != 0 && i%3 == 0){
            arr[i] = 1 + min(arr[i-1], arr[i/3]);
        }else if(i%2 == 0 && i%3 != 0){
            arr[i] = 1 + min(arr[i-1], arr[i/2]);
        }else{
            arr[i] = 1 + (arr[i-1]);
        }
    }

    return arr[n];
}

int minsteps(int n){
    if(n<=1){
        return 0;
    }

    int x = minsteps(n-1);
    int y = INT_MAX, z = INT_MAX;
    if(n%2 == 0){
        y = minsteps(n/2);
    }
    if(n%3 == 0){
        z = minsteps(n/3);
    }

    return 1 + min(x, min(y, z));
}

int minstephelper(int n, int* arr){
    if(n<=1){
        return n;
    }

    if(arr[n] != -1){
        return arr[n];
    }
    int x = minstephelper(n-1, arr);
    int y = INT_MAX, z = INT_MAX;
    if(n%2 == 0){
        y = minstephelper(n/2, arr);
    }
    if(n%3 == 0){
        z = minstephelper(n/3, arr);
    }

    int ans = 1 + min(x, min(y, z));

    arr[n] = ans;

    return ans;
}

int minsteps_1(int n){
    int *arr = new int[n+1];
    for(int i = 0; i<=n; i++){
        arr[i] = -1;
    }
    return minstephelper(n, arr);
}

int main(){
    int n;
    cin>>n;
    cout<<minsteps_2(n)<<endl;
}