#include <iostream>

#include <stdio.h>

#include <string>

using namespace std;
 
class MyClass{

	int x;

	int y;

	int z;
 
public:

	//const

	MyClass(int a,int b,int c) : x(a),y(b),z(c) {

		cout<<"inside Constructor"<<endl;

	}
 
	// move constructor

	MyClass(const MyClass&& obj){

		cout<<"inside move Constructor"<<endl;

		x = std::move(obj.x);

		y = std::move(obj.y);

		z = std::move(obj.z);

	}
 
	//move assignment

	MyClass& operator=(const MyClass&& obj){

		cout << "Move Assignment Operator\n";

		if(this != &obj){

			x = std::move(obj.x);

			y = std::move(obj.y);

			z = std::move(obj.z);

		}

		return *this;

	}
 
	void display() const{

		cout<<x<<" "<<y<<" "<<z<<endl;

	}

};
 
int main(){

	MyClass obj1(40,60,80);

	MyClass obj2 = std::move(obj1);

	obj1.display();

	obj2.display();

}
 