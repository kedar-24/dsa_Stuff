#include <iostream>
using namespace std;
#include "Queueusingll.cpp"

void print(queue<int> p){
    queue<int> g = p;
    while(!g.isEmpty()){
        cout<<g.dequeue()<<endl;
    }
}
void reverse_queue(queue<int> &q1){
    if(q1.isEmpty()){
        return;
    }

    int fr = q1.dequeue();

    reverse_queue(q1);

    q1.enqueue(fr);
}

int main(){
    queue<int> q1;

    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    q1.enqueue(40);
    q1.enqueue(50);


    reverse_queue(q1);
    
    print(q1);


}