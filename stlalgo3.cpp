#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


int main() {
	vector <int> s = { 10,10,23,33,23,44,44,55,67,67 }; //{ 1,1,2,2,2,3,4,4,5,6 }; 
	vector<int> s2(4); //s2(size) --> size of s2

	// 1. copy
	copy(s.begin(), s.begin()+4, s2.begin());
	//copy(s.begin(), s.end(), s2.begin());
	for (auto x : s)
		cout << x << " ";
	cout << endl;
	for (auto x : s2)
		cout << x << " ";
	cout << endl;

	//=============================================================//

	//2. unique (only removes consecutive duplicates)
	auto x = unique(s.begin(), s.end());
	for (auto x : s)
		cout << x << " ";
	cout << endl;

	// Resize the vector to the new logical size
	s.erase(x, s.end());

	for (auto x : s)
		cout << x << " ";
	cout << endl;

	//=============================================================//


	// Swap
	s.swap(s2);
	for (auto x : s)
		cout << x << " ";
	cout << endl;

	for (auto x : s2)
		cout << x << " ";
	cout << endl;


	//=============================================================//

	generate(s.begin(), s.begin()+4, []() {return 3; });
	for (auto x : s)
		cout << x << " ";
	cout << endl;
	vector<int> v(7);
	generate(v.begin(), v.end(), []() {return 3; });
	for (auto x : v)
		cout << x << " ";
	cout << endl;


	//=============================================================//

	//transform
	transform(s2.begin(), s2.end(), v.begin(), [](int x) { return x * x; });
	for (auto x : v)
		cout << x << " ";
	cout << endl;

	return 0;
}