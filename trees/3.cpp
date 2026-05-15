#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int countLevels(TreeNode* root) {
}

TreeNode* buildExampleTree() {
    TreeNode* root = new TreeNode(10);
    root->left  = new TreeNode(20);
    root->right = new TreeNode(30);
    root->left->left  = new TreeNode(40);
    root->left->right = new TreeNode(50);
    root->right->right = new TreeNode(60);
    return root;
}

int main() {
    cout << "Tree of 6 nodes  expected 3  got " << countLevels(buildExampleTree()) << endl;

    TreeNode* single = new TreeNode(1);

    cout << "Single node      expected 1  got " << countLevels(single) << endl;

    cout << "Empty tree       expected 0  got " << countLevels(nullptr) << endl;

    // skewed tree: 1 -> 2 -> 3 -> 4 (all left children)
    TreeNode* skew = new TreeNode(1);
    skew->left = new TreeNode(2);
    skew->left->left = new TreeNode(3);
    skew->left->left->left = new TreeNode(4);
    cout << "Skewed 4 deep    expected 4  got " << countLevels(skew) << endl;

    return 0;
}
