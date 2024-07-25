#include <iostream>
using namespace std;

class fraction{
    private:

    int num;
    int deno;
    
    public:

    fraction(int num,int deno){
        this -> num = num;
        this -> deno = deno;
    }

    void display(){
        cout<<this->num<<"/"<<this->deno<<endl;
    }

    void simplify(){
        int gcd = 1;
        int j = min(this->num, this->deno);
        for(int i=1;i<=j;i++){
            if((this->num % i == 0) && (this->deno % i == 0)){
                gcd = i;
            }
        }
        this->num = this-> num/gcd;
        this->deno = this-> deno/gcd;

    }
    fraction add(fraction const &f2){
        int lcm = this->deno * (f2.deno);
        int x = (lcm/this->deno);
        int y = (lcm/f2.deno);

        int n = (x*(this->num)) + (y*(f2.num));

        //num=n;
        //deno=lcm;
        fraction fN(n,lcm);
        fN.simplify();
        return fN;
    }

    fraction operator+(fraction const &f2){
        int lcm = this->deno * (f2.deno);
        int x = (lcm/this->deno);
        int y = (lcm/f2.deno);

        int n = (x*(this->num)) + (y*(f2.num));

        //num=n;
        //deno=lcm;
        fraction fN(n,lcm);
        fN.simplify();
        return fN;
    }

    fraction operator* (fraction const &f2){
        int n = this -> num * f2.num;
        int d = this -> deno* f2.deno;
        fraction fN(n,d);
        fN.simplify();
        return fN; 
    }
    void multiply(fraction const &f2){
        this->num *= f2.num;
        this->deno *= f2.deno;

        simplify();

    }

    bool operator==(fraction &f2){
        simplify();
        f2.simplify();
        return (this->num == f2.num && this->deno == f2.deno);
    }
    //pre increament
    fraction operator++(){
        num = num + deno;
        simplify();
        return *this;
    }
};

int main(){

    fraction f1(2,3);
    fraction * f2 = new fraction(3,5);
    
    f1.display();
    ++f1;
    f1.display();
    //f1++;
    f1.display();


    
    /*f1.display();
    f2->display();

    fraction f3 = f1.add(*f2);
    fraction f4 = f1 + (*f2);
    f3.display();
    f4.display();

    fraction f5 = f1 * (*f2);
    f5.display();

    cout<<(f1==(*f2))<<endl;
    */

}