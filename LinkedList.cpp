#include <iostream>

using namespace std;

struct Node{
	int data;
	Node* next;

	// Node constructor 
	Node(int value) : data(value), next(nullptr) {}
};

class LinkedList{
private:
	Node* head; // Pointer to the first element of the list

public:
	// LinkedList constructor
	LinkedList() : head(nullptr) {}

	// Function to add a new node at the beginning
	void appendAtBeginning(int value){
		Node* newNode = new Node(value);
		newNode->next = head;
		head = newNode;
	}

	// Function to add a new node at the end of the list
	void append(int value){
		Node *newNode = new Node(value);
		if(head == nullptr) {
			head = newNode;
		} else {
			Node* current = head;
			while(current->next != nullptr){
				current = current->next;
			}
			current->next = newNode;
		}
	}

	void removeFirstNode(){
		if(head == nullptr){
			cout << "List is alredy empty" << endl;
			return;
		}

		Node *temp = head; // Save the address of the current head
		head = head->next; // Move the head to the next node
		delete temp; // Delete the original first node
	}

	// Remove the last node from the list
	void removeLastNode(){
		if(head == nullptr){
			cout << "List is alredy empty" << endl;
			return;
		}

		// If there's only one node in the list, remove it.
		if(head->next == nullptr){
			delete head;
			head = nullptr;
		} else {
			Node* current = head;
			Node* previous = nullptr;

			// Go through the list to the last node
			while(current->next != nullptr){
				previous = current;
				current = current->next;
			}

			delete current; // Remove the last node
			previous->next = nullptr; // Update the next of the new node
		}
	}

	// Search for a node with a specific value
	Node* searchNode(int value){
		Node* current = head;
		while(current != nullptr){
			if(current->data == value){
				return current;
			}
			current = current->next;
		}

		cout << "Node could not be found" << endl;
		return nullptr;

	}

	void reverseList(){
		Node* prev = nullptr;
		Node* current = head;
		Node* nextNode = nullptr;

		while(current != nullptr){
			nextNode = current->next;
			current->next = prev;
			prev = current;
			current = nextNode;
		}

		head = prev;
	}

	void printList(){
		Node* current = head;
		while(current != nullptr) {
			cout << current->data << endl;
			current = current->next;
		}
	}
};

int main(){
	LinkedList list;
	list.append(1);
	list.append(2);
	list.append(3);
	list.append(4);
	list.appendAtBeginning(0);

	list.printList();

	cout << "Removing First Node..." << endl;
	list.removeFirstNode();
	list.printList();

	cout << "Removing Last Node..." << endl;
	list.removeLastNode();
	list.printList();

	cout << "Reversing List..." << endl;
	list.reverseList();
	list.printList();

	return 0;
}
