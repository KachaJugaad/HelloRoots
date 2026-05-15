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

void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j) {

	if(i<0 || i>=(int)grid.size() || j<0 ||j>=(int)grid[0].size()) return; 
	if(visited[i][j] || grid[i][j]=='0') return;
	
	visited[i][j]=true;
	cout << "visited " << i << ":" << j << endl; 

//UP
			dfs(grid,visited,i-1,j);
//down
			dfs(grid,visited,i+1,j);
//left
			dfs(grid,visited,i,j-1);
//right
			dfs(grid,visited,i,j+1);
}

int main() {
	vector<vector<char>> grid = {
		{'1', '0', '1'},
		{'0', '1', '0'},
		{'1', '0', '1'}
	};

	vector<vector<bool>> visited(3, vector<bool>(3, false));
	int island =0;
	for(int i = 0;i<(int)grid.size();i++)
	{
		for(int j = 0; j<(int)grid[0].size();j++)
		{
			if(!visited[i][j] && grid[i][j]=='1') {

				dfs(grid,visited,i,j);
				island++;

			}
		}
	}
	cout<<"total Islands "<< island<<endl;
	return 0;
}
