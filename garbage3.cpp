#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main(){
	
	vector<int>* k1 = new vector<int>;
	vector<int>* k2 = new vector<int>;

	vector<int>* v1 = new vector<int>;

	k1->push_back(1);
	k1->push_back(2);
	k1->push_back(3);
	k1->push_back(4);
	k1->push_back(5);

	k2->push_back(1);
	k2->push_back(2);
	k2->push_back(3);
	k2->push_back(4);
	k2->push_back(5);

	v1->push_back(10);
	v1->push_back(20);

	map<vector<int>* , vector<int>* > m;
	m.insert(make_pair(k1,v1));
	map<vector<int>* , vector<int>* > :: iterator it;
	it = m.find(k2);
	if(it!=m.end()){
		cout<<"hello"<<endl;
	}else{
		cout<<"trello"<<endl;
	}

	// m.insert(make_pair(k1, NULL));
	// vector<int> v = m.find(k1)->second;
	// if(m.find(k1)->second == NULL){
	// 	cout<<"hello";
	// }else{
	// 	cout<<"trello";
	// }

	// vector<int> v;
	// cout<<v.size()<<endl;
	// // v.push_back();
	// cout<<v.size()<<endl;


}