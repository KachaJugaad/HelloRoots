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

TreeNode* searchBST(TreeNode* root, int val) {
    // null → return nullptr
    // val matches → return root
    // val < root->val → recurse left
    // else recurse right

if(!root) return NULL;
if(root->val == val) return root;
else if(root->val>val) return searchBST(root->left,val);
else return searchBST(root->right,val);
return NULL;
}

TreeNode* insertBST(TreeNode* root, int val) {
    // null → return new TreeNode(val)
    // val < root->val → root->left = insertBST(...)
    // else → root->right = insertBST(...)
    // return root

if(!root) return new TreeNode(val);
if(val<root->val) root->left=insertBST(root->left,val);
else root->right=insertBST(root->right,val);
return root;

}

int main() {
    // Build BST by inserting: 5, 3, 8, 1, 4, 10
    //         5
    //        / \
    //       3   8
    //      / \   \
    //     1   4   10
    TreeNode* root = nullptr;
    int values[] = {5, 3, 8, 1, 4, 10};
    for (int v : values) {
        root = insertBST(root, v);
    }

    // Search tests
    TreeNode* found = searchBST(root, 4);
    cout << (found ? found->val : -1) << endl;   // expect 4

    found = searchBST(root, 10);
    cout << (found ? found->val : -1) << endl;   // expect 10

    found = searchBST(root, 99);
    cout << (found ? found->val : -1) << endl;   // expect -1 (not found)

    found = searchBST(root, 5);
    cout << (found ? found->val : -1) << endl;   // expect 5 (root)

    return 0;
}
