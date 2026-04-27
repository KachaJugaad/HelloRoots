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

bool isMirror(TreeNode* a, TreeNode* b) {
	// If both null → true (both empty subtrees mirror each other)
	// If one null, other not → false
	// If values differ → false
	// Otherwise recurse:
	//   a->left mirrors b->right
	//   AND a->right mirrors b->left
	if(!a && !b) return true;
	if(!a || !b) return false;
	if (a->val != b->val) return false;       // ← THIS LINE

	return isMirror(a->left,b->right) && isMirror(a->right, b->left);


}

bool isSymmetric(TreeNode* root) {
	// Empty tree is symmetric → return true
	// Otherwise return isMirror(root->left, root->right)
	if(!root)return true;
	return isMirror(root->left,root->right);


}

int main() {
    // Symmetric:
    //         1
    //        / \
    //       2   2
    //      / \ / \
    //     3  4 4  3
    TreeNode* t1 = new TreeNode(1);
    t1->left = new TreeNode(2);
    t1->right = new TreeNode(2);
    t1->left->left = new TreeNode(3);
    t1->left->right = new TreeNode(4);
    t1->right->left = new TreeNode(4);
    t1->right->right = new TreeNode(3);

    cout << isSymmetric(t1) << endl;   // expect 1

    // Not symmetric:
    //         1
    //        / \
    //       2   2
    //        \   \
    //         3   3
    TreeNode* t2 = new TreeNode(1);
    t2->left = new TreeNode(2);
    t2->right = new TreeNode(2);
    t2->left->right = new TreeNode(3);
    t2->right->right = new TreeNode(3);

    cout << isSymmetric(t2) << endl;   // expect 0

    // Empty tree:
    cout << isSymmetric(nullptr) << endl;  // expect 1
// Asymmetric values:
//     1
//    / \
//   2   3
TreeNode* t4 = new TreeNode(1);
t4->left = new TreeNode(2);
t4->right = new TreeNode(3);

cout << isSymmetric(t4) << endl;   // expect 0
    return 0;
}
