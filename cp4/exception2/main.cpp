#include <iostream>
#include <stdexcept>

using namespace std;
class DivideByZero : public runtime_error 
{
    public:
        DivideByZero() : 
            runtime_error("Divide by zero execcption"){};
};
     
double quotient(double number , double denom){
    if (denom == 0){
        throw DivideByZero();
    }
    else {
        return  number /denom;
    }
}

int main(){
    double number1, number2, ratio;
    cout << "Enter a numerator:";
    cin >> number1;
    cout << "Enter a denominator:";
    cin >> number2;
    
    try {
        ratio = quotient(number1,number2);
        cout << "Ratio is :" << ratio << endl;
    }
    catch (DivideByZero &except){
        cout << except.what() << endl;
    }
    return 0;
}