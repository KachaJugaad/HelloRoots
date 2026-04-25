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

bool containsDuplicate(vector<int>& nums) {
	unordered_map<int,int> g;
	for(int i=0;i<(int)nums.size();i++)
	{
		g[nums[i]]+=1;
		if(g[nums[i]]>1) 
			return true;
	}
	return false;
}

int main() {
    vector<int> a = {1, 2, 3, 1};
    vector<int> b = {1, 2, 3, 4};
    cout << containsDuplicate(a) << endl;  // expect 1
    cout << containsDuplicate(b) << endl;  // expect 0
    return 0;
}


