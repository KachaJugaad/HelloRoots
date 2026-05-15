================================================================================
TODAY'S PRACTICE - TEMPLATE STUBS FOR EACH PATTERN
Fill these in as you solve each problem
================================================================================

================================================================================
PATTERN 1: TWO POINTERS (20 min)
LeetCode 167 - Two Sum II Input Array Is Sorted
================================================================================

#include <iostream>
#include <vector>
using namespace std;

// PROBLEM: Given sorted array and target, find two numbers that add to target
// Return 1-indexed positions [index1, index2]
// Example: nums = [2,7,11,15], target = 9 → [1,2]

vector<int> twoSum(vector<int>& numbers, int target) {
    // BLANK 1: Implement two pointer approach
    // left = 0, right = n-1
    // while left < right:
    //   sum = numbers[left] + numbers[right]
    //   if sum == target: return [left+1, right+1]  (1-indexed!)
    //   if sum < target: left++
    //   else: right--
    // return [] (not found)
    
    int left = 0, right = numbers.size() - 1;
    
    while (left < right) {
        int sum = numbers[left] + numbers[right];
        
        if (sum == target) {
            return {left + 1, right + 1};  // 1-indexed
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }
    
    return {};
}

int main() {
    // Test 1
    vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    auto result1 = twoSum(nums1, target1);
    cout << "Test 1: [" << result1[0] << ", " << result1[1] << "]" << endl;
    cout << "Expected: [1, 2]" << endl << endl;
    
    // Test 2
    vector<int> nums2 = {2, 3, 4};
    int target2 = 6;
    auto result2 = twoSum(nums2, target2);
    cout << "Test 2: [" << result2[0] << ", " << result2[1] << "]" << endl;
    cout << "Expected: [1, 3]" << endl << endl;
    
    // Test 3
    vector<int> nums3 = {-1, 0};
    int target3 = -1;
    auto result3 = twoSum(nums3, target3);
    cout << "Test 3: [" << result3[0] << ", " << result3[1] << "]" << endl;
    cout << "Expected: [1, 2]" << endl;
    
    return 0;
}

// Compile: g++ -std=c++17 -Wall two_pointers.cpp -o two_pointers
// Run: ./two_pointers

================================================================================
PATTERN 2: SLIDING WINDOW (30 min)
LeetCode 3 - Longest Substring Without Repeating Characters
================================================================================

#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

// PROBLEM: Find length of longest substring without repeating characters
// Example: "abcabcbb" → 3 (substring "abc")
// Example: "bbbbb" → 1 (substring "b")
// Example: "pwwkew" → 3 (substring "wke")

int lengthOfLongestSubstring(string s) {
    // BLANK 2: Implement sliding window
    // Use HashMap to track last seen position of each character
    // Use two pointers [left, right]
    // For each character at right:
    //   - Update last seen position
    //   - While character appears before left:
    //     - Move left forward past duplicate
    //   - Update max length
    
    unordered_map<char, int> last_seen;
    int left = 0;
    int max_length = 0;
    
    for (int right = 0; right < s.length(); right++) {
        char current = s[right];
        
        // If character was seen after left, move left past it
        if (last_seen.count(current) && last_seen[current] >= left) {
            left = last_seen[current] + 1;
        }
        
        // Update last seen position
        last_seen[current] = right;
        
        // Update max length
        max_length = max(max_length, right - left + 1);
    }
    
    return max_length;
}

int main() {
    // Test 1
    string s1 = "abcabcbb";
    cout << "Test 1: '" << s1 << "'" << endl;
    cout << "Result: " << lengthOfLongestSubstring(s1) << endl;
    cout << "Expected: 3" << endl << endl;
    
    // Test 2
    string s2 = "bbbbb";
    cout << "Test 2: '" << s2 << "'" << endl;
    cout << "Result: " << lengthOfLongestSubstring(s2) << endl;
    cout << "Expected: 1" << endl << endl;
    
    // Test 3
    string s3 = "pwwkew";
    cout << "Test 3: '" << s3 << "'" << endl;
    cout << "Result: " << lengthOfLongestSubstring(s3) << endl;
    cout << "Expected: 3" << endl << endl;
    
    // Test 4
    string s4 = "au";
    cout << "Test 4: '" << s4 << "'" << endl;
    cout << "Result: " << lengthOfLongestSubstring(s4) << endl;
    cout << "Expected: 2" << endl << endl;
    
    // Test 5
    string s5 = "dvdf";
    cout << "Test 5: '" << s5 << "'" << endl;
    cout << "Result: " << lengthOfLongestSubstring(s5) << endl;
    cout << "Expected: 3" << endl;
    
    return 0;
}

// Compile: g++ -std=c++17 -Wall sliding_window.cpp -o sliding_window
// Run: ./sliding_window

================================================================================
PATTERN 3: BINARY SEARCH (25 min)
LeetCode 33 - Search in Rotated Sorted Array
================================================================================

#include <iostream>
#include <vector>
using namespace std;

// PROBLEM: Search for target in rotated sorted array
// Array was rotated at some pivot: [0,1,2,4,5,6,7] → [4,5,6,7,0,1,2]
// Example: nums = [4,5,6,7,0,1,2], target = 0 → 4

int search(vector<int>& nums, int target) {
    // BLANK 3: Implement binary search on rotated array
    // Key insight: One half is always properly sorted
    // Check which half is sorted, then decide which half to search
    
    int left = 0, right = nums.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] == target) {
            return mid;
        }
        
        // Determine which half is sorted
        if (nums[left] <= nums[mid]) {
            // Left half is sorted
            if (nums[left] <= target && target < nums[mid]) {
                // Target in left half
                right = mid - 1;
            } else {
                // Target in right half
                left = mid + 1;
            }
        } else {
            // Right half is sorted
            if (nums[mid] < target && target <= nums[right]) {
                // Target in right half
                left = mid + 1;
            } else {
                // Target in left half
                right = mid - 1;
            }
        }
    }
    
    return -1;  // Not found
}

