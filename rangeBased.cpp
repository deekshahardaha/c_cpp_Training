#include <iostream>
#include <iterator>
#include <map>
#include <vector>

using namespace std;
 
 
int main54(){

	multimap<int,int> mm;
 
	mm.insert(pair<int,int>(1,70));

	mm.insert(pair<int,int>(1,70));

	mm.insert(pair<int,int>(1,60));

	mm.insert(pair<int,int>(8,40));

	mm.insert(pair<int,int>(2,70));
 
 
	
 
	for(multimap<int,int>::iterator itr=mm.begin(); itr != mm.end(); ++itr){

		cout<<itr->first<<" "<<itr->second<<endl;

	}
 
	for(auto it:mm){

		cout<<it.first<<" "<<it.second<<endl;

	}
 
 
	vector<int> v;

	v.push_back(10);

	v.push_back(20);

	v.push_back(30);

	v.push_back(40);

	v.push_back(50);

	v.push_back(60);
 
	for(auto it:v) cout<<it<<endl;
 
		

	for(vector<int>::iterator itt = v.begin();itt!=v.end();++itt){

		cout<<*itt<<endl;

	}

	return 0;
 
}
 