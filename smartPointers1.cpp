#include<iostream>
#include<memory>

using namespace std;


class myClass{
public:
    myClass(){
        cout<<"const"<<endl;
    }
    ~myClass(){
        cout<<"dest"<<endl;
    }
};


void up(unique_ptr<int> && p){
    cout<<"unique ptr: "<<*p <<endl;
}

void sp(shared_ptr<int> && p){
    cout<<"shared ptr: "<<*p <<endl;
}

void spc(shared_ptr<myClass> && p){
    cout<<"in funct"<<endl;
}



class Teacher;

class Student{
    public:
    shared_ptr<Teacher> t;
    Student(){
        cout<<"const S"<<endl;
    }
    ~Student(){
        cout<<"Dest S"<<endl;
    }
};
class Teacher{
    public:
    shared_ptr<Student> s;
    Teacher(){
        cout<<"const T"<<endl;
    }
    ~Teacher(){
        cout<<"Dest T"<<endl;
    }
};


int main61(){

    //  auto_ptr  depricated
    // auto_ptr<int> ptr(new int); // int *ptr=new int;  


    unique_ptr<int> ptr;
    ptr = make_unique<int>();
    *ptr =48;

    unique_ptr<int> ptr2;
    ptr2=std::move(ptr);
    up(std::move(ptr2));
    // cout<<*ptr<<endl;

    shared_ptr<int> pp;
    pp = make_shared<int>();
    *pp=45;
    sp(std::move(pp));

    
    shared_ptr<myClass> pn;
    pn = make_shared<myClass>();
    spc(std::move(pn));
    return 0;
}