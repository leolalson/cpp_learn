
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;
//base class
class Animal {
    public:
        virtual void talk() = 0;  
};

class Dog: public Animal{
    public:
        virtual void talk(){
            cout << "Bow" << endl;
        }
};

class Cat: public Animal{
    public:
        virtual void talk(){
            cout << "meow" << endl;
        }
};


int main(){
    Dog dog1;
    Cat cat1;
    dog1.talk();
    cat1.talk();
    
    return 0;
}
