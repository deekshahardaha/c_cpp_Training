#include <iostream>
#include<map>

using namespace std;

int main30()
{

  map<int, char> myMap{ {1,'a'}, {2,'b'}, {3, 'c'}};
  
  myMap.insert(make_pair(10,'a'));

  for (auto x : myMap)
  {
    cout << x.first << " ";
    cout << x.second << endl;
  }


  auto res = myMap.insert(make_pair(11, 'c'));

  //auto x = res.first ;
  //int a = x->first;

  cout << (res.first->first) << " "<<(res.first->second)<<" ";
  cout << (res.second) << endl;

  //myMap[1] = 'a';
  //myMap[1] = 'b';


  map<int, int>::iterator mapiterator;
  map<int, char>::iterator mapiterator2;

  map<int, char> myMap2{ {111,'a'}, {22,'b'}, {33, 'c'} };

  //for (mapiterator2 = myMap2.begin(); mapiterator2 != myMap2.end(); mapiterator2++)
    for(mapiterator2 = myMap2.begin(); mapiterator2 != myMap2.end(); ++mapiterator2)
  {
    cout << mapiterator2->first << " : " << mapiterator2->second << endl;
  }

 for(mapiterator2 = myMap.begin(); mapiterator2 != myMap.end(); ++mapiterator2)
  {
    cout << mapiterator2->first << " : " << mapiterator2->second << endl;
  }

  return 0;
}