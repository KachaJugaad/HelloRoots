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

int maxSum;

int gain(TreeNode* root) {
    // Base: null → return 0
    // leftGain  = max(0, gain(root->left))
    // rightGain = max(0, gain(root->right))
    // Update maxSum with root->val + leftGain + rightGain
    // Return root->val + max(leftGain, rightGain)



}

int maxPathSum(TreeNode* root) {
    maxSum = INT_MIN;
    gain(root);
    return maxSum;
}

int main() {
    // Tree 1:
    //     1
    //    / \
    //   2   3
    TreeNode* t1 = new TreeNode(1);
    t1->left = new TreeNode(2);
    t1->right = new TreeNode(3);
    cout << maxPathSum(t1) << endl;   // expect 6

    // Tree 2:
    //     -10
    //     / \
    //    9   20
    //        / \
    //       15  7
    TreeNode* t2 = new TreeNode(-10);
    t2->left = new TreeNode(9);
    t2->right = new TreeNode(20);
    t2->right->left = new TreeNode(15);
    t2->right->right = new TreeNode(7);
    cout << maxPathSum(t2) << endl;   // expect 42

    // Tree 3:
    //     -3
    TreeNode* t3 = new TreeNode(-3);
    cout << maxPathSum(t3) << endl;   // expect -3

    return 0;
}
