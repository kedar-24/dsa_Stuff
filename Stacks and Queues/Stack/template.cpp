template <typename T>

class Pair{
    T x;
    T y;

    public:

    void setX(T x){
        this->x = x;
    }

    T getX(){
        return x;
    }

    void setY(T y){
        this->y = y;
    }

    T getY(){
        return y;
    }

};

#include <iostream>
using namespace std;

int main(){

    Pair<Pair<int,int>,int> p3;     //triplet
    Pair<int> p1;

    p1.setX(10);
    p1.setY(20);

    cout<<p1.getX()<<" "<<p1.getX()<<endl;

    Pair<double> p2;

    p2.setX(10.9);
    p2.setY(11.9);

    cout<<p2.getX()<<" "<<p2.getX()<<endl;
}