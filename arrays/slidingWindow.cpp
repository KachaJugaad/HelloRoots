#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int lengthOfLongestSubstring(string s) {
	unordered_set<char> window;
	int left = 0;
	int maxLen = 0;

	for (int right = 0; right < (int)s.length(); right++) {
		while(window.count(s[right])){
			window.erase(s[left]);
			left++;
		}
		window.insert(s[right]);
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
