#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <algorithm>
#include <climits>
#include <cstring>
using namespace std;
struct Entry {
    int key;
    int value;
    Entry* next;
    Entry(int k, int v) : key(k), value(v), next(nullptr) {}
};
class MyHashMap {
public:
    MyHashMap();              // Constructor
    void put(int key, int value);  // Insert or update
    int get(int key);              // Get value, or -1 if not found
    void remove(int key);          // Delete key-value pair
    bool contains(int key);        // Check if key exists
    size_t hash(int key) const {
	    int h = key % (int)capacity;
	    if (h < 0) h += capacity;
	    return (size_t)h;
    }
private:
    vector<Entry*> table;
    size_t capacity;
    size_t count;
    const float LOAD_THRESHOLD = 0.75f;
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // your code here

    return 0;
}
