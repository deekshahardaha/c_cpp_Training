#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex mtx;

void threadfun(){
    cout<<"Thread fun"<<endl;
    for (int i=1; i<1000;i++){
        cout<<"Thread : "<<i<<endl;
    }
}

int main37(){
    thread th(threadfun);
    for (int i=1001;i<=2000;i++){
        cout<<"Main : "<<i<<endl;
    }
    th.join();
    return 0;
}