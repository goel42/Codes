#include <iostream>
#include <vector>

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

int main(){
	vector<int> temp;
	temp.push_back(1);
	temp.push_back(2);
	temp.push_back(3);
	temp.push_back(4);
	temp.push_back(5);
	temp.push_back(6);
	temp.push_back(7);
	temp.push_back(8);
	temp.push_back(9);
	temp.push_back(10);
	temp.push_back(11);
	temp.push_back(12);
	temp.push_back(13);
	temp.push_back(14);
	temp.push_back(15);
	temp.push_back(16);

	vector<int> * outputR = swappy(temp, 0, 2 , 1, 4);
	for(int i=0;i < outputR->size();i++){
		cout<<(*outputR)[i]<<" ";
	}
	cout<<endl;
	vector<int> * outputC = swappy(temp, 1, 2 , 1, 4);
	for(int i=0;i < outputC->size();i++){
		cout<<(*outputC)[i]<<" ";
	}
	cout<<endl;        
}