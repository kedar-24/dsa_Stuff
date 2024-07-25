#include <iostream>
using namespace std;
template <typename T>
class queue{
    T *arr;
    int fi;
    int ni;
    int size;
    int capacity;

    public:

    queue(int capacity){
        arr = new T[capacity];
        fi = -1;
        ni = 0;
        size = 0;
        this->capacity = capacity;
    }

    int getSize(){
        return size;
    }

    bool isEmpty(){
        return ( size == 0);
    }

    void enqueue(T element){
        if(size == capacity){
            T *narr = new T[2*capacity];    //dynamic shit
            int j=0;            
            for(int i=fi; i<capacity; i++,j++){
                narr[j] = arr[i];
            }
            for(int i=0; i<fi; i++){
                narr[j] = arr[i];
            }
            delete [] arr;
            arr = narr;
            fi = 0;
            ni = capacity;
            capacity*=2;
            //cout<<"Queue is FULL."<<endl;       //normal shit
            //return;
        }
        arr[ni] = element;
        ni = (ni+1)%capacity;
        if(fi == -1){
            fi = 0;
        }
        size++;
    }

    T front(){
        if(isEmpty()){
            cout<<"Queue is Empty."<<endl;
            return 0;
        }
        return arr[fi];
    }

    T dequeue(){
        if(isEmpty()){                          
            cout<<"Queue is Empty."<<endl;              
            return 0;
        }
        T ans = arr[fi];
        fi = (fi+1)%capacity;
        size--;
        if(size == 0){
            fi = -1;
            ni = 0;
        }
        return ans;
    }
};