#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item{
	int weight;
	int value;
};

// Compare two items
bool compare(Item a, Item b);
// Greedy algorithm
double backpack(vector<Item>& elements, int capacity);

int main(){
	vector<Item> elements = {{10,60}, {20, 100}, {30, 120}};
	int backpackCapacity = 50;

	double result = backpack(elements, backpackCapacity);
	cout << "Max value: " << result << endl;

	return 0;
}

bool compare(Item a, Item b){
	double ratioA = (double) a.value / a.weight;
	double ratioB = (double) b.value / b.weight;
	return ratioA > ratioB;
}

double backpack(vector<Item>& elements, int capacity){
	// Sort elements in descending order using compare function
	sort(elements.begin(), elements.end(), compare);

	double totalValue = 0;
	// Iterate over items and add them to the backpack while there is still space
	for(const auto& item : elements){
		if(capacity >= item.weight){
			// Add the complete item to the backpack
			totalValue += item.value;
			capacity -= item.weight;
		} else {
			totalValue += (double)item.value / item.weight * capacity;
			break;
		}
	}

	return totalValue;
}
