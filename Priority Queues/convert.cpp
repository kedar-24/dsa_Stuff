// covert max priortyQueue ti min priorty Queue;
#include <iostream>
#include <queue>
using namespace std;

int main(){
    priority_queue<int, vector<int>, greater<int> > pq;
    pq.push(16);
    pq.push(167);
    pq.push(1);
    pq.push(12);
    pq.push(98);
    pq.push(34);
    pq.push(21);
    pq.push(14);

    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
}