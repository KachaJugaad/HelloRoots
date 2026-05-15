#include <iostream>
#include <queue>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// =========================================================
// FUNCTION 1: Validate BST (recursive DFS with inherited range)
// =========================================================
bool validateBST(TreeNode* node, long minVal, long maxVal) {
    // Step 1: empty subtree is valid by definition
if(!tree) return false;
if(!tree->left&&!tree->right) return true;
     

    // Step 2: check current node fits strictly inside (minVal, maxVal)
    

    // Step 3: recurse left with tightened max = node->val
    //         recurse right with tightened min = node->val
    //         BOTH must be valid for tree to be valid
    

    return true;  // replace with your actual return
}

// Convenience wrapper so the caller doesn't have to pass LONG_MIN/LONG_MAX
bool validateBST(TreeNode* root) {
    return validateBST(root, LONG_MIN, LONG_MAX);
}

// =========================================================
// FUNCTION 2: Find level using BFS-by-level (you've drilled this!)
// =========================================================
int findLevel(TreeNode* root, int target) {
    // your code here — same template you wrote earlier tonight
    
    return -1;
}

// =========================================================
// MAIN ORCHESTRATOR
// =========================================================
int validateAndFindLevel(TreeNode* root, int target) {
    if (!validateBST(root)) return -2;
    return findLevel(root, target);
}

// =========================================================
// TEST DRIVER
// =========================================================
TreeNode* buildValidBST() {
    //          10
    //         /  \
    //        5    15
    //       / \   / \
    //      2   7 12  20
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(7);
    root->right->left = new TreeNode(12);
    root->right->right = new TreeNode(20);
    return root;
}

TreeNode* buildInvalidBST() {
    //          10
    //         /  \
    //        5    15
    //       / \
    //      2   12   ← 12 in left subtree of 10 → INVALID
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(12);
    return root;
}

int main() {
    TreeNode* valid   = buildValidBST();
    TreeNode* invalid = buildInvalidBST();

    cout << "valid BST, target=7    expected 2  got " << validateAndFindLevel(valid, 7)   << endl;
    cout << "valid BST, target=10   expected 0  got " << validateAndFindLevel(valid, 10)  << endl;
    cout << "valid BST, target=20   expected 2  got " << validateAndFindLevel(valid, 20)  << endl;
    cout << "valid BST, target=99   expected -1 got " << validateAndFindLevel(valid, 99)  << endl;
    cout << "invalid BST            expected -2 got " << validateAndFindLevel(invalid, 5) << endl;
    cout << "empty tree, target=1   expected -1 got " << validateAndFindLevel(nullptr, 1) << endl;
    return 0;
}
