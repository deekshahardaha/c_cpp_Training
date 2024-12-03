#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Sort
{
public:
	int m = 0;
	bool operator()(int a, int b)
	{
        m++;
        cout<<a<<" "<<b<<" "<<m<<endl;
		return a < b;
	}
};


int main39()
{
	
	vector <int> v{ 239,54,21445,32923 };
	Sort s;
	sort(v.begin(), v.end(), s);
	for (int e : v)
	{
		cout << e << " ";
	}
	cout <<endl<<s.m << endl; // giving zero why?

    /*

    */

    return 0;
}

