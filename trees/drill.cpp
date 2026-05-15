// =============================================
// Candidate: [your name]
// Date: 2026-04-28
// =============================================

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <deque>
#include <algorithm>
using namespace std;

// =============================================
// QUESTION 1
// =============================================
// Problem (restate in your own words):
//
//
// Clarifying questions asked:
// 1.
// 2.
//
// Brute force approach:                 O(    ) time, O(    ) space
// Optimized approach:                   O(    ) time, O(    ) space
// Data structure choice + reason:
//
// Edge cases to test:
// -
// -
// -


/* ---------- Q1 SOLUTION ---------- */
int countSuspiciousClients(vector<string>& clientIds, vector<int>& timestamps);
{
int suspician = 0; 
unordered_map<string,deque<int>> sus_table;
vector<string> result;

    for (int t = 0; t < (int)clientIds.size(); t++) {
        auto& d10  = sus_table[clientIds[timestamps[t]]];        // ★ auto& — reference, not copy!
        while (!d10.empty()  && d10.front()  <= timestamps[t] - 10)  d10.pop_front();
        if (d10.size() < 10) {
            d10.push_back(timestamps[t]); 
        } else {
            result.push_back(clientIds[t]);            // rejected = no push
        }
    }
    return (int)result.size();
}

}






/* ---------- Q1 DRIVER ---------- */
int main() {
    
    return 0;
}
