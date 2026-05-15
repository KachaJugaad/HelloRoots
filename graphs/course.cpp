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
    int numCourses = 4;
    vector<vector<int>> prerequisites = {{1,0}, {2,1}, {3,2}};
    
    // TODO: Create adjacency list
    vector<vector<int>> adj(numCourses);
    
    // TODO: Add edges from prerequisites
    // For each [a, b], add edge b → a
    // (because b is prerequisite of a, so b must come before a)
    
    for(auto pre : prerequisites) {
        int course = pre[0];      // 1, 2, 3
        int prereq = pre[1];      // 0, 1, 2
        adj[prereq].push_back(course);  // prereq → course
    }
    
    // Print the graph
    for(int i = 0; i < numCourses; i++) {
        cout << i << " → ";
        for(int j : adj[i]) {
            cout << j << " ";
        }
        cout << endl;
    }
    
    return 0;
}
