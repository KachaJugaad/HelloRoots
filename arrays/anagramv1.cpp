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
bool isAnagram(string s, string t) {
    if (s.length() != t.length()) return false;

    unordered_map<char, int> count;
    for (int i = 0; i < (int)s.length(); i++) {
        count[s[i]]++;
        count[t[i]]--;
    }

    // Now check: are all values in `count` zero?
    for (auto& [c, v] : count) {
        if (v != 0) return false;
    }
    return true;
}
int main() {
    cout << isAnagram("anagram", "nagaram") << endl;  // expect 1 (true)
    cout << isAnagram("rat", "car") << endl;           // expect 0 (false)
    return 0;
}
