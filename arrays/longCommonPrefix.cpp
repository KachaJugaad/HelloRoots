#include <iostream>
#include <vector>
#include <string>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
	// Approach: take strs[0] as a candidate prefix.
	// Walk character-by-character.
	// At position i, check if every other string has the same character.
	// If any mismatch or any string is shorter than i → stop.
	//std::stack s;
	string tmp = strs[0];

	for(int i=0;i<(int)strs[0].length();i++)
	{
		for(int j=1;j<(int)strs.size();j++)
			if(strs[j].length()>=i && strs[j][i] != strs[0][i])
			{	return	strs[0].substr(0,i);

			}
			else
			{
				//cout<<"strs[j][i]" << strs[j][i] << "\n  strs[i][j]" << strs[i][j]<<endl;
			} 

	}
	return strs[0];
}

int main() {
	vector<string> a = {"flower", "flow", "flight"};   // expect "fl"
	vector<string> b = {"dog", "racecar", "car"};      // expect ""
	vector<string> c = {"flower", "fl"};                // expect "fl"
	vector<string> d = {"abc", "abc", "abc"};          // expect "abc"	
	cout << longestCommonPrefix(a) << endl;   // expect "fl"
	cout << longestCommonPrefix(b) << endl;   // expect "" (empty line)
	cout << longestCommonPrefix(c) << endl;   // expect "fl"
	cout << longestCommonPrefix(d) << endl;   // expect "" (empty line)
	return 0;
}