int main() {
    // Test 1
    vector<int> nums1 = {4, 5, 6, 7, 0, 1, 2};
    int target1 = 0;
    cout << "Test 1: [4,5,6,7,0,1,2], target=0" << endl;
    cout << "Result: " << search(nums1, target1) << endl;
    cout << "Expected: 4" << endl << endl;
    
    // Test 2
    vector<int> nums2 = {4, 5, 6, 7, 0, 1, 2};
    int target2 = 3;
    cout << "Test 2: [4,5,6,7,0,1,2], target=3" << endl;
    cout << "Result: " << search(nums2, target2) << endl;
    cout << "Expected: -1" << endl << endl;
    
    // Test 3
    vector<int> nums3 = {1};
    int target3 = 1;
    cout << "Test 3: [1], target=1" << endl;
    cout << "Result: " << search(nums3, target3) << endl;
    cout << "Expected: 0" << endl << endl;
    
    // Test 4
    vector<int> nums4 = {1, 3};
    int target4 = 3;
    cout << "Test 4: [1,3], target=3" << endl;
    cout << "Result: " << search(nums4, target4) << endl;
    cout << "Expected: 1" << endl;
    
    return 0;
}

// Compile: g++ -std=c++17 -Wall binary_search.cpp -o binary_search
// Run: ./binary_search

================================================================================
PATTERN 4: PREFIX SUM (15 min)
LeetCode 303 - Range Sum Query - Immutable
================================================================================

#include <iostream>
#include <vector>
using namespace std;

// PROBLEM: Given array, answer multiple range sum queries efficiently
// Example: nums = [-2, 0, 3, -5, 2, -1]
//   sumRange(0, 2) → -2+0+3 = 1
//   sumRange(2, 5) → 3+(-5)+2+(-1) = -1

