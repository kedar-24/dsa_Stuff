#include <iostream>
using namespace std;

class polynomial{
    int * degcoeff;
    int capacity;

    public:

    polynomial(){
        this -> capacity = 10;
        this -> degcoeff = new int[10];
        for(int i=0; i<10; i++){
            degcoeff[i]=0;
        }
    }

    polynomial(polynomial const &p1){
        this -> capacity = p1.capacity; 
        this -> degcoeff = new int [p1.capacity];
        for(int i=0 ; i<p1.capacity; i++){
            this -> degcoeff[i] = p1.degcoeff[i];
        }
    }

    void setCoeff(int deg, int val){
        if(deg>=capacity){
            int size = deg + 1;
            int *newarr = new int[size];
            for(int i=0 ; i<capacity; i++){ newarr[i]= degcoeff[i];}
            for(int i=capacity; i<size; i++){ newarr[i]= 0;}
            delete[] this->degcoeff;
            this -> degcoeff = newarr;
            this -> capacity = size;
        }
        this->degcoeff[deg] = val;
    }

    polynomial operator+(polynomial const &p1){
        polynomial na;
        na.capacity = max(p1.capacity,capacity);
        na.degcoeff = new int[na.capacity];
        if(capacity<p1.capacity){
            int i;
            for(i=0; i<capacity; i++){
                na.degcoeff[i] = p1.degcoeff[i] + this->degcoeff[i];
            }
            for(;i<p1.capacity;i++){
                na.degcoeff[i] = p1.degcoeff[i];
            }    
        }else{
            int i;
            for(i=0; i<p1.capacity; i++){
                na.degcoeff[i] = p1.degcoeff[i] + this->degcoeff[i];
            }
            for(;i<capacity;i++){
                na.degcoeff[i] = this->degcoeff[i];
            }
        }
        return na;
    }

    polynomial operator-(polynomial const &p1){
        polynomial na;
        na.capacity = max(p1.capacity,capacity);
        na.degcoeff = new int[na.capacity];
        if(capacity<p1.capacity){
            int i;
            for(i=0; i<capacity; i++){
                na.degcoeff[i] = this->degcoeff[i] - p1.degcoeff[i];
            }
            for(;i<p1.capacity;i++){
                na.degcoeff[i] = -(p1.degcoeff[i]);
            }    
        }else{
            int i;
            for(i=0; i<p1.capacity; i++){
                na.degcoeff[i] = this->degcoeff[i] - p1.degcoeff[i];
            }
            for(;i<capacity;i++){
                na.degcoeff[i] = this->degcoeff[i];
            }
        }
        return na;
    }

    polynomial operator=(polynomial const &p1){
        this-> capacity = p1.capacity;
        this-> degcoeff = new int[capacity];
        for(int i=0; i<capacity; i++){
            this -> degcoeff[i]= p1.degcoeff[i];
        }
        return *this;
    }

    polynomial operator*(polynomial const &p1){
        polynomial na;
        na.capacity = this -> capacity + p1.capacity;
        na.degcoeff = new int[na.capacity];
        for(int i=0; i<na.capacity; i++){
            na.degcoeff[i]=0;
        }
        for(int i=0; i<capacity; i++){
            for(int j=0; j<p1.capacity; j++){
                na.degcoeff[i+j]+= this->degcoeff[i]*p1.degcoeff[j];
            }
        }
        return na;
    }

    void print(){
        for(int i=0; i<this->capacity; i++){
            if(this->degcoeff[i]!=0){
                cout<<this->degcoeff[i]<<"x"<<i<<" ";
            }
        }
        cout<<endl;
    }
};

int main(){

    int cnt1, cnt2, choice;
    cin>>cnt1;

    int * deg1 = new int[cnt1];
    int * coef1 = new int[cnt1];

    for(int i=0; i<cnt1; i++){
        cin>>deg1[i];
    }
    for(int i=0; i<cnt1; i++){
        cin>>coef1[i];
    }

    polynomial p1;
    for(int i=0; i<cnt1; i++){
        p1.setCoeff(deg1[i], coef1[i]);
    }

    cin>>cnt2;

    int * deg2 = new int[cnt2];
    int * coef2 = new int[cnt2];

    for(int i=0; i<cnt2; i++){
        cin>>deg2[i];
    }
    for(int i=0; i<cnt2; i++){
        cin>>coef2[i];
    }

    polynomial p2;
    for(int i=0; i<cnt2; i++){
        p2.setCoeff(deg2[i], coef2[i]);
    }

    cout<<"Enter ur choice : \n1.add \n2.subtract \n3.multiply \n4.copy constructor \n5.copy operator \n";
    cin>>choice;
        switch(choice){
            case 1:
                //add
                {polynomial r1 = p1 + p2;
                r1.print();}
            break;

            case 2:
                //subtract
                {polynomial r2 = p1 - p2;
                r2.print();}
            break;

            case 3:
                //multiply
                {polynomial r3 = p1 * p2;
                r3.print();}
            break;
        
            case 4:
                //copy constructor.
                {polynomial c1(p1);
                c1.print();}
            break;
        
            case 5:
                //copy operator.
                {polynomial c2;
                c2 = p1;
                c2.print();}
            break;
            }
    
}