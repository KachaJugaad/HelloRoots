#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
    int left = 0;
    int right = numbers.size() - 1;
    while (left < right) {
	
	    int sum = numbers[left] + numbers[right];
		    if(sum > target) right--;
		    else if(sum < target) left++;
		    else if(sum == target) 
			return {left+1,right+1};
    }

    return {};
}

int main() {
    vector<int> a = {2, 7, 11, 15};
    vector<int> r1 = twoSum(a, 9);
    cout << r1[0] << " " << r1[1] << endl;   // expect: 1 2

    vector<int> b = {2, 3, 4};
    vector<int> r2 = twoSum(b, 6);
    cout << r2[0] << " " << r2[1] << endl;   // expect: 1 3
    return 0;
}
