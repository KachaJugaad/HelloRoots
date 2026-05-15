#include <iostream>
#include <stdexcept>
#include <cassert>
using namespace std;

template <typename T>
class DoublyLinkedList {
	private:
		struct Node {
			T value;
			Node* prev;
			Node* next;
			Node(const T& v) : value(v), prev(nullptr), next(nullptr) {}
		};

		Node* head;
		Node* tail;
		size_t count;

	public:
		DoublyLinkedList() : head(nullptr), tail(nullptr), count(0) {}

		~DoublyLinkedList() {
			// BLANK 1: walk from head to tail, delete every node
			//          (leaking nodes here is the classic DLL bug)
		}

		// --- Insertions ---

		void push_front(const T& value) {
			// BLANK 2: create node; wire it before head; update head;
			//          if list was empty, tail also points to new node
			//Node *newNode = (Node*)malloc(sizeof(Node));
			Node *newNode = new Node(value);
			newNode->value = value;
			count++;
			if (!head) {
				head = tail = newNode;
				newNode->next = NULL;
				newNode->prev = NULL;
				return;
			}
			newNode->next = head;
			newNode->prev = NULL;
			head->prev=newNode;
			head = newNode;
		}

		void push_back(const T& value) {
			// BLANK 3: mirror of push_front on the tail side
			//Node* newNode = (Node*)malloc(sizeof(Node));
			Node* newNode = new Node(value);
			count++;
			if(!head) 
			{
				head = tail = newNode;
				newNode->next = newNode->prev = NULL;
				return;
			}
			tail->next = newNode;
			newNode->prev = tail;
			newNode->next = NULL;
			tail = newNode;
			return ; 
		}

		// Insert `value` at zero-based index. index == size() means append.
		void insert_at(size_t index, const T& value) {
			// BLANK 4: bounds check (index <= count, else throw out_of_range)
			//          handle index == 0  → push_front
			//          handle index == count → push_back
			//          otherwise walk to position, splice node in,
			//          rewire 4 pointers: newNode->prev, newNode->next,
			//          left->next, right->prev
			if (index > count) {
				throw std::out_of_range("Index out of bounds");
			}

			// Delegate to simpler functions
			if (index == 0) {
				push_front(value);
				return;
			}
			if (index == count) {
				push_back(value);
				return;
			}

			// Middle insertion: choose direction based on proximity
			Node* left;
			if (index <= count / 2) {
				// Traverse forward from head
				left = head;
				for (size_t i = 0; i < index - 1; i++) {
					left = left->next;
				}
			} else {
				// Traverse backward from tail
				left = tail;
				for (size_t i = count - 1; i > index - 1; i--) {
					left = left->prev;
				}
			}

			// Now insert between left and left->next
			Node* newNode = new Node(value);
			Node* right = left->next;

			left->next = newNode;
			newNode->prev = left;
			newNode->next = right;
			right->prev = newNode;

			count++;	
		}

		// --- Deletions ---

		T pop_front() {
			// BLANK 5: empty-case contract — pick one (throw / sentinel / assert)
			//          and use the SAME choice in pop_back / remove_at
			//          detach head, advance head, fix new head's prev,
			//          delete old node, decrement count, return value
			assert(head != nullptr);
			T tmp = head->value;
			// ...
			Node *oldHead = head; 
			head = head->next;
			delete oldHead;
			count--;
			return tmp;
		}

		T pop_back() {
			// BLANK 6: mirror of pop_front on the tail side
			assert(tail != nullptr);
			T tmp = tail->value;
			// ...
			Node* oldTail = tail;
			tail = tail->prev;
			delete oldTail;
			count--;
			return tmp;
		}

		T remove_at(size_t index) {
			// BLANK 7: bounds check (index < count, else throw)
			//          index == 0           → pop_front
			//          index == count - 1   → pop_back
			//          otherwise walk to node, rewire prev<->next,
			//          delete node, decrement count, return value


			if (index >= count) {
				throw std::out_of_range("Index out of bounds");
			}

			if (index == 0) {
				return	pop_front();
			}
			if (index == count-1) {
				return	pop_back();
			}

			Node* left;
			if (index <= count / 2) {
				// Traverse forward from head
				left = head;
				for (size_t i = 0; i < index - 1; i++) {
					left = left->next;
				}
			} else {
				// Traverse backward from tail
				left = tail;
				for (size_t i = count - 1; i > index - 1; i--) {
					left = left->prev;
				}
			}
		        T tmp = left->value;
			left->prev->next = left->next;
			left->next->prev = left->prev;
			delete left;
			count--;	

			return tmp;
		}

		// --- Access / search ---

		const T& front() const {
			// BLANK 8: must match pop_front's empty-case contract
			return head->value;
		}

		const T& back() const {
			// BLANK 9: must match pop_back's empty-case contract
			return tail->value;
		}

		// Return zero-based index of first node holding `value`, or -1.
		int find(const T& value) const {
			// BLANK 10: linear scan from head, return index when found
			Node *tmp = head;
			int indexFound=0;
			while(tmp!= NULL) 
			{
				cout<<tmp->value<<":"<<value<<endl;
				if(tmp->value == value) return indexFound;
				tmp=tmp->next;
				indexFound++;
			}

			return -1;
		}

		// --- Introspection ---

		size_t size() const { return count; }
		bool is_empty() const { return count == 0; }

		// Walk head → tail, print values space-separated.
		void print_forward() const {
			// BLANK 11
		}

		// Walk tail → head, print values space-separated.
		// (Existence of this proves your prev-pointers are correct.)
		void print_backward() const {
			// BLANK 12
		}
};

int main() {
	DoublyLinkedList<int> d;
	assert(d.is_empty());
	assert(d.size() == 0);

	d.push_back(2);
	d.push_back(3);
	d.push_front(1);          // list: 1 2 3
	assert(d.size() == 3);
	assert(d.front() == 1);
	assert(d.back() == 3);
	assert(d.find(2) == 1);
	assert(d.find(99) == -1);

	d.insert_at(1, 10);        // list: 1 10 2 3
	assert(d.size() == 4);
	assert(d.find(10) == 1);

	assert(d.pop_front() == 1); // list: 10 2 3
	assert(d.pop_back() == 3);  // list: 10 2
	assert(d.remove_at(0) == 10); // list: 2
	assert(d.size() == 1);
	assert(d.front() == d.back());

	assert(d.pop_front() == 2);
	assert(d.is_empty());

	// BLANK 13: add one test that exercises your empty-pop contract
	//           (the same way you did for Stack)

	// BLANK 14: add one test that calls print_backward() and visually
	//           confirms prev-pointers are wired correctly

	cout << "all asserts passed\n";
	return 0;
}

// BLANK 15 (one line, no code): which invariant must hold after EVERY
// mutation, and which method is the most likely place to break it?
//
