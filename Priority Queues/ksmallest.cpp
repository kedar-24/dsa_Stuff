#include <iostream>
#include <queue>
using namespace std;

void kSmallest(int *input, int n, int k){
    priority_queue<int> pq;
    for(int i = 0; i<k; i++){
        pq.push(input[i]);
    }
    for(int i = k; i<n; i++){
        if(pq.top()>input[i]){
            pq.pop();
            pq.push(input[i]);
        }
    }

    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
}
int main(){
    int input[] = {5, 6, 9, 12, 3, 13, 2};
    kSmallest(input, 7, 3);
}