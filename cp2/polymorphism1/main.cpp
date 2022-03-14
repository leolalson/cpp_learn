//TODO :code not working. Should be updated to make it work. As polymorphism is not 
//important, skipping it.
#include <iostream>
#include <sstream>
#include <vector>

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
    virtual double grossPay(int hours){
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
        double grossPay(double hours){
             if (salaried){
                 return pay;
             }
             else{
                 return pay*hours;
             }
         }
};


int main(){
    
    vector<Employee> emps;
    
    Employee emp1("Emp1",1200);
    Employee emp2("Emp2",2400);
    
    Manager mgr1("Mgr1",1200, true);
    
    emps.push_back(emp1);
    emps.push_back(mgr1);
    for (int i=0; i< emps.size(); ++i){
        cout << emps[i].grossPay(40) << endl;
    }
    
    Employee *empPtr;
    empPtr = &emp1;
    cout << "Name:" << empPtr->getName() << endl;
    cout << "Pay:" << empPtr->grossPay(40) << endl;
    empPtr = &mgr1;
    cout << "Name:" << empPtr->getName() << endl;
    cout << "Name:" << empPtr->grossPay(40) << endl;
    
    return 0;
}
