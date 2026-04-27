#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int maxDepth(TreeNode* root) {
	// Base case: if root is nullptr → return 0
	// Recurse: leftDepth = maxDepth(root->left)
	//          rightDepth = maxDepth(root->right)
	// Return 1 + max of the two
	// int leftD = 0;
	// int rightD = 0;
	if(!root)return 0;
//	leftD=maxDepth(root->left);
//	rightD=maxDepth(root->right);
//	return(1+max(leftD,rightD));
	return 1+max(maxDepth(root->left),maxDepth(root->right));
}

int main() {
    // Tree 1:
    //     3
    //    / \
    //   9   20
    //      /  \
    //     15   7
    TreeNode* t1 = new TreeNode(3);
    t1->left = new TreeNode(9);
    t1->right = new TreeNode(20);
    t1->right->left = new TreeNode(15);
    t1->right->right = new TreeNode(7);

    cout << maxDepth(t1) << endl;  // expect 3

    // Tree 2:
    //   1
    //  /
    // 2
    TreeNode* t2 = new TreeNode(1);
    t2->left = new TreeNode(2);

    cout << maxDepth(t2) << endl;  // expect 2

    // Tree 3: empty
    cout << maxDepth(nullptr) << endl;  // expect 0

    return 0;
}
