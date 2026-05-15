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
int lengthOfLongestSubstring(string s) {
	unordered_set<char> chars;
	int left =0; 
	int maxLen=0;
	for(int right=0;right<s.length();right++)
	{
		while(chars.count(s[right]))
		{
			chars.erase(s[left]);
			left++;
		}
		chars.insert(s[right]);
		maxLen=max(maxLen,right-left+1);
	}
	return maxLen;
}
int main() {
	cout << lengthOfLongestSubstring("abcabcbb") << endl;  // 3
	cout << lengthOfLongestSubstring("bbbbb") << endl;     // 1
	cout << lengthOfLongestSubstring("pwwkew") << endl;    // 3
	cout << lengthOfLongestSubstring("") << endl;          // 0
	return 0;
}
