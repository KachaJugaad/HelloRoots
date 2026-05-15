#include <vector>
#include <iostream>
#include <climits>
using namespace std;

int minCoins(int amount, vector<int>& coins) {
    // Base case: amount is 0
    if(amount == 0) return 0;
    
    // If amount is negative, impossible
    if(amount < 0) return INT_MAX;
    
    int minCount = INT_MAX;
    
    // Try each coin
    for(int coin : coins) {
        int result = minCoins(amount - coin, coins);
        cout<<"coin:  "<<coin<<" : "<<result<<endl;
        if(result != INT_MAX) {
            minCount = min(minCount, 1 + result);
        }
    }
    
    return minCount;
}

int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    
    int result = minCoins(amount, coins);
    cout << "Min coins for " << amount << ": " << result << endl;
    
    return 0;
}
