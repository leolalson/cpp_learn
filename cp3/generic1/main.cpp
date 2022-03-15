//TODO :code not working. Should be updated to make it work. As polymorphism is not 
//important, skipping it.
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

template <typename T>
void display(T arr[], int size){
    for (int i =0; i < size; ++i){
        cout << arr[i] << endl;
    }
}

template <typename T>
T findMax(T &arg1, T &arg2){
    if  (arg1>arg2){
        return arg1;
    }else {
        return arg2;
    }
}


int main(){
    int size=10;
    int numbers[size];
    for (int i=0;i<size;++i){
        numbers[i] = i;
    }
    display(numbers,size);
    
    string names[] = {"a","s","d","f","g","h","j","k","l","z"};
    display(names,size);
    
    int a=12,b=24;
    cout <<findMax(a,b)<<endl;
    double x=2.25,y=0.25;
    cout <<findMax(x,y)<<endl;
    
    string w1 ="apple",w2 = "aardvark";
    cout <<findMax(w1,w2)<<endl;
    return 0;
}
