#include "Header.h"
#include "functions.h"

// Function to read 10 integers from user and enqueue them
void inputIntegers(Queue<int>& q) {
    int value;
    cout << "Enter 10 integers to add to the queue:\n";
    for (int i = 0; i < 10; ++i) {
        cout << "Enter integer #" << (i + 1) << ": ";
        cin >> value;
        q.push(value);
    }
}
// Function to take input, display the queue, and show front element and size
void take_input_display(Queue<int>& q) {
	inputIntegers(q);
	cout << "Queue after inputting integers:\n";
	q.display();
	cout << "Front element: " << q.front() << endl;
	cout << "Queue size: " << q.size() << endl;
	
}
// Function to move the front element to the rear of the queue
void move_to_rear(Queue<int>& q) {
	if (q.empty()) {
		cout << "Queue is empty. Cannot move front to rear.\n";
		return;
	}

	int front_value = q.front();
	q.pop(); // Remove the front element
	q.push(front_value); // Add it to the back
	cout << "Moved front element " << front_value << " to the rear of the queue.\n";
	cout << "Queue after moving front to rear:\n";
	q.display(); // Display the queue after moving
	q.clear(); // Clear the queue after displaying
}

// Function to display the contents of a vector
void display_vector(const vector<int>& vec) {
	cout << "Vector contents: ";
	for (const auto& item : vec) {
		cout << item << " ";
	}
	cout << endl;
}
// Recursive function to find the last occurrence of a target in a vector
int linear_search_last_occurrence(const vector<int>& items, int& target, size_t pos_first) {
    if (pos_first == items.size())
        return -1;
    int pos = linear_search_last_occurrence(items, target, pos_first + 1);
    if (pos != -1)
        return pos;
    else if (target == items[pos_first])
        return pos_first;
    else
        return -1;
}
//Function to see if the target is in the vector
void search_again_recursive(const vector<int>& vec) {
	int target;
	cout << "Enter the target value to search for its last occurrence:\n";
	cin >> target;

	int last_occurrence = linear_search_last_occurrence(vec, target, 0);

	if (last_occurrence != -1) {
		cout << "Last occurrence of " << target << " is at index: " << last_occurrence << endl;
	}
	else {
		cout << target << " not found in the vector.\n";
		cout << "Would you like to try again? (y/n): ";
		char choice;
		cin >> choice;
		if (choice == 'y' || choice == 'Y') {
			search_again_recursive(vec);  // 🔁 Recursive call
		}
		else {
			cout << "Exiting search.\n";
		}
	}
}

// Function to demonstrate linear search for last occurrence
void linear_search_demo() {
	vector<int> vec;
	cout << "Enter integers for the vector (end with a non-integer input, then hit enter):\n";
	int value;
	while (cin >> value) {
		vec.push_back(value);
	}
	cin.clear(); 
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	search_again_recursive(vec); // Start the search for last occurrence
	vec.clear(); // Clear the vector after the search
}

//Funtion to take in a queue
void take_input(Queue<int>& q) {
	int value;
	cout << "Enter integers to add to the queue (end with a non-integer input):\n";
	while (cin >> value) {
		q.push(value);
	}
	cin.clear(); // Clear the error state
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the rest of the line
	q.display(); // Display the queue after input
	cout << "Queue size: " << q.size() << endl;
}
// Insertion sort of a queue
void insertion_sort(Queue <int>& q) {
	int i, j, key;
	bool insertionNeeded = false;
	// takes in elements to sort
	take_input(q);
	vector<int> num = q.to_vector(); // Convert queue to vector for sorting
	for (j = 1; j < num.size(); j++) {
		key = num[j];
		insertionNeeded = false;
		for (i = j - 1; i >= 0; i--) {
			if (key < num[i]) {
				num[i + 1] = num[i]; // larger values move right
				insertionNeeded = true;
			}
			else
				break;
		}
		if (insertionNeeded)
			num[i + 1] = key; //Put key into its proper location
	}
	q.clear(); // Clear the queue before inserting sorted elements back
	for (int k = 0; k < num.size(); k++) {
		q.push(num[k]); // Push sorted elements back to the queue
	}
	cout << "Queue sorted using insertion sort:\n";
	q.display(); // Display the sorted queue
	q.clear(); // Clear the queue after displaying
}