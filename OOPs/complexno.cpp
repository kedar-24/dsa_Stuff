#include <iostream>
using namespace std;

class complex_num{
    int real;
    int img;

    public:

    complex_num(int real, int img){
        this -> real = real;
        this -> img = img;
    }

    void display(){
        cout<<real<<" + ("<<img<<")i"<<endl;
    }

    void add (complex_num const &c2){
        this -> real += c2.real;
        this -> img += c2.img;
    }

    void subtract (complex_num const &c2){
        this -> real -= c2.real;
        this -> img -= c2.img;
    }

    void multiply(complex_num const &c2){
        int r = (real * c2.real) - (img * c2.img);
        int i = (real * c2.img) + (img * c2.real);

        real = r;
        img = i;
    }
};

int main(){

    complex_num c1(2,3);
    complex_num * c2 = new complex_num(4,1);

    c2->add(c1);

    c2->display();
}