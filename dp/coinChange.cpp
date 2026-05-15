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

int coinChange(vector<int>& coins, int amount) {
	// dp[i] = minimum coins to make amount i
	vector<int> dp(amount + 1, INT_MAX);
	dp[0] = 0;  // Base case: 0 amount needs 0 coins

	// Build table from 1 to amount
	for (int i = 1; i <= amount; i++) {
		// Try each coin
		//cout<<"amount: "<<i<<endl;
		for (int coin : coins) {
			if (coin <= i && dp[i - coin] != INT_MAX) {
				// Can use this coin
				dp[i] = min(dp[i], 1 + dp[i - coin]);
				//cout<<"coin "<<coin<<"dp: "<<dp[i]<<endl;
			}
		}
	}
	for(int d:dp)cout<<d<<endl;
	return dp[amount] == INT_MAX ? -1 : dp[amount];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> coins = {1,2,5};
	int amount = 11; 
	cout << coinChange(coins, amount)<<endl;

	// your code here

	return 0;
}

