#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>

using namespace std;

vector<int>* swappy(vector<int> input, int rc, int rcNum, int rot, int n){
	vector<int>* opt = new vector<int>(input);
	if(rc == 0){
		int startIndex = (rcNum)*n;
		for(int i=startIndex;i<startIndex+n;i++){
			int index = ((i+rot)%n) + (rcNum)*n;
			(*opt)[index] = input[i];
		}
		return opt;
	}

	if( rc == 1){
		int startIndex = rcNum;
		int endIndex = rcNum + n*(n-1);
		for(int i = startIndex; i <= endIndex; i += n){
			int index = (i + rot*n) % (n*n);
			(*opt)[index] = input[i];
		}
		return opt;
	}
}


void bfs(vector<int> input, vector<int> output, int n){
	queue <vector<int> > q;
	map<vector<int>, vector<int> > m;
	map<vector<int> , vector<int> > :: iterator it;
	map<vector<int> , vector<int> > :: iterator it2;


	q.push(input);
	vector<int> nullParent;
	m.insert(make_pair(input,nullParent));

	while(!q.empty()){
		vector<int> curr = q.front();
		q.pop();
		for(int k=0;k<2;k++){
			for(int i =0;i<n ;i++){
				for(int j=1; j<=n-1; j++){
					vector<int>* a1_temp = swappy(curr, k, i, j, n);
					vector<int> a1;
					for(int i =0; i < a1.size();i++){
						a1.push_back((*a1_temp)[i]);
					}
					// delete a1_temp;
					it = m.find(a1);
					if(it == m.end()){
						m.insert(make_pair(a1,curr));
						q.push(a1);
					}
					if(a1 == output){
						stack<vector<int> > s;
						s.push(a1);
						vector<int> parent = m.find(a1)->second;
						while(parent!=nullParent){
							s.push(parent);
							parent = m.find(parent)->second;
						}
						while(!s.empty()){
							vector<int> f = s.top();
							for(int i=0;i<f.size();i++){
								cout<<f[i]<<" ";
							}
							cout<<endl;
							s.pop();
						}
					}
				}
			}
		}
	}
}

int main(){

	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> input;
		for(int i =0;i<n;i++){
			int temp;
			cin>>temp;
			input.push_back(temp);
		}
		vector<int> output;
		for(int i =0;i<n;i++){
			int temp2;
			cin>>temp2;
			output.push_back(temp2);
		}
		bfs(input,output,n);
	}


}