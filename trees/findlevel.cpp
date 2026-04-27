#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int findLevel(TreeNode* root, int target, int depth = 0) {
    // Base case: nullptr → return -1 (not found)
    // If root->val == target → return depth
    // Recurse left with depth+1 → if leftResult != -1, return it
    // Recurse right with depth+1 → return rightResult
if(!root) return -1;
if(root->val == target) return depth;
int leftResult = findLevel(root->left, target, depth + 1);
if (leftResult != -1) return leftResult;          // ← check after left

return findLevel(root->right, target, depth + 1); // ← no explicit check
}

int main() {
    //         1
    //        / \
    //       2   3
    //      / \   \
    //     4   5   6
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    cout << findLevel(root, 5) << endl;   // expect 2
    cout << findLevel(root, 1) << endl;   // expect 0
    cout << findLevel(root, 6) << endl;   // expect 2
    cout << findLevel(root, 99) << endl;  // expect -1
    cout << findLevel(nullptr, 5) << endl; // expect -1

    return 0;
}
