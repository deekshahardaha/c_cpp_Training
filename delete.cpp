#include <iostream>

using namespace std;

class Myclass1{
    int  value = 0;
    Myclass1& operator=(const Myclass1& obj ) {
        cout<<"cpy ass"<<endl;
    };

public:
    Myclass1(){
        cout<<"const "<<endl;
    }
    Myclass1(int val){
        value=val;
        cout<<"val const "<<endl;
    }
    Myclass1(const Myclass1& obj ){
        cout<<"CC const "<<endl;
    }
    
    
    void printValue() {
 
        auto lambda =[this]() {
    
        cout << "Value: " << value << endl;
        };
        lambda();
    }
 

    
 
};
 
int main10() {
 
Myclass1 obj(10);
Myclass1 o2;
// o2=obj;
 
Myclass1 *ptr = new Myclass1[10];
 
obj.printValue();
 
delete[] ptr;

return 0;
}