#include <iostream>
#include <queue>

using namespace std;

void bfs(int** g, int n, int src, int dest){

	vector< vector<int> > paths;
	for( int i =0;i<n;i++){
		vector<int> t;
		paths.push_back(t);
	}
	int isVisited[n];
	for(int i=0;i<n;i++){
		isVisited[i]=0;
	}
	queue<int> q;
	int distances[n];
	for( int i=0;i<n;i++){
		distances[i]=-1;
	}
	distances[src]=0;
	q.push(src);
	isVisited[src]=1;
	paths[src].push_back(src);


	while(!q.empty()){
		int temp = q.front();
		q.pop();
		// isVisited[temp]=1;
		for( int i =0;i<n;i++){
			if(g[temp][i]==1 && isVisited[i] == 0){
				distances[i]=distances[temp]+1;
				q.push(i);
				isVisited[i]=1;
				for(int k =0;k<paths[temp].size();k++){
					paths[i].push_back(paths[temp][k]);
				}
				paths[i].push_back(i);
			}
		}
	}

	// cout<<distances[dest];
	// for( int i =0;i<n;i++){
	// 	cout<<distances[i]<<" ";
	// }
	// cout<<endl;
	// cout<<endl;
	// for(int i =0;i<n;i++){
	// 	for(int j =0;j<paths[i].size();j++){
	// 		cout<<paths[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }

	cout<<distances[dest]<<endl;
	for(int i =0;i<paths[dest].size();i++){
		cout<<paths[dest][i]<<" ";
	}
	cout<<endl;
}

int main(){
int t;
cin>>t;
while(t--){
	int num;
	cin>>num;
	// cout<<num;
	// cout<<"beauty";
	int** graph;
	// cout<<"hello2";
	graph = (int **)malloc(num*sizeof(int *));
	for(int i =0;i<num;i++){
		graph[i] = new int[num];
	}
	// cout<<"hello1";

	for(int i =0;i<num;i++){
		for(int j=0;j<num;j++){
			cin>>graph[i][j];
		}
	}
	int s,d;
	cin>>s>>d;
	bfs(graph, num,s,d);
}
	return 0;
}

