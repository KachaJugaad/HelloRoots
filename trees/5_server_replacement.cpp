#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// =========================================================
// YOUR CODE
// =========================================================
int countReplacements(int n, vector<string>& serverIds, vector<string>& statuses) {
unordered_map<string,int> resetLogs;
int reset = 0;
for(int i=0;i<(int)serverIds.size();i++)
{
	if(statuses[i] == "error") 
	{
		resetLogs[serverIds[i]]+=1;
		if(resetLogs[serverIds[i]]==3){
			resetLogs[serverIds[i]]=0;reset++;
		}
	}
	else
	{
		resetLogs[serverIds[i]]=0;
	}
}

return reset;
}
#if 0
int countReplacements(int n, vector<string>& serverIds, vector<string>& statuses) {
unordered_map<string,int> resetLogs;
int reset = 0;
for(int i=0;i<(int)serverIds.size();i++)
{
	if(resetLogs.find(serverIds[i])==resetLogs.end())
		;
	if(statuses[i] == "error") 
	{
		resetLogs[serverIds[i]]+=1;
		if(resetLogs[serverIds[i]]==3){
			resetLogs[serverIds[i]]=0;reset++;
		}
	}

	else if(statuses[i] == "success")
	{
		resetLogs[serverIds[i]]+=1;
		if(resetLogs[serverIds[i]] == 1) 
		{
			resetLogs[serverIds[i]]=0;reset++;
		}
	}
}

return reset;
}
#endif
// =========================================================

int main() {
    {
        vector<string> ids = {"s1","s1","s2","s1","s1","s2","s2","s2"};
        vector<string> st  = {"error","error","error","error","error","success","error","error"};
        cout << "Test 1  expected 1  got " << countReplacements(2, ids, st) << endl;
    }
    {
        // Three errors in a row, then keep going
        vector<string> ids = {"s1","s1","s1","s1","s1","s1"};
        vector<string> st  = {"error","error","error","error","error","error"};
        cout << "Test 2  expected 2  got " << countReplacements(1, ids, st) << endl;
    }
    {
        // Success interrupts the streak before reaching 3
        vector<string> ids = {"s1","s1","s1","s1"};
        vector<string> st  = {"error","error","success","error"};
        cout << "Test 3  expected 0  got " << countReplacements(1, ids, st) << endl;
    }
    {
        // No errors at all
        vector<string> ids = {"s1","s2","s3"};
        vector<string> st  = {"success","success","success"};
        cout << "Test 4  expected 0  got " << countReplacements(3, ids, st) << endl;
    }
    {
        // Empty
        vector<string> ids = {};
        vector<string> st  = {};
        cout << "Test 5  expected 0  got " << countReplacements(0, ids, st) << endl;
    }
    {
        // Two servers each hit 3 errors
        vector<string> ids = {"s1","s2","s1","s2","s1","s2"};
        vector<string> st  = {"error","error","error","error","error","error"};
        cout << "Test 6  expected 2  got " << countReplacements(2, ids, st) << endl;
    }
    return 0;
}
