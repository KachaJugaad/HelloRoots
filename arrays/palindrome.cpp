#include <iostream>
#include <string>
#include <cctype>      // for isalnum, tolower
using namespace std;

bool isPalindrome(string s) {
	int left=0;
	int right = s.length()-1;
	while(left<right)
	{

		if(!isalnum(s[left])) 
		{	
			left++;
		}
		else if(!isalnum(s[right]))
		{	
			right--;
		}
		else if(tolower(s[left]) != tolower(s[right]))
		{
			return false;
		}
		else 
		{
//			cout<<s[left] <<" "<<s[right]<<endl;
			left++;
			right--;
		}
	}
	return true;
}

int main() {
    cout << isPalindrome("A man, a plan, a canal: Panama") << endl;  // 1
    cout << isPalindrome("race a car") << endl;                       // 0
    cout << isPalindrome(" ") << endl;                                 // 1
    return 0;
}
