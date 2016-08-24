#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> swappy(vector<int> input, int rc, int rcNum, int rot, int n){
	if(rc == 0){
		int startIndex = (rcNum)*n;

	}

	if( rc == 1){

	}
}

void bfs(vector<int> input, vector<int> output){
	queue <vector<int> > q;
	map<vector<int>, vector<int> > m;
	map<vector<int> , vector<int> > :: iterator it;


	q.push(input);
	vector<int> nullParent;
	m.insert(make_pair(input,nullParent));

	while(!q.empty()){
		vector<int> curr = q.front();
		q.pop();

		vector<int> a1 = 

		it = m.find(a1);
		if(a1 == output){
			//
		}else if(it == m.end()){
			//
		}

	}




}