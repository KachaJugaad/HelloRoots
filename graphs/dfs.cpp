#include <iostream>
#include <vector>
using namespace std;

void dfs(int u, vector<vector<int>>& adj, vector<bool>& visited) {
	visited[u]=true;
        cout<<u <<" ";
	
	for(int below=0;below<(int)adj[u].size();below++)
	{
		if(!visited[adj[u][below]])
		{
			dfs(adj[u][below], adj, visited);
		}
	}
	/*for (int neighbor : adj[u]) {
		if (!visited[neighbor]) {
			dfs(neighbor, adj, visited);
		}
	}*/
	// TODO:
	// 1. Mark visited[u] = true
	// 2. Print u followed by a space
	// 3. For each neighbor in adj[u]:
	//      if not visited: recursively call dfs(neighbor, adj, visited)



}

int main() {
	int n = 6;
	vector<vector<int>> adj(n);
	adj[0] = {1};
	adj[1] = {0, 2};
	adj[2] = {1};
	adj[3] = {4};
	adj[4] = {3, 5};
	adj[5] = {4};



	vector<bool> visited(n, false);

	dfs(0, adj, visited);
	cout << endl;

	return 0;
}
#if 0
int n = 6;
vector<vector<int>> adj(n);
adj[0] = {1};
adj[1] = {0, 2};
adj[2] = {1};
adj[3] = {4};
adj[4] = {3, 5};
adj[5] = {4};
    int n = 6;
    vector<vector<int>> adj(n);
    adj[0] = {1, 5};
    adj[1] = {0, 2};
    adj[2] = {1, 3};
    adj[3] = {2, 4};
    adj[4] = {3, 5};
    adj[5] = {0, 4};
#endif 
