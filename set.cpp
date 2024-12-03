#include <iostream>
#include<set>
#include<vector>
#include<list>
#include <string>

using namespace std;

class MyClassS {
public:
    string b;
    MyClassS( const string& b) :b(b) {
        cout << "MyClass constructed: "  << b << endl;
    }
    MyClassS(const MyClassS &curr) :b(curr.b){
        cout << "Copy constructed: " << b << endl;
    }
    MyClassS(MyClassS &&curr):b(move(curr.b))  {
        cout << "Move constructed: " << b << endl;
    }

};

class Greater
{
  int a;
public:
  bool operator<(int x)
  {
    return a < x;
  }

  void operator()() {

  }
};

int main56(){

// set<int, greater<>> mySet{1, 10, 30, 23 };
set<int> mySet{1, 10, 30, 23 };
  set<int, Greater> mySet1;


  vector<list<pair<int, MyClassS>>> myData;
//   auto x = function1();
 
   auto result =  mySet.insert(1);
   cout << *(result.first) << endl;
   cout << result.second<< endl;

   auto result2 = mySet.insert(11);
   cout << *(result2.first) << endl;
   cout << result2.second << endl;

   for (int x : mySet)
  {
   cout << x << " ";
  }
  cout<<endl;

  auto x = mySet.lower_bound(12); // Iterator pointing to first element equal to or greater than key, or end(). //23
   cout << *x << endl;

   auto y = mySet.upper_bound(12); // Iterator pointing to the first element greater than key, or end(). //23
   cout << *y << endl;

   auto x1 = mySet.lower_bound(11); //11
   cout << *x1 << endl;

   auto y1 = mySet.upper_bound(11); //23
   cout << *y1 << endl;

  mySet.insert(13);
  mySet.insert(10);
  mySet.insert(8);

  for (int x : mySet)
  {
   cout << x << " ";
  }
  cout<<endl;

    int key=10;
  // Get the range of elements equal to key
    auto range = mySet.equal_range(key);

    // Output the results
    cout << "Elements equal to " << key << " are in the range: ";
    cout << "[" << *range.first << ", " << (range.second == mySet.end() ? "end" : to_string(*range.second)) << ")" << endl;

    // Check if the key is present
    if (range.first != range.second) {
        cout << "The key " << key << " is present in the set." << endl;
    } else {
        cout << "The key " << key << " is not present in the set." << endl;
    }


  return 0;

}