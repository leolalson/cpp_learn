#include <iostream>
#include <sstream>

using namespace std;
//base class
class Employee {
    protected:
        string name;
        double pay;
    public:
        Employee(){
            name = "";
            pay = 0;
        }
        Employee(string empname,double payrate){
            name = empname;
            pay = payrate;
        }
    string getName(){
        return name;
    }
    void setName(string empname){
        name = empname;
    }
    double getPay(){
        return pay;
    }
    void setPay(double payRate){
        pay = payRate;
    }
    string toString(){
        stringstream stm;
        stm << name << ": " <<pay;
        return stm.str();
    }
    double grossPay(int hours){
        return pay * hours;
    }
    ~Employee(){}
            
};

class Manager : public Employee{
    private:
        bool salaried;
    public:
        //default constructor
        Manager() : salaried(true){}
    
        Manager(string name, double payRate, bool isSalaried):Employee(name, payRate){
        salaried = isSalaried;
        }
        ~Manager(){}
    
        bool getSalaried(){
            return salaried;
        }
           
         double grossPay(){
             if (salaried){
                 return pay;
             }
             else{
                 return pay*hours;
             }
         }
};


int main(){
 
    Employee emp1("Emp1",1200);
    Employee emp2("Emp2",2400);
    
    cout << emp1.toString() << endl;
    cout << emp2.toString() << endl;
    cout << emp2.grossPay(40) << endl;
    
    Manager emp3("Emp3",3400,true);
    cout << emp3.getName() << endl;
    cout << emp3.getPay() << endl;
    cout << emp3.getSalaried() << endl;
    cout << emp3.grossPay() << endl;
}
