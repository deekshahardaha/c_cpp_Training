
// Functor -- function call operator
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


class Sort

{
	int m;
public:
	bool operator()(int a, int b)
	{
		return a < b && m > 0;
	}
};

static bool compa(int a, int b)
{
	return a < b;
}

void main19()
{

	vector <int> v{ 239,54,21445,32923 };

	sort(v.begin(), v.end(), Sort());



    vector <int> v1{ 239,54,21445,32923 };

	sort(v.begin(), v.end(), compa);



}
 