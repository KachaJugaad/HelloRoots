#include <iostream>
#include <vector>
#include <stdexcept>
#include <cassert>
using namespace std;

template <typename T>
class Stack {
	public:
		void push(const T& value) {
			data.push_back(value); 
		}

		T pop() {
			// BLANK 2: empty-case contract — pick one (throw / sentinel / assert) and stick with it
			// BLANK 3: remove last element and return it
			assert(!data.empty());
			T tmp = data.back();
			data.pop_back();
			return tmp;
		}

		const T& peek() const {
			// BLANK 4: empty-case contract (must match pop's choice)
			// BLANK 5: return reference to last element
			return data.back();
		}

		bool is_empty() const {
			// BLANK 6
			return (data.empty())? true:false;
		}

		size_t size() const {
			// BLANK 7
			return data.size();
		}

	private:
		vector<T> data;
};

int main() {
	Stack<int> s;
	assert(s.is_empty());
	assert(s.size() == 0);

	s.push(1); s.push(2); s.push(3);
	assert(s.size() == 3);
	assert(s.peek() == 3);
	assert(s.pop() == 3);
	assert(s.pop() == 2);
	assert(s.size() == 1);
	assert(!s.is_empty());
	assert(s.pop() == 1);
	assert(s.is_empty());

	// BLANK 8: add one test that exercises your empty-pop contract

	cout << "all asserts passed\n";
	return 0;
}

// BLANK 9 (one line, no code): how would you make this thread-safe?
//
