#include <iostream>
#include <climits>
using namespace std;

class stack1{
    private:
        int* a ;
        int nextindex;
        int capacity;
    public:
        stack1(){
            a = new int[4];
            nextindex = 0;
            capacity = 4;
        }
        /*stack1(int totalsize){
            a = new int[totalsize];
            nextindex = 0;
            capacity = totalsize;
        }*/

        int size(){
            return nextindex;
        }

        int top(){
            if(isEmpty()){
                return 0;
            }
            return a[nextindex-1];
        }

        bool isEmpty(){
            return (nextindex == 0);
            //if(size == 0) ? return true : return false;
        }

        void push(int ele){
            if(nextindex == capacity){
                /*cout<<"Stack Overflow "<<endl;
                return;*/
                int* newa = new int[(2 * capacity)];
                for(int i = 0; i< capacity; i++){
                    newa[i] = a[i];
                }
                capacity*=2;
                delete []a;
                a = newa; 
            }
            a[nextindex] = ele;
            nextindex++;
        }

        int pop(){
            if(isEmpty()){
                cout<<"Stack Underflow."<<endl;
                return INT_MIN;
            }
            nextindex--;
            return a[nextindex];
        }
};