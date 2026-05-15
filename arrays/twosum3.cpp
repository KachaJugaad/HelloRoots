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

vector<int> twoSum(vector<int>& numbers, int target) {
	int left, right; 
	left =0;
	right = numbers.size()-1;
	while(left<right)
	{
		int sum = numbers[left]+numbers[right]; 
		if(sum>target) right--;
		else if(sum<target) left++;
		else if(sum==target) return {left,right};
	}
return {};
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// your code here
	vector<int> numbers = {2,7,11,15};int target = 9;
	cout<<twoSum(numbers,target)[0]<<endl;
	cout<<twoSum(numbers,target)[1]<<endl;
	return 0;
}