class NumArray {
private:
    vector<int> prefix;
    
public:
    NumArray(vector<int>& nums) {
        // BLANK 4: Build prefix sum array
        // prefix[i] = sum of all elements from 0 to i-1
        // prefix[0] = 0
        // prefix[i] = prefix[i-1] + nums[i-1]
        
        prefix.resize(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        // BLANK 5: Query using prefix sum
        // return prefix[right+1] - prefix[left]
        
        return prefix[right + 1] - prefix[left];
    }
};

int main() {
    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray* obj = new NumArray(nums);
    
    cout << "Array: [-2, 0, 3, -5, 2, -1]" << endl << endl;
    
    cout << "Test 1: sumRange(0, 2)" << endl;
    cout << "Result: " << obj->sumRange(0, 2) << endl;
    cout << "Expected: 1 (-2+0+3)" << endl << endl;
    
    cout << "Test 2: sumRange(2, 5)" << endl;
    cout << "Result: " << obj->sumRange(2, 5) << endl;
    cout << "Expected: -1 (3+(-5)+2+(-1))" << endl << endl;
    
    cout << "Test 3: sumRange(0, 5)" << endl;
    cout << "Result: " << obj->sumRange(0, 5) << endl;
    cout << "Expected: -3 (sum of all)" << endl;
    
    delete obj;
    return 0;
}

// Compile: g++ -std=c++17 -Wall prefix_sum.cpp -o prefix_sum
// Run: ./prefix_sum

================================================================================
PATTERN 5: MONOTONIC STACK (40 min)
LeetCode 84 - Largest Rectangle in Histogram
================================================================================

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

// PROBLEM: Find largest rectangle area in histogram
// Example: heights = [2,1,5,6,2,3] → 10 (rectangle of height 5-6, width 2)
// [This is complex - take time to understand]

int largestRectangleArea(vector<int>& heights) {
    // BLANK 6: Implement monotonic stack approach
    // Intuition:
    //   For each bar, we want to know:
    //     - How far left we can extend (until we hit smaller bar)
    //     - How far right we can extend (until we hit smaller bar)
    //   Use monotonic stack to find these boundaries in O(n)
    //
    // Algorithm:
    //   Maintain stack of indices in increasing height order
    //   For each bar:
    //     - While bar shorter than stack top:
    //       - Pop stack and calculate area for popped bar
    //       - The popped bar's width extends from next_stack_top to current
    //     - Push current bar's index
    //   Pop remaining bars and calculate areas
    
    stack<int> st;
    int max_area = 0;
    
    for (int i = 0; i < heights.size(); i++) {
        while (!st.empty() && heights[st.top()] > heights[i]) {
            int h_index = st.top();
            st.pop();
            
            int height = heights[h_index];
            int width = st.empty() ? i : i - st.top() - 1;
            int area = height * width;
            
            max_area = max(max_area, area);
        }
        st.push(i);
    }
    
    // Pop remaining bars
    while (!st.empty()) {
        int h_index = st.top();
        st.pop();
        
        int height = heights[h_index];
        int width = st.empty() ? (int)heights.size() : (int)heights.size() - st.top() - 1;
        int area = height * width;
        
        max_area = max(max_area, area);
    }
    
    return max_area;
}

int main() {
    cout << "===== Monotonic Stack: Largest Rectangle =====" << endl << endl;
    
    // Test 1
    vector<int> heights1 = {2, 1, 5, 6, 2, 3};
    cout << "Test 1: [2,1,5,6,2,3]" << endl;
    cout << "Result: " << largestRectangleArea(heights1) << endl;
    cout << "Expected: 10 (rectangle 5x2 or 6x1+5x1)" << endl << endl;
    
    // Test 2
    vector<int> heights2 = {2, 4};
    cout << "Test 2: [2,4]" << endl;
    cout << "Result: " << largestRectangleArea(heights2) << endl;
    cout << "Expected: 4" << endl << endl;
    
    // Test 3
    vector<int> heights3 = {1};
    cout << "Test 3: [1]" << endl;
    cout << "Result: " << largestRectangleArea(heights3) << endl;
    cout << "Expected: 1" << endl;
    
    return 0;
}

// Compile: g++ -std=c++17 -Wall monotonic_stack.cpp -o monotonic_stack
// Run: ./monotonic_stack

================================================================================
HOW TO USE THESE TEMPLATES
================================================================================

For each pattern:

1. Copy the template code
2. Try to fill in the BLANK(s) yourself
3. Compile and run
4. If wrong, look at my solution (already in template!)
5. Understand why solution works
6. Move to next pattern

Templates include:
  ✅ Complete solution (already coded for you)
  ✅ Test cases (to verify)
  ✅ Expected output (to check)

You should:
  ✅ Cover the code and try first
  ✅ Run tests to check
  ✅ Understand the approach

================================================================================
QUICK REFERENCE: What to know about each pattern
================================================================================

Two Pointers:
  - Left and right converge
  - Works on SORTED arrays
  - O(n) time

Sliding Window:
  - Two pointers, window size varies
  - Expand/contract based on condition
  - Track state in window (HashMap, count, etc.)
  - O(n) time

Binary Search:
  - Divide and conquer
  - Works on SORTED or MONOTONIC data
  - "Which half to search" is the key insight
  - O(log n) time

Prefix Sum:
  - Precompute cumulative sums
  - Answer range queries in O(1)
  - Saves time if multiple queries
  - O(n) preprocessing, O(1) per query

Monotonic Stack:
  - Stack maintains increasing/decreasing order
  - Pop when violated, calculate area/distance
  - O(n) total (each element pushed/popped once)
  - Hardest to understand, but elegant

================================================================================
