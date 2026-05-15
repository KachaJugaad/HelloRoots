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
	vector<vector<char>> grid = {
		{'1', '0', '1'},
		{'0', '1', '0'},
		{'1', '0', '1'}
	};



	vector<vector<bool>> visited(3, vector<bool>(3, false));
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(grid[i][j] =='1') 
				cout<<"visited" <<i<<":"<<j<<"="<< grid[i][j]<<endl;
		}
	}


	// TODO: Write a function that:
	// 1. Takes grid, visited, row i, col j
	// 2. Marks grid[i][j] as visited
	// 3. Prints the grid value
	// 4. Does NOT explore neighbors yet

	// Call it on grid[0][0]

	return 0;
}

