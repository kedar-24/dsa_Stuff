#include <iostream>
using namespace std;

int fibo_3(int n){
    int *arr = new int[n+1];

    arr[0] = 0;
    arr[1] = 1;

    for(int i=2; i<=n; i++){
        arr[i] = arr[i-1] + arr[i-2];
    }

    return arr[n];
}
int fibo(int n){
    if(n<=1){
        return n;
    }
    int a = n-1;
    int b = n-2;
    return a+b;
}
int fibohelper(int n, int* arr){
    if(n <= 1){
        return n;
    }

    if(arr[n]!= -1){
        return arr[n];
    }

    int a = fibohelper(n-1, arr);
    int b = fibohelper(n-2, arr);

    arr[n] = a + b;

    return arr[n];
}

int fibo_2(int n){
    int *arr = new int[n+1];
    for(int i=0; i<=n; i++){
        arr[i] = -1;    
    }
    return fibohelper(n, arr);
}

int main(){
    int n;
    cin>>n;
    cout<<fibo_2(n)<<endl;
}