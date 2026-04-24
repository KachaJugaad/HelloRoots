// Drill: Single Number
// Every element appears twice except one. Find the one.
// Constraint: O(n) time, O(1) extra space.
//
// Example:
//   Input:  [4, 1, 2, 1, 2]
//   Output: 4

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int singleNumber(vector<int>& nums) {

	int result = 0;
	for(int i=0;i<nums.size();i++)
	{
		result ^= nums[i];
	}
	return result;
#if 0	
	queue<int> q;
	sort(nums.begin(),nums.end());
	q.push(nums[0]);
	for(int i=1;i<(int)nums.size();i++)
	{

		if(q.back() == nums[i]) {
			q.pop();
		}
		else {
			q.push(nums[i]);
		} 

	}
	return q.front();
#endif
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> nums = {4, 1, 2, 1, 2};
	cout << singleNumber(nums) << endl;  // expect 4

	return 0;
}
