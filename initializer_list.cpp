#include<iostream>
#include<vector>

using namespace std;

void print(initializer_list<int> list);

class MyCls

{

	int m[10];

public:

	MyCls(initializer_list<int> list)

	{
		int i = 0;
		for (auto v : list)
		{
			m[i++] = v;
		}
        // print(list);
        for(auto it:m){
            cout<<it<<" ";
        }
        cout<<endl;
	}
 
	void operator()(int adjustment)

	{

		for (auto& elm : m)

		{

			elm += adjustment;
            cout<<elm<<" ";

		}
        cout<<endl;


	}
    void operator+(int adjustment)

	{

		for (auto& elm : m)

		{

			elm += adjustment;
            cout<<elm<<" ";

		}
        cout<<endl;


	}

};

void print(initializer_list<int> list)

{

	for (auto e : list)

	{

		cout << e << " ";

	}
    cout<<endl;

}

class Matrix

{

	//data element

public:

	Matrix(initializer_list<initializer_list<int>> m)

	{
        for(auto it:m){
            print(it);
        }
	}

};

void printVec(vector<int> v)

{

	for (auto e : v)

	{

		cout << e <<" ";

	}
     cout<<endl;

}

int main22()

{

	int x = 4;
 
	int arr[]{ 1,2,3,4,5,6,7,8,9,10 };

 
	vector<int> v{ 1,2,4,5 };
 
	initializer_list<int> list{ 3,4,5,5,6 };

	printVec({2,4,5,5});
    printVec(list);
 
	
 
	MyCls obj({ 1,2,3 });

	MyCls obj2({ 1 });

	MyCls obj3({ 1,2,3,4,5,6,7,8,9,10 ,23,23,2,44,33});
	obj3(4);
    obj3+4;
    obj3+(4);
    // obj3()(4);
    // obj3()4;


 
	Matrix m1({ { 1,2 }, { 3,4 } });

	Matrix m2({ {1,2,3},{4,5,6},{7,8,9} });

	print({ 21,5,3,54,6,543,434,34,35,46,456,56,54,34,54 });


    return 0;

}
 