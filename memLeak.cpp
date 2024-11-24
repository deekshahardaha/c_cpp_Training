#include<iostream>

using namespace std;


void myfun(){
    static int icounter=0;
    icounter++;
    int *ptr = new int;
    *ptr = 5;
    if(icounter%2==0){
        return ;  //memory leak on specific condition. 
    }
    delete ptr;
}
int main(){
    
    myfun();
    myfun();
    myfun();
    myfun();


    return 0;
}