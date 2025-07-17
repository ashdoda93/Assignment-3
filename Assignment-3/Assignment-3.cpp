#include "Header.h"
#include "functions.h"

int main() {

	Queue<int> q;
	int choice;
	do {
		cout << "Menu:\n";
		cout << "1. Queue data structure demo.\n";
		cout << "2. Linear search for last occurrence in a vector demo\n";
		cout << "3. Insertion sort demo.\n";
		cout << "4. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;
		switch (choice) {
		case 1:
			take_input_display(q);
			move_to_rear(q);
			break;
		case 2:
			linear_search_demo();
			break;
		case 3:	
			insertion_sort(q);
			break;
		case 4:
			cout << "Exiting program.\n";
			break;
		default:
			cout << "Invalid choice. Please try again.\n";
		}
	} while (choice != 4);
	return 0;
}
