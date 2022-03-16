#include <iostream>
#include <stdexcept>
#include <fstream>

using namespace std;

int main(){
    ifstream file;
    file.exceptions(ifstream::failbit | ifstream::badbit);
    file.open("file.txt");
    try {
        while (!file.eof()){
            cout << file.get() ;
        }
    }
    catch (ifstream::failure e){
        cout << e.what() << endl;
        return 1;
    }
    file.close();
    return 0;
}