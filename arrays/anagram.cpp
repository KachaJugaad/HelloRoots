#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

bool isAnagramOneHash(string s, string t) {
	// Approach: count character frequencies in both strings, compare.
	// Hashmap pattern.
	unordered_map<char,int> count;
	if(s.length() != t.length()) return false;
	for(int i=0;i<(int)s.length();i++)
	{
		count[s[i]]+=1;
		count[t[i]]-=1;
	}
	
	for (auto& [c, v] : count) {
		if (v != 0) return false;
	}
	return true;
}
bool isAnagram(string s, string t) {
	// Approach: count character frequencies in both strings, compare.
	// Hashmap pattern.
	unordered_map<char,int> src(0);
	unordered_map<char,int> dst(0);
	if(s.length() != t.length()) return false;
	for(int i=0;i<(int)s.length();i++)
	{
		src[s[i]]+=1;
		dst[t[i]]+=1;
	}
	return src==dst;
}

int main() {
    cout << isAnagram("anagram", "nagaram") << endl;  // expect 1 (true)
    cout << isAnagram("rat", "car") << endl;           // expect 0 (false)
    return 0;
}
