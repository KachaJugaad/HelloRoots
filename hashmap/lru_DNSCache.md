================================================================================
LRU CACHE ARCHITECTURE - Your Design
HashMap with Separate Chaining + Doubly-Linked List
================================================================================

YOUR DESIGN INSIGHT:
────────────────────
1. HashMap: array of size = Max_limit_LRU
2. Each bucket: head of doubly-linked list (separate chaining for collisions)
3. Every Node: has DLL pointers (prev/next) for collision chain
4. Every Node: has DLL pointers (prev_lru/next_lru) for LRU order

This is SOPHISTICATED! You're combining:
  - Hash map (for O(1) lookup)
  - Separate chaining (for collision handling)
  - DLL (for LRU eviction order)

================================================================================
DATA STRUCTURE DEFINITION
================================================================================

struct UrlRecord {
    int key;
    string value;
    
    // Pointers for COLLISION CHAIN (within same hash bucket)
    UrlRecord* next_chain;      // Next in collision chain
    UrlRecord* prev_chain;      // Prev in collision chain
    
    // Pointers for LRU ORDER (global across all buckets)
    UrlRecord* next_lru;        // More recently used
    UrlRecord* prev_lru;        // Less recently used
    
    UrlRecord(int k, string v) {
        key = k;
        value = v;
        next_chain = nullptr;
        prev_chain = nullptr;
        next_lru = nullptr;
        prev_lru = nullptr;
    }
};

class LRUCache {
private:
    vector<UrlRecord*> hash_table;      // Array of buckets (heads of chains)
    int max_limit_lru;                   // Capacity
    int current_size;                    // Current entries
    
    // LRU order pointers (doubly-linked list)
    UrlRecord* lru_head;                 // Most recently used
    UrlRecord* lru_tail;                 // Least recently used
    
public:
    LRUCache(int capacity) { }
    
    // Hash function
    int hash(int key) { }
    
    // Operations
    string get(int key) { }
    void insert(int key, string value) { }
    void deleteKey(int key) { }
    
private:
    // Helper: Find node in collision chain
    UrlRecord* findInChain(int bucket_index, int key) { }
    
    // Helper: Move node to head of LRU (mark as recently used)
    void moveToHead(UrlRecord* node) { }
    
    // Helper: Remove from LRU order
    void removeFromLRU(UrlRecord* node) { }
    
    // Helper: Evict LRU node
    void evictLRU() { }
};

================================================================================
DETAILED OPERATION WALKTHROUGH
================================================================================

EXAMPLE:
────────
Max_limit_lru = 4 (hash table size 4, so indices 0-3)

Hash function: hash(key) = key % max_limit_lru

Initial state:
  hash_table[0] = nullptr
  hash_table[1] = nullptr
  hash_table[2] = nullptr
  hash_table[3] = nullptr
  
  lru_head = nullptr
  lru_tail = nullptr

════════════════════════════════════════════════════════════════════════════════

OPERATION 1: insert(5, "url_five")
──────────────────────────────────

Step 1: Calculate bucket
  bucket = hash(5) = 5 % 4 = 1

Step 2: Create new node
  node = UrlRecord(5, "url_five")

Step 3: Insert into collision chain at bucket 1
  hash_table[1] = node  (was nullptr, now points to new node)

Step 4: Insert into LRU order (at head = most recently used)
  node->next_lru = lru_head  (currently nullptr)
  node->prev_lru = nullptr
  lru_head = node
  lru_tail = node  (first node, so also tail)

State after:
  hash_table[1] → [Node: key=5, value="url_five"] → nullptr
  
  LRU Order: [5] ← most recent | least recent →
  
  current_size = 1

════════════════════════════════════════════════════════════════════════════════

OPERATION 2: insert(9, "url_nine")
──────────────────────────────────

Step 1: Calculate bucket
  bucket = hash(9) = 9 % 4 = 1  (COLLISION with key=5!)

Step 2: Create new node
  node = UrlRecord(9, "url_nine")

Step 3: Insert into collision chain at bucket 1
  Current: hash_table[1] → [5] → nullptr
  Insert at head of chain:
    node->next_chain = hash_table[1]  (points to 5)
    hash_table[1] = node  (points to 9 now)
  
  Result: hash_table[1] → [9] → [5] → nullptr

Step 4: Insert into LRU order (at head)
  node->next_lru = lru_head  (currently node 5)
  node->prev_lru = nullptr
  lru_head->prev_lru = node  (node 5 updates)
  lru_head = node
  
State after:
  hash_table[0] = nullptr
  hash_table[1] → [9] → [5] → nullptr
  hash_table[2] = nullptr
  hash_table[3] = nullptr
  
  LRU Order: [9] ← most recent | [5] ← least recent
  
  current_size = 2

════════════════════════════════════════════════════════════════════════════════

OPERATION 3: get(5)
───────────────────

Step 1: Calculate bucket
  bucket = hash(5) = 5 % 4 = 1

