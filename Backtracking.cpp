#include <iostream>
#include <vector>

using namespace std;

void swap(vector<int>& v, int i, int j);
void printPermutations(const vector<int>& v);
// Recursive function that generates permutations using Backtracking
void generatePermutations(vector<int>& v, int start, int end);

int main(){
	vector<int> numbers = {1, 2, 3};
	cout << "Permutations: " << endl;
	generatePermutations(numbers, 0, numbers.size() - 1);
}

void swap(vector<int>& v, int i, int j){
	int temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}


void printPermutations(const vector<int>& v){
	for(int num : v){
		cout<<num<<" ";
	}
}

void generatePermutations(vector<int>& v, int start, int end){
	if (start == end){
		// Complete permutation has been reached, now we have to print it
		printPermutations(v);
		return;
	}

	for(int i = start; i <= end; i++){
		// Swap current element with the first
		swap(v, start, i);
		// Call recursively for the remaining elements
		generatePermutations(v, start+1, end);
		// Undo the swap to try other permutations
		swap(v, start, i);
	}
}
