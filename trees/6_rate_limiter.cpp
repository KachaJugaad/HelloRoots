#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <unordered_map>
using namespace std;

const string OK     = "{status: 200, message: OK}";
const string REJECT = "{status: 429, message: Too many requests}";

const int WIN5_DUR  = 5;
const int WIN5_LIM  = 2;
const int WIN30_DUR = 30;
const int WIN30_LIM = 5;

// =========================================================
// YOUR CODE
// =========================================================
// =========================================================

vector<string> rateLimit(vector<string>& requests) {
    vector<string> result;
    unordered_map<string, deque<int>> w5;
    unordered_map<string, deque<int>> w30;

    for (int t = 0; t < (int)requests.size(); t++) {
        const string& domain = requests[t];
        auto& d5  = w5[domain];        // ← reference, NOT copy. Edits the real deque.
        auto& d30 = w30[domain];

        // Step 2a: prune d5 — while front exists AND front <= t - 5, pop_front

	while (!d5.empty()  && d5.front() <= t - 5)  d5.pop_front();
	while (!d30.empty() && d30.front() <= t - 30) d30.pop_front();
        // Step 2b: prune d30 — while front exists AND front <= t - 30, pop_front
        

        // Step 3-5: check both limits, decide, push or reject
        if (d5.size() < 2 && d30.size() < 5) {
            // allowed: push t to both, append OK
		d5.push_back(t);d30.push_back(t);
	        result.push_back(OK);
        } else {
	        result.push_back(REJECT);
            // rejected: just append REJECT
        }
    }

    return result;
}
void printResults(const vector<string>& results) {
    for (size_t i = 0; i < results.size(); i++) {
        cout << "  t=" << i << ": " << results[i] << endl;
    }
}

int main() {
    {
        cout << "Test 1: example from spec\n";
        vector<string> req = {"www.xyz.com","www.abc.com","www.xyz.com",
                              "www.pqr.com","www.xyz.com","www.abc.com","www.xyz.com"};
        vector<string> expected = {OK, OK, OK, OK, REJECT, OK, OK};
        vector<string> got = rateLimit(req);
        printResults(got);
        cout << (got == expected ? "  PASS\n" : "  FAIL\n") << endl;
    }
    {
        cout << "Test 2: single domain hits 5s limit fast\n";
        // xyz at t=0,1,2 — 3rd one rejected
        vector<string> req = {"xyz","xyz","xyz"};
        vector<string> expected = {OK, OK, REJECT};
        vector<string> got = rateLimit(req);
        printResults(got);
        cout << (got == expected ? "  PASS\n" : "  FAIL\n") << endl;
    }
    {
        cout << "Test 3: 30s limit\n";
        // 6 requests of same domain spaced widely (every 5s) — 6th hits the 30s/5 limit
        // t = 0,5,10,15,20,25 — at t=25, window [-4..25] contains all 6 → REJECT
        vector<string> req(26, "");
        req[0]="a"; req[5]="a"; req[10]="a"; req[15]="a"; req[20]="a"; req[25]="a";
        // fill the rest with a different domain so each second has a request
        for (int i = 0; i < 26; i++) if (req[i].empty()) req[i] = "filler";
        vector<string> got = rateLimit(req);
        // check the request at t=25
        cout << "  t=25 (a's 6th in 30s) got " << got[25]
             << "  expected " << REJECT
             << (got[25] == REJECT ? "  PASS" : "  FAIL") << endl;
    }
    {
        cout << "Test 4: empty input\n";
        vector<string> req = {};
        vector<string> got = rateLimit(req);
        cout << (got.empty() ? "  PASS" : "  FAIL") << endl;
    }
    {
        cout << "Test 5: rejected requests don't block future ones\n";
        // xyz at 0,1,2 — third rejected. At t=5, the rejected one shouldn't count.
        // window at t=5 is [1..5]: only timestamps 1, then maybe 5
        vector<string> req = {"xyz","xyz","xyz","xyz","xyz","xyz"};
        // t=0 OK, t=1 OK, t=2 REJ, t=3 REJ (window [-1..3] has 0,1), 
        // t=4 REJ (window [0..4] has 0,1), t=5 OK (window [1..5] has 1, room for one more)
        vector<string> got = rateLimit(req);
        cout << "  t=5 expected OK got " << got[5]
             << (got[5] == OK ? "  PASS" : "  FAIL") << endl;
    }
    return 0;
}