Step 2: Find node in collision chain
  Traverse chain at bucket 1:
    Node 9: key=9, not match
    Node 5: key=5, MATCH! Return value="url_five"

Step 3: Move to head (mark as recently used)
  Current LRU: [9] ← head | [5] ← tail
  
  After moveToHead(node_5):
    Remove 5 from its current position:
      5->prev_lru = nullptr (already at tail end, nothing before)
      5->next_lru = nullptr (already at tail)
    
    Actually, 5 is at TAIL. Need to remove from tail position:
      9->next_lru = nullptr (5 was after 9, now gone)
    
    Insert 5 at HEAD:
      5->next_lru = 9
      5->prev_lru = nullptr
      9->prev_lru = 5
      lru_head = 5
  
  Result LRU: [5] ← head (most recent) | [9] ← tail (least recent)

════════════════════════════════════════════════════════════════════════════════

OPERATION 4: insert(13, "url_thirteen")
────────────────────────────────────────

Step 1: Calculate bucket
  bucket = hash(13) = 13 % 4 = 1  (ANOTHER COLLISION!)

Step 2: Create new node
  node = UrlRecord(13, "url_thirteen")

Step 3: Insert into collision chain at bucket 1
  Current: hash_table[1] → [9] → [5] → nullptr
  Insert at head:
    node->next_chain = hash_table[1]  (points to 9)
    hash_table[1] = node  (points to 13)
  
  Result: hash_table[1] → [13] → [9] → [5] → nullptr

Step 4: Insert into LRU order (at head)
  Current LRU: [5] ← head | [9] ← tail
  
  New node 13 at head:
    13->next_lru = 5
    13->prev_lru = nullptr
    5->prev_lru = 13
    lru_head = 13
  
  Result LRU: [13] ← head | [5] | [9] ← tail

State after:
  hash_table[1] → [13] → [9] → [5] → nullptr
  LRU Order: [13] ← most recent ... [9] ← least recent
  current_size = 3

════════════════════════════════════════════════════════════════════════════════

OPERATION 5: insert(1, "url_one")
──────────────────────────────────

Step 1: Calculate bucket
  bucket = hash(1) = 1 % 4 = 1  (YET ANOTHER COLLISION!)

Step 2-4: Same as above, insert in chain and LRU

State after:
  hash_table[1] → [1] → [13] → [9] → [5] → nullptr
  LRU Order: [1] ← most recent ... [9], [5] ← least recent
  current_size = 4

current_size == max_limit_lru, so cache is FULL!

════════════════════════════════════════════════════════════════════════════════

OPERATION 6: insert(17, "url_seventeen")
──────────────────────────────────────────

Step 1: Calculate bucket
  bucket = hash(17) = 17 % 4 = 1  (COLLISION AGAIN)

Step 2: Create new node
  node = UrlRecord(17, "url_seventeen")

Step 3a: Check if cache is full
  current_size == max_limit_lru? YES!
  
  Call evictLRU():
    Evict tail: node_9 (least recently used)
    
    Remove from LRU chain:
      5->prev_lru = nullptr  (9 was removed, 5 is now tail)
      lru_tail = 5
    
    Remove from hash collision chain at bucket 1:
      hash_table[1] → [1] → [13] → [5] → nullptr (9 removed)
    
    Free memory: delete node_9
    current_size = 3

Step 3b: Insert new node
  Insert 17 in collision chain at bucket 1:
    hash_table[1] → [17] → [1] → [13] → [5] → nullptr

Step 4: Insert in LRU order
  17->next_lru = lru_head  (1)
  17->prev_lru = nullptr
  lru_head->prev_lru = 17
  lru_head = 17

State after:
  hash_table[1] → [17] → [1] → [13] → [5] → nullptr
  LRU Order: [17] ← head (most recent) ... [5] ← tail (least recent)
  current_size = 4

════════════════════════════════════════════════════════════════════════════════

KEY INSIGHTS FROM YOUR DESIGN:
──────────────────────────────

1. TWO SEPARATE DLL CHAINS
   - Collision chain: all keys hashing to same bucket
   - LRU chain: all keys in order of recency (global)
   
   These are INDEPENDENT!
   Node 9 might be:
     - In collision chain at bucket 1 (with 1, 13, 5, 17)
     - In LRU chain (position based on last access)

2. O(1) OPERATIONS
   - get(key): O(1) hash, O(k) chain traversal (k = collision count)
     In practice, with good hash function, k ≈ O(1)
   
   - insert(key): O(1) hash, O(1) insert in chains
   
   - delete(key): O(1) hash, O(k) chain traversal, O(1) removal
   
   - evict: O(1) remove tail from LRU order

3. SPACE
   O(max_limit_lru) for hash table + O(n) for nodes

================================================================================
FUNCTION SIGNATURES (Clean Code)
================================================================================

// Hash function based on capacity
// With negative key handling
int hash(int key) {
    int h = key % max_limit_lru;
    if (h < 0) h += max_limit_lru;
    return h;
}

