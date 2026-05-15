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

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// =========================================================
// YOUR CODE GOES HERE
// =========================================================
int findLevel(TreeNode* root, int target) {

if(!root) return -1;

queue<TreeNode*> q;
q.push(root);
cout<<"r: "<<root->val<<endl;
int level = 0; 

while(!q.empty())
{
	int sz = q.size();
	for(int i = 0;i<sz;i++)
	{
		TreeNode* tmp = q.front();
		q.pop();

		if(tmp->val == target) return level; 

		if(tmp->left) {cout<< "L: "<<tmp->val<<endl;q.push(tmp->left);}
		if(tmp->right){cout<<"R: " << tmp->val<<endl;q.push(tmp->right);}
	}
	level++;
}
// TODO 1: handle empty tree

// TODO 2: set up BFS queue and level counter

// TODO 3: standard BFS loop
//   - snapshot current level size
//   - process exactly that many nodes
//   - if value matches target, return current level
//   - else push left and right children
//   - after the inner loop, increment level

// TODO 4: target not found
return -1;
}
// =========================================================

// ---------- helper to build the example tree ----------
//          10
//         /  \
//        20   30
//       / \    \
//      40  50   60
TreeNode* buildExampleTree() {
	TreeNode* root = new TreeNode(10);
	root->left  = new TreeNode(20);
	root->right = new TreeNode(30);
	root->left->left  = new TreeNode(40);
	root->left->right = new TreeNode(50);
	root->right->right = new TreeNode(60);
	return root;
}

// ---------- driver ----------
int main() {
	TreeNode* root = buildExampleTree();

	vector<int> tests = {10, 20, 50, 60, 40, 99};
	vector<int> expected = {0, 1, 2, 2, 2, -1};

	for (int i = 0; i < (int)tests.size(); i++) {
		int got = findLevel(root, tests[i]);
		cout << "target = " << tests[i]
			<< "  expected = " << expected[i]
			<< "  got = " << got
			<< (got == expected[i] ? "  PASS" : "  FAIL")
			<< endl;
	}

	// edge case: empty tree
	cout << "empty tree, target = 1  expected = -1  got = "
		<< findLevel(nullptr, 1) << endl;

	return 0;
}
