#include <iostream>

using namespace std;
const int DivideByZero = 1;

int main(){
    try {
        int number = 12;
        int denom = 0;
        
        if (denom == 0) {
            throw DivideByZero;
        }
        
    }
    catch (int e){
        if (e == DivideByZero){
            cout << "cant divide by zero " << endl;
        }
    }
    return 0;
}