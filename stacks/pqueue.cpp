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
class Solution {
	public:
		int findKthLargest(vector<int>& nums, int k) {
			priority_queue<int,vector<int>> pq(nums.begin(),nums.end());
			k=k-1;
			while(k>0){
				pq.pop();
				k--;
			}

			return pq.top();
		}
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int>nums={3,2,1,5,6,4};int k =2;
	// your code here
	Solution sol;
	cout<<sol.findKthLargest(nums, k)<<endl;

	return 0;
}

