
class Node {
public:
    int data;      // Stores the integer value
    Node* next;    // Pointer to the next node

    // Constructor to initialize a node
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
    Node* head;  // Pointer to the first node
};

// Function to shift the largest node to the end of the linked list
//this solution saves and does not change the order of the rest of the nodes
void ShiftLargest(Node* head) {
	if (head == nullptr || head->next == nullptr) {
		return;
	}

	Node* largest = head;
	Node* prev = nullptr;
	Node* current = head->next;

	while (current != nullptr) {
		if (current->data > largest->data) {
			largest = current;
			prev = current;
		}
		current = current->next;
	}
	if (largest->next == nullptr) {
		return;
	}
	prev->next = largest->next;
	current = head;
	while (current->next != nullptr) {
		current = current->next;
	}
	current->next = largest;
	largest->next = nullptr;
} 
