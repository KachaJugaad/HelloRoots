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

void bfs(int sr, int sc, vector<vector<char>>& grid,
		vector<vector<bool>>& visited, int m, int n) {
	
	queue<pair<int,int>> q;
	q.push({sr,sc});
	visited[sr][sc] = true;


	int dr[]={-1,1,0,0};
	int dc[]={0,0,-1,1};

	while(!q.empty()){
		auto[r,c]=q.front();
		q.pop();
		for(int i=0;i<4;i++)
		{
			int nr=r+dr[i];int nc=c+dc[i];
			if(nr>=0&&nr<m && nc>=0&&nc<n && grid[nr][nc]=='1' && !visited[nr][nc])
			{
				visited[nr][nc]=true;
				q.push({nr,nc});
			}
		}
	}
}
int numIslands(vector<vector<char>>& grid){
	int m = grid.size();
	int n = grid[0].size();
	vector<vector<bool>> visited(m,vector<bool>(n,false));

	int count=0;
	for(int row=0;row<m;row++){
		for(int col=0;col<n;col++)
		{
			if(grid[row][col]=='1' && !visited[row][col])
			{
				count++;bfs(row,col,grid,visited,m,n);
			}
		}
	}
	return count;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // your code here
    vector<vector<char>> grid = {
	    {'1','1','0','1','0'},
	    {'1','0','0','1','0'},
	    {'0','0','1','0','0'},
	    {'1','0','0','0','1'}
};
	cout<<numIslands(grid)<<endl;
    return 0;
}

