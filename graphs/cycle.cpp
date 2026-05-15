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

bool hasCycle(int node, vector<vector<int>>& adj, vector<int>& color) {
	// TODO:
	// 1. If color[node] == 1 (GRAY), return true (cycle found!)
	// 2. If color[node] == 2 (BLACK), return false (already processed)
	// 3. Mark color[node] = 1 (GRAY - in progress)
	// 4. For each neighbor, recursively check hasCycle
	// 5. If any neighbor returns true, return true
	// 6. Mark color[node] = 2 (BLACK - done)
	// 7. Return false (no cycle from this node)
	if(color[node] == 1) return true;
	if(color[node] == 2) return false;
	color[node]=1;
	for(int neighbor=0;neighbor<(int)adj[node].size();neighbor++)
	{
		if(hasCycle(adj[node][neighbor],adj,color)) return true;
	}
	color[node]=2;
	return false;
}

int main() {
    int numCourses = 4;
    vector<vector<int>> adj = {{1}, {2}, {3}, {}};  // From previous step
    
    vector<int> color(numCourses, 0);  // All WHITE initially
    
    // Check each node
    for(int i = 0; i < numCourses; i++) {
        if(color[i] == 0) {  // If unvisited
            if(hasCycle(i, adj, color)) {
                cout << "Cycle detected!" << endl;
                return 0;
            }
        }
    }
    
    cout << "No cycle. Can take all courses." << endl;
    return 0;
}
