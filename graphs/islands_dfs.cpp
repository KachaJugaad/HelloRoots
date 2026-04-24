#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(int sr, int sc, vector<vector<char>>& grid,
		vector<vector<bool>>& visited, int m, int n) {
	queue<pair<int,int>> q;
	q.push({sr,sc});
	visited[sr][sc]=true; 

	int dr[]={-1,1,0,0};
	int dc[]={0,0,-1,1};

	while(!q.empty()){
		auto[r,c]=q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];     // neighbor row
			int nc = c + dc[i];     // neighbor col

			if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc] == '1'  && !visited[nr][nc]) 	// bounds + land + visited check, same code once
			{
				visited[nr][nc]=true;
				q.push({nr,nc});
			}
		}
	}
}

void dfs(int r, int c, vector<vector<char>>& grid, vector<vector<bool>>& visited, int m, int n) {
    // TODO:
    // 1. Mark visited[r][c] = true
    // 2. Define dr[] and dc[]
    // 3. For each of 4 directions:
    //      compute (nr, nc)
    //      if in-bounds AND grid[nr][nc]=='1' AND !visited[nr][nc]:
    //          call dfs(nr, nc, grid, visited, m, n) recursively
    int dr[]={-1,1,0,0};
    int dc[]={0,0,-1,1};
    visited[r][c] = true;           // ← mark ourselves

    for (int i = 0; i < 4; i++) {
	    int nr = r + dr[i];
	    int nc = c + dc[i];
	    if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc] == '1'  && !visited[nr][nc]) 	// bounds + land + visited check, same code once
	    {
		    dfs(nr,nc,grid,visited,m,n);

	    }
    }
}
int numIslands(vector<vector<char>>& grid) {
	int m = grid.size();
	int n = grid[0].size();
	vector<vector<bool>> visited(m, vector<bool>(n, false));
	int count = 0;
	for(int row = 0;row< m; row++)
	{

		for(int col = 0;col< n; col++)
			if(grid[row][col] == '1' && !visited[row][col])
			{
				count++;
				//bfs(row,col,grid,visited,m,n);
				dfs(row,col,grid,visited,m,n);
			}
	}
	return count;
}

int main() {
	vector<vector<char>> grid = {
		{'1','1','0','1','0'},
		{'1','0','0','1','0'},
		{'0','0','1','0','0'},
		{'1','0','0','0','1'}
	};
	cout << numIslands(grid) << endl;
	return 0;
}
