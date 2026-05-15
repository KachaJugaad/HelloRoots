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


class NumArray {
private:
    vector<int> prefix;
    
public:
    NumArray(vector<int>& nums) {
        prefix.resize(nums.size() + 1, 0);
        
        for (int i = 0; i < nums.size(); i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        return prefix[right + 1] - prefix[left];
    }
};

int main() {
    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray* obj = new NumArray(nums);
    
    cout << "Test 1: " << obj->sumRange(0, 2) << " (expected: 1)" << endl;
    cout << "Test 2: " << obj->sumRange(2, 5) << " (expected: -1)" << endl;
    cout << "Test 3: " << obj->sumRange(0, 5) << " (expected: -3)" << endl;
    cout << "Test 4: " << obj->sumRange(0, 0) << " (expected: -2)" << endl;
    cout << "Test 5: " << obj->sumRange(5, 5) << " (expected: -1)" << endl;
    
    delete obj;
    return 0;
}
