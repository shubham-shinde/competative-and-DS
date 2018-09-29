#include<stdlib.h>
#include<math.h>
#include<iostream>
using namespace std;

class Trinales {
    public: int a, b, c;
    public: 
    void assingValue(int f, int g, int h) {
        a=f;
        b=g;
        c=h;
        return;
    }
    void printValue() {
        cout << a << b << c;
    }
    float printArea() {
        float s = (a+b+c)/2;
        return pow(s*(s-a)*(s-b)*(s-b), 0.5);
    }
};

int main() {
    Trinales obj;
    obj.assingValue(4, 4 ,6);
    obj.printValue();
    cout << obj.printArea();
    return 0;
}