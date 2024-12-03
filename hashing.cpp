#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

class myHash
{
  int noOFBuckets;
  list<int>* listOfBuckets;
 
public:
  myHash(int count) : noOFBuckets(count)
  {
    listOfBuckets = new list<int>[noOFBuckets];
  }
 
  // int hashingkeyLogic(int element)
  // {
  //   return element % 10;
  // }

  int hashingkeyLogic(int ele){
    int a=19,b=93;
    // cout<<ele<<" : : "<<((a*ele+b)%noOFBuckets)<<endl;
    return ((a*ele+b)%noOFBuckets);
  }
 
  void addElement(int ele)
  {
    int key = hashingkeyLogic(ele);
    listOfBuckets[key].push_back(ele);
  }

  void delElement(int ele)
  {
    int key = hashingkeyLogic(ele);
    listOfBuckets[key].remove(ele);
  }
 
  void printTheElements()
  {
    for (int i = 0; i < noOFBuckets; ++i)
    {
      for(int x: listOfBuckets[i])
      { 
        cout << "Element is from bucket: " << i << " and the value is: " << x << endl;
      }
    }
  }

  ~myHash(){
    delete[] listOfBuckets;
  }
};

int main21(){
    myHash bucket(10);
    bucket.addElement(43);
    bucket.addElement(32);
    bucket.addElement(39);
    bucket.addElement(91);
    bucket.addElement(33);
    bucket.addElement(53);
    bucket.addElement(42);
    bucket.addElement(49);
    bucket.addElement(81);
    bucket.addElement(43);

    bucket.printTheElements();

    bucket.delElement(43);
    cout<<"After deleting 43 ======"<<endl;

    bucket.printTheElements();


    return 0;
}