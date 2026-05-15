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
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
	int left, right;
	left =0; right = k;
	cout<<nums.size()<<endl;
	vector<int> output;
	int start = left;int i;
	if(nums.size() == 1) {
	return {nums[0]};
	}
	if(nums.size() == 0) return {};
	while(left<nums.size()-k+1)
	{
		int maxValue=-1;
		for(i = left; i<right; i++)
		{
			maxValue = max(maxValue, nums[i]);
		}
		output.push_back(maxValue);
		maxValue=0;
		right = left + k + 1; 
		left+=1;
	}

	return output;;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int>nums = {-5769,-7887,-5709,4600,-7919,9807,1303,-2644,1144,-6410,-7159,-2041,9059,-663,4612,-257,2870,-6646,8161,3380,6823,1871,-4030,-1758,4834,-5317,6218,-4105,6869,8595,8718,-4141,-3893,-4259,-3440,-5426,9766,-5396,-7824,-3941,4600,-1485,-1486,-4530,-1636,-2088,-5295,-5383,5786,-9489,3180,-4575,-7043,-2153,1123,1750,-1347,-4299,-4401,-7772,5872,6144,-4953,-9934,8507,951,-8828,-5942,-3499,-174,7629,5877,3338,8899,4223,-8068,3775,7954,8740,4567,6280,-7687,-4811,-8094,2209,-4476,-8328,2385,-2156,7028,-3864,7272,-1199,-1397,1581,-9635,9087,-6262,-3061,-6083,-2825,-8574,5534,4006,-2691,6699,7558,-453,3492,3416,2218,7537,8854,-3321,-5489,-945,1302,-7176,-9201,-9588,-140,1369,3322,-7320,-8426,-8446,-2475,8243,-3324,8993,8315,2863,-7580,-7949,4400};//{1,3,-1,-3,5,3,6,7}; 
	int k = 6;
	maxSlidingWindow(nums,k);

	// your code here

	return 0;
}

