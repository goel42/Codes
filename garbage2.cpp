#include <iostream>
#include <climits>

using namespace std;

int findMinDistVertex(int distances[], bool isFinal[], int n){
	int min =  INT_MAX;
	int index = -1;
	for(int i =0;i<n;i++){
		if(distances[i]<min && isFinal[i]==false){
			index = i;
			min = distances[i];
		}
	}

	return index;
}

void printPath(int parents[], int d){
	if(parents[d]==-1){
		cout<<d<<" ";
		return;
	}

	printPath(parents, parents[d]);
	cout<<d<<" ";
}

void djikstra(int** g , int n, int src, int dest){
	int distances[n];
	bool isFinal[n];
	int* parents = new int[n];

	parents[src]=-1;
	for( int i=0;i<n;i++){
		distances[i]=INT_MAX;
	}
	for(int i =0;i<n;i++){
		isFinal[i]=false;
	}

	distances[src]=0;
	while(1){
		int minVer = findMinDistVertex(distances, isFinal, n);
		if(minVer== -1){
			break;
		}
		isFinal[minVer]=true;
		for( int i =0;i<n;i++){
			if(g[minVer][i]!=0 && isFinal[i]==false && distances[minVer]+g[minVer][i] < distances[i]){
				parents[i]=minVer;
				distances[i]=distances[minVer] + g[minVer][i];
			}
		}
	}

	cout<<distances[dest]<<endl;
	printPath(parents, dest);
	cout<<endl;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int num;
		cin>>num;
		int** graph;

		graph = (int **)malloc(num*sizeof(int *));
		for(int i =0;i<num;i++){
			graph[i] = new int[num];
		}
		for(int i =0;i<num;i++){
			for(int j=0;j<num;j++){
				cin>>graph[i][j];
			}
		}
		int s;
		int d;
		cin>>s;
		cin>>d;
		djikstra(graph, num,s,d);
	}
	return 0;
}