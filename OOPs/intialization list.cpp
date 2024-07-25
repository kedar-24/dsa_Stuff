#include <iostream>
using namespace std;

class student{
    int age;
    const int roll_number;
    int &x;
    student (int r, int age) : roll_number(r), age(age), x(this->age){
        //this->roll_number = r;
    }
};