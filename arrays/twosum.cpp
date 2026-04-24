#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {

	unordered_map<int,int> seen;
	for(int i=0;i<nums.size();i++)
	{
		int complement = target-nums[i];
		if(seen.count(complement))
		{
			return {seen[complement],i};
		}
		seen[nums[i]]=i;
	}
	return {};
}

vector<int> two(vector<int>&nums, int target)
{
	for(int i = 0; i<nums.size();i++)
	{
		int complement = target - nums[i];
		std::vector<int>::iterator it;
		it = find (nums.begin()+i+1, nums.end(), complement);
		if (it != nums.end()){
			std::size_t index = std::distance(std::begin(nums), it);
			return {i,(int)index};
		}
#if 0
		for(int j = i+1; j<nums.size();j++)
		{
			if(complement == nums[j]) 
				cout<< "answer: " <<i <<"  "<<j<<endl; 
		}
#endif
	}

	return {};
}
int main() {
	vector<int> nums = {2, 7, 11, 15};
	int target = 9;
	//    vector<int> result = twoSum(nums, target);

	vector<int> result = two(nums, target);
	cout << result[0] << " " << result[1] << endl;
	return 0;
}
