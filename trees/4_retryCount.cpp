#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// =========================================================
// YOUR CODE
// =========================================================
int getRetryCount(int gap, vector<string>& requestIds, vector<int>& timestamps) {
	unordered_map<string,int> check; 
	int retry=0;
	for(int i=0;i<(int)requestIds.size();i++)
	{
		if(check.find(requestIds[i]) == check.end())
		;
		else if(gap>=timestamps[i]-check[requestIds[i]])
		{
			retry++;
		}
		check[requestIds[i]]=timestamps[i];
	}	
	return retry;

}
// =========================================================

int main() {
    {
        vector<string> ids = {"r1", "r2", "r1", "r2", "r2"};
        vector<int> timestamps     = { 1,    3,    8,    15,   20};
        cout << "Test 1  expected 2  got " << getRetryCount(10, ids, timestamps) << endl;
    }
    {
        // No retries — all gaps too large
        vector<string> ids = {"r1", "r1", "r1"};
        vector<int> timestamps     = { 1,    100,  200};
        cout << "Test 2  expected 0  got " << getRetryCount(10, ids, timestamps) << endl;
    }
    {
        // All retries — same id, tight gaps
        vector<string> ids = {"r1", "r1", "r1", "r1"};
        vector<int> timestamps     = { 1,    2,    3,    4};
        cout << "Test 3  expected 3  got " << getRetryCount(10, ids, timestamps) << endl;
    }
    {
        // Different ids interleaved, none retry
        vector<string> ids = {"a", "b", "c", "d"};
        vector<int> timestamps     = { 1,   2,   3,   4};
        cout << "Test 4  expected 0  got " << getRetryCount(10, ids, timestamps) << endl;
    }
    {
        // Edge: gap exactly equal to threshold
        vector<string> ids = {"r1", "r1"};
        vector<int> timestamps     = { 5,    15};
        cout << "Test 5  expected 1  got " << getRetryCount(10, ids, timestamps) << endl;
    }
    {
        // Empty input
        vector<string> ids = {};
        vector<int> timestamps     = {};
        cout << "Test 6  expected 0  got " << getRetryCount(10, ids, timestamps) << endl;
    }
    return 0;
}
