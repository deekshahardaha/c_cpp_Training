#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;
 
class MyClassS{
	int x;
	int y;
	int z;
public:
	//const
	MyClassS(int a,int b,int c) : x(a),y(b),z(c) {
		cout<<"inside Constructor"<<endl;
	}
 
	// move constructor
	MyClassS(const MyClassS&& obj){
		cout<<"inside move Constructor"<<endl;
		x = move(obj.x);
		y = move(obj.y);
		z = move(obj.z);
	}
 
	//move assignment
	MyClassS& operator=(const MyClassS&& obj){
		cout << "Move Assignment Operator\n";
		if(this != &obj){
			x = move(obj.x);
			y = move(obj.y);
			z = move(obj.z);
		}

		return *this;
	}
 
	void display() const{
		cout<<x<<" "<<y<<" "<<z<<endl;
	}

};
 
int main33(){
	MyClassS obj1(40,60,80);
	MyClassS obj2 = move(obj1);
	//obj1.display();
	obj2.display();

	return 0;
}
 