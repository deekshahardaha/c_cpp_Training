/*
STL Algo's
 

1.Sort ()
2.Reverse
3.Max_element
4.Min_Element
5.Accumulate
6.Count
7.Find 
8.Binary_search()
9.Lower_bound
10.Upper_bound
 
*/
#include<iostream>
#include<vector>
#include <algorithm>
#include<numeric>

using namespace std;


class IsOdd {
public:
    int operator()(int sum, int n) const {
        return sum + (n % 2 != 0 ? n : 0); 
    }
};

int main62(){
    

    vector<int> v={33,56,25,78,44,33};

    //1. Sort
    // sort(v.begin(),v.end());
    // sort(v.begin(),v.end(), A comparison functor);


    // 2.reverse
    // reverse(v.begin(),v.end());

    // 3. 4. Max Min
    auto mxitr=max_element(v.begin(),v.end());
    auto mnitr = min_element(v.begin(),v.end());

    cout<<" max :"<<*mxitr<< "at : "<<(mxitr-v.begin())+1<<endl;
    cout<<" min :"<<*mnitr<<"at : "<<(mnitr-v.begin())+1<<endl;

    // 5. Accumulate
    int sum = accumulate(v.begin(), v.end(), 0);
    IsOdd isod;
    int val =accumulate(v.begin(),v.end(),0,isod );

    cout << "Sum  : "<<sum<<endl;
    cout << "Val  : "<<val<<endl;

    // 6. Count
    cout<<"Count of 33 : "<<count(v.begin(),v.end(),33)<<endl;


    // 7. Find
    auto rr=find(v.begin(),v.end(),21);
    cout<<*rr<<endl;

    // 8.Binary Search
    if(binary_search(v.begin(),v.end(),33)){
        cout<<"found "<<endl;
    }else{
        cout<<"Not found"<<endl;
    }
    // bool ff=binary_search(v.begin(),v.end(),34,[](int a, int b){
    //     cout<<a<<" "<<b<<endl;
    //     return a<b;
    // });
    // if(ff){
    //     cout<<"found "<<endl;
    // }else{
    //     cout<<"Not found"<<endl;
    // }

    // 9.Lower_bound 10.Upper_bound
    auto bhk=lower_bound(v.begin(),v.end(),33);
    cout<<*bhk<<endl;
    auto bhk2=upper_bound(v.begin(),v.end(),33);
    cout<<*bhk2<<endl;



    return 0;
}