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
int main() {
    unordered_map<char, char> match = {{')','('}, {']','['}, {'}','{'}};
    unordered_set<char> openers = {'(', '[', '{'};
    stack<char> s;
    string input = "{ashu(tosh}";
    bool valid = true;

    for (char c : input) {
        if (openers.count(c)) {
		s.push(c);
        }
        else if (match.count(c)) {
            if (
		/* BLANK 2: stack not empty AND top matches expected opener */) {
                // BLANK 3: safe to pop
            } else {
                valid = false;
                break;
            }
        }
        // else: not a bracket, skip
    }

    // BLANK 4: final answer. valid must be true AND what else about the stack?
    cout << (/* BLANK 4 */ ? "success" : "failure");
    return 0;
}
#if 0


int main() {
	unordered_map<char,char> match = {{')','('}, {']','['}, {'}','{'}};
	std::stack<char> s;
	string givenInput="{ashu(tosh}";


	for(char key: givenInput)
	{
		for(auto& p: match)
		{
			if(key == p.second)
			{
				cout<<"stack in: "<<key<<endl;
				s.push(key);
			}
			else if(key == p.first)
			{
				cout<<"stack out: "<<key<<endl;
				s.pop();
			}     
		}
	}

		cout<<((!s.size())?"success":"failure");// your code here

	return 0;

}
#endif


