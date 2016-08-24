#include <iostream>
#include <vector>

using namespace std;

int main(){
	vector<int>* vec = new vector<int>(10,0);
	vector<int> v(vec);
}