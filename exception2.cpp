#include<iostream>
#include<exception>
#include<vector>
using namespace std;


class divideByZeroException: public exception
{
public:
  divideByZeroException() {
    cout<<"divide by zero exception class."<<endl;
  }

};

class divideByZeroException1
{
public:
  divideByZeroException1() {
  }
};

class myClass {
public:
  myClass() {

  }
  void memFunc1(int x, int y)
  {
    int a = 20;
    try
    {
      //Exception -1
      int* p = new int[x * 1000000000];

      ////Approach-2
      ////while (true)
      ////{
      ////  int* ptr = new int[1000000000];
      ////}

      ////Exception -2
      //vector<int> intVector;
      //cout << intVector.at(5);

      ////Exception - 3
      if (y == 0)
        throw divideByZeroException1();

      int k = x / y;
    }
    catch (exception& ex)
    {
      cout << "exception is: " << ex.what() << endl;
    }
    catch (bad_alloc& ex)
    {
      cout << "exception thrown is: "<<ex.what() << endl;
      cout << "inside bad_alloc exception.." << endl;
    }
    catch (out_of_range& ex)
    {
      cout << "inside out of range exception." << endl;
    }
    catch (divideByZeroException& ex) {
      cout<<"Inside custom Exception Handler" << endl;
    }
    catch (...)
    {
      cout << "Exception is thrown and caught in defailt catch block" << endl;
    }
    cout << "Outside try catch" << endl;
  }

  void memFunc2() {
    throw;
  }


  void memFunc3() {
    try
    {
      //Exception -2
      vector<int> intVector;
      cout << intVector.at(5);
    }
    catch (out_of_range& ex)
    {
      cout << "inside MemFunc3. Exception is: "<<ex.what() << endl;
      cout<<"Re throwing the exception" << endl;
      //throw;
    }

    //cout << "Out side try catch block of MemFunc3();" << endl;
  }

};

class A {
  int* p;
public:
    A()
  {
    cout << "Inside Base(A's) Constr" << endl;
    //p = new int[pow(10, 1000000000)];
  }
  ~A()
  {
    cout<<"Inside A's destructor" << endl;
    if (p != nullptr)
    {
      delete []p;
      p = NULL;

    }
  }
};

class B {

  A aObj;

public:
  B() {
    try {
      cout << "Inside B's Constr" << endl;
      vector<int> intVector;
      cout << intVector.at(5);
    }
    catch (exception& ex)
    {
      cout << "Exception inside constrcutor" << endl;
      throw;
    }
    cout << "Inside Constructor completion" << endl;
  }
  ~B() {
    cout << "Inside B's destructor" << endl;
  }
  void memFunc() {

  }
};

void globalFunc()
{
  try {
    B obj;
  }
  catch (exception& ex)
  {
    cout << "Inside main, Exception is: "<<ex.what() << endl;
  }

}

void tempFunc()
{
  vector<int> intVector;
  cout << intVector.at(5);

}


class A1 {
  int* p;
public:
  A1()
  {
    cout << "A's Constr" << endl;
    p = new int[10];
  }
  ~A1()
  {
    if (p != nullptr)
    {
      delete[]p;
      p = nullptr;
    }

    cout << "Inside A's des" << endl;
  }
};

class B1 {
  A1 aObj1;
  A1 aObj2;

public:
  B1()
  {
    try {
      vector<int> intVector;
      cout << intVector.at(5);
    }
    catch (exception& ex)
    {
      cout<<"Insidde B1's catch" << endl; 
    }

  }
  void BMemFunc()
  {
    vector<int> intVector;
    cout << intVector.at(5);
  }

};


int main()
{

//   B1 objB;
//   tempFunc();

  globalFunc();
  myClass obj;
  //obj.memFunc2();
  //obj.myFunc(3, 0);

  //try {
  //  obj.memFunc3();
  //}
  //catch (exception& ex)
  //{
  //  cout << "Inside Main. Exception is: "<<ex.what() << endl;
  //}
  
  return 0;
}