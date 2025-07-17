#include "Header.h"

template <typename Item_Type>
class Queue {
private:
    struct Node {
        Item_Type data;
        Node* next;
        Node(const Item_Type& item, Node* ptr = nullptr)
            : data(item), next(ptr) {
        }
    };

    Node* front_of_queue;
    Node* back_of_queue;
    size_t num_items;

public:
    Queue();
    ~Queue();
	void push(const Item_Type& item);  // Adds to queue
	void pop();                        // Removes front item
    Item_Type front() const;          // Access front item
    size_t size() const;              // Get number of items
    bool empty() const;               // Is queue empty?
	void display() const;             // Display queue contents
	vector<Item_Type> to_vector() const; // Convert queue to vector
	void clear();                     // Clear the queue
};

// Constructor
template <typename Item_Type>
Queue<Item_Type>::Queue() : front_of_queue(nullptr), back_of_queue(nullptr), num_items(0) {}

// Destructor
template <typename Item_Type>
Queue<Item_Type>::~Queue() {
    while (!empty()) {
        pop();
    }
}

// Add to queue
template <typename Item_Type>
void Queue<Item_Type>::push(const Item_Type& item) {
    if (front_of_queue == nullptr) {
        back_of_queue = new Node(item);
        front_of_queue = back_of_queue;
    }
    else {
        back_of_queue->next = new Node(item);
        back_of_queue = back_of_queue->next;
    }
    num_items++;
}

// Remove from queue
template <typename Item_Type>
void Queue<Item_Type>::pop() {
    if (empty()) {
        throw underflow_error("Queue is empty. Cannot pop.");
    }

    Node* old_front = front_of_queue;
    front_of_queue = front_of_queue->next;
    if (front_of_queue == nullptr) {
        back_of_queue = nullptr;
    }
    delete old_front;
    num_items--;
}

// Front
template <typename Item_Type>
Item_Type Queue<Item_Type>::front() const {
    if (empty()) {
        throw underflow_error("Queue is empty. No front element.");
    }
    return front_of_queue->data;
}

// Size
template <typename Item_Type>
size_t Queue<Item_Type>::size() const {
    return num_items;
}

// Empty
template <typename Item_Type>
bool Queue<Item_Type>::empty() const {
    return num_items == 0;
}

//Display function
template <typename Item_Type>
void Queue<Item_Type>::display() const {
    Node* current = front_of_queue;
    cout << "\nQueue contents (from front to back):\n";
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// Convert queue to vector
template <typename Item_Type>
vector<Item_Type> Queue<Item_Type>::to_vector() const {
	vector<Item_Type> results;
	Node* current = front_of_queue;
	while (current != nullptr) {
		results.push_back(current->data);
		current = current->next;
	}
	return results;
}

// Clear the queue
template <typename Item_Type>
void Queue<Item_Type>::clear() {
	while (!empty()) {
		pop();
	}
}