// Find node in collision chain at given bucket
UrlRecord* findInChain(int bucket_index, int key) {
    UrlRecord* current = hash_table[bucket_index];
    while (current != nullptr) {
        if (current->key == key) {
            return current;
        }
        current = current->next_chain;
    }
    return nullptr;  // Not found
}

// Get value (and mark as recently used)
string get(int key) {
    int bucket = hash(key);
    UrlRecord* node = findInChain(bucket, key);
    
    if (node == nullptr) {
        return "";  // Not found
    }
    
    // Mark as recently used (move to head of LRU)
    moveToHead(node);
    
    return node->value;
}

// Insert or update
void insert(int key, string value) {
    int bucket = hash(key);
    UrlRecord* node = findInChain(bucket, key);
    
    // If key exists, update and mark recently used
    if (node != nullptr) {
        node->value = value;
        moveToHead(node);
        return;
    }
    
    // Key doesn't exist, create new node
    node = new UrlRecord(key, value);
    
    // Evict if cache is full
    if (current_size == max_limit_lru) {
        evictLRU();
    }
    
    // Insert into collision chain at head
    node->next_chain = hash_table[bucket];
    if (hash_table[bucket] != nullptr) {
        hash_table[bucket]->prev_chain = node;
    }
    hash_table[bucket] = node;
    
    // Insert into LRU chain at head
    node->next_lru = lru_head;
    node->prev_lru = nullptr;
    if (lru_head != nullptr) {
        lru_head->prev_lru = node;
    }
    lru_head = node;
    if (lru_tail == nullptr) {
        lru_tail = node;
    }
    
    current_size++;
}

// Move node to head of LRU (mark as recently used)
void moveToHead(UrlRecord* node) {
    if (node == lru_head) {
        return;  // Already at head
    }
    
    // Remove from current position
    if (node->prev_lru != nullptr) {
        node->prev_lru->next_lru = node->next_lru;
    }
    if (node->next_lru != nullptr) {
        node->next_lru->prev_lru = node->prev_lru;
    }
    if (node == lru_tail) {
        lru_tail = node->prev_lru;
    }
    
    // Insert at head
    node->next_lru = lru_head;
    node->prev_lru = nullptr;
    if (lru_head != nullptr) {
        lru_head->prev_lru = node;
    }
    lru_head = node;
}

// Evict least recently used node
void evictLRU() {
    if (lru_tail == nullptr) return;
    
    UrlRecord* node_to_evict = lru_tail;
    
    // Remove from LRU chain
    removeFromLRU(node_to_evict);
    
    // Remove from collision chain
    int bucket = hash(node_to_evict->key);
    UrlRecord* current = hash_table[bucket];
    
    if (current == node_to_evict) {
        hash_table[bucket] = current->next_chain;
    } else {
        while (current != nullptr) {
            if (current->next_chain == node_to_evict) {
                current->next_chain = node_to_evict->next_chain;
                break;
            }
            current = current->next_chain;
        }
    }
    
    delete node_to_evict;
    current_size--;
}

================================================================================
EDGE CASES TO HANDLE
================================================================================

1. Cache capacity = 1
   - Only one item at a time
   - Every insert evicts previous

2. All items hash to same bucket
   - Long collision chain
   - Hash function is poor (but still works, just slower)

3. Get non-existent key
   - Return empty string or -1 or handle gracefully

4. Insert duplicate key
   - Update value
   - Mark as recently used (move to head)

5. Empty cache
   - lru_head = nullptr
   - lru_tail = nullptr

6. Memory leaks
   - When evicting, must delete node
   - Destructor must clean up all nodes

================================================================================
TESTING STRATEGY
================================================================================

Test 1: Basic insert + get
  insert(1, "a")
  insert(2, "b")
  assert(get(1) == "a")
  assert(get(2) == "b")

Test 2: LRU eviction
  capacity = 2
  insert(1, "a")
  insert(2, "b")
  insert(3, "c")  ← evicts 1
  assert(get(1) == "")  ← 1 is gone
  assert(get(2) == "b")
  assert(get(3) == "c")

Test 3: Collision handling
  capacity = 2
  insert(1, "a")
  insert(3, "c")  ← hash to same bucket if capacity = 2
  assert(get(1) == "a")
  assert(get(3) == "c")

Test 4: Move to head on get
  capacity = 3
  insert(1, "a")
  insert(2, "b")
  insert(3, "c")
  get(1)  ← moves 1 to head
  insert(4, "d")  ← evicts 2 (was least recent after 1 moved)
  assert(get(2) == "")  ← 2 is gone
  assert(get(1) == "a")  ← 1 still there

Test 5: Update existing key
  capacity = 2
  insert(1, "a")
  insert(1, "updated_a")  ← update, not new
  assert(current_size == 1)  ← not 2!
  assert(get(1) == "updated_a")

================================================================================
COMPILE & TEST COMMANDS
================================================================================

g++ -std=c++17 -Wall -Wextra lru_cache.cpp -o lru_cache
./lru_cache

================================================================================
