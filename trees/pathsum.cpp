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

bool hasPathSum(TreeNode* root, int targetSum) {
	// 1. If root is nullptr → return false
	// 2. If root is a leaf (both children null):
	//      return whether root->val == targetSum
	// 3. Otherwise recurse:
	//      hasPathSum(root->left, targetSum - root->val)
	//      OR hasPathSum(root->right, targetSum - root->val)

	if(!root) return false; 
	if(!(root->left) && !(root->right)) return (root->val == targetSum);
	return (hasPathSum(root->left, targetSum-root->val) ||	hasPathSum(root->right,targetSum-root->val));
}

int main() {
    // Tree 1:
    //         5
    //        / \
    //       4   8
    //      /   / \
    //    11  13   4
    //   / \        \
    //  7   2        1
    TreeNode* t1 = new TreeNode(5);
    t1->left = new TreeNode(4);
    t1->right = new TreeNode(8);
    t1->left->left = new TreeNode(11);
    t1->left->left->left = new TreeNode(7);
    t1->left->left->right = new TreeNode(2);
    t1->right->left = new TreeNode(13);
    t1->right->right = new TreeNode(4);
    t1->right->right->right = new TreeNode(1);

    cout << hasPathSum(t1, 22) << endl;  // expect 1
    cout << hasPathSum(t1, 100) << endl; // expect 0

    // Tree 2:
    //     1
    //    / \
    //   2   3
    TreeNode* t2 = new TreeNode(1);
    t2->left = new TreeNode(2);
    t2->right = new TreeNode(3);

    cout << hasPathSum(t2, 5) << endl;   // expect 0

    // Empty:
    cout << hasPathSum(nullptr, 0) << endl;  // expect 0

    return 0;
}